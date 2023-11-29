package Package1;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketTimeoutException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Arrays;

import packinter.Iinter;

// ORDRE D'EXECUTION: Servercentral(run on server)->server1->server2->server3->server4->server5(peu importe pour les servers)->inter->Cl2->Cl3->Cl4->Cl5->Cl6->Cl1

public class Cl1 extends Client {
    public static int[] values = {1122, 2233, 3344, 4455, 5566, 6611};

    public static void main(String[] args) throws Exception {
        try {
        	//la chaine de reference, elle contient les services de ce client
            String[] clientReferenceChain = {"Service1", "Service0", "Service4", "Service12", "Service11", "Service10",
                    "Service9", "Service8", "Service7", "Service6", "Service5", "Service4", "Service3", "Service2",
                    "Service1", "Service0", "FIN"};
            //Utiliser RMI avec inter
            Registry r = LocateRegistry.getRegistry("localhost", 1099);
            Iinter i = (Iinter) r.lookup("refinter");

            //A noter que ceci est pour le premier service seulement, apres le traitement se fera a la ligne 62 (boucle)
            
            System.out.println("============================================================");
            System.out.println("============================================================");
            System.out.println("Client1 envoie nom du service a inter ");
            
            String Sx = i.Sending(clientReferenceChain[0]);
         // inter est entrain de traiter la demande
            //on doit diviser la chaine qu'on va recevoir, car tout est concatené avec un espace
            String[] parts = Sx.split(" ", 3);
            String numService = parts[0];// contient le numero du service
            String nomService = parts[1];// contient le nom du service
            String descService = parts[2];// contient la description de service
          //Afficher le resultat dans client
            System.out.println(
                    "numero service = " + numService + " / nom service = " + nomService + " / description service = "
                            + descService);
            //UDP pour communiquer avec le prochain client
            DatagramSocket socketf = new DatagramSocket();
            String message = "Token";
            InetAddress address = InetAddress.getLocalHost();
            //checkstatus permet de verifier quels clients sont offline, donc ca nous permet d'eviter d'envoyer un message
            // a un client offline et passe directement a un client online 
            int[] p = SansPort1(values, 6611);
            values = checkstatus(p);
            
            // avoir la position du port de ce client dans le tableau values
            // puis chercher le port suivant dans le tableau pour lui envoyer le message
            // exemple values= [5511,2233] on va envoyer a 2233 (qui est client 3)
            // modulo pour parcourir le values circulairement
            
            int y1 = findPosition(values, 6611);
            int mod = (y1 + 1) % values.length;
            int port1 = values[mod];
            char clientmod = Integer.toString(port1).charAt(2);

            DatagramPacket packetf = new DatagramPacket(message.getBytes(), message.length(), address, port1);
            //envoi du packet
            socketf.send(packetf);
            //token envoye au prochain client
            System.out.println("Message envoyé depuis Client 01 au Client 0" + clientmod);

            socketf.close();
            
            // cette boucle parcours tout le services, a chaque fois qu'un service est terminé, il envoie le token, 
            // puis repasse au debut de la boucle ou il va devoir attendre un datagramme token
            
            for (int iz = 1; iz < clientReferenceChain.length; iz++) {
                if (clientReferenceChain[iz].equals("FIN")) {
                    System.out.println("Fin client1");
                } else {
                    System.out.println("============================================================");
                    System.out.println("============================================================");
                    
                    //preparation a la reception d'un datagramme
                    
                    DatagramSocket socket = new DatagramSocket(6611);
                    //mettre un timer sur la socket, si on recoit pas pendant 40secondes elle leve une exception(traitement)
                    socket.setSoTimeout(40000);
                    byte[] buffer = new byte[1024];
                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

                    boolean received2 = false;
                    int x2 = 0;
                    // attendre un datagramme
                    while (!received2) {
                        try {
                            socket.receive(packet);// on essaie de recevoir
                            String receivedtest = new String(packet.getData(), 0, packet.getLength());
                            //si le message recu est un message reset, on doit reset le timer, 
                            // sortir de la boucle et relancer pour avoir un nouvelle attente
                            if (receivedtest.equals("Reset")) {
                                System.out.println("Reset du timer du client 2");
                                received2 = true;
                                x2 = 1;
                            } 
                            // si msg recu est deleteport, on doit juste mettre ajour notre tableau values
                            // pour ne plus envoyer a ce port qui est termine
                            else if (receivedtest.contains("Deleteport")) {
                                String[] partx = receivedtest.split("Deleteport");
                                if (partx.length > 1) {// suppression du port
                                    int[] updatedValues = Arrays.stream(values)
                                            .filter(port -> port != Integer.parseInt(partx[1]))
                                            .toArray();
                                    values = updatedValues;// mise a jour de values
                                    System.out.println("Les Ports restants sont : ");// afficher les clients restants
                                    for (int value : values) {
                                   	 char third = Integer.toString(value).charAt(2);
                                        System.out.println("Client 0"+third+", son port :"+value);
                                   }
                                    received2 = true;
                                    x2 = 1;
                                }
                            } 
                            //cas ou le message recu est un token recu depuis la rellocatetoken() apres qu un timer soit depassé
                            else {
                                if (receivedtest.equals("NVToken")) {
                                    System.out.println("Nouveau Token Recu");
                                } 
                                //sinon cas normal, c'est un token recu depuis le client precedent
                                else {
                                    System.out.println("Token normal Recu");
                                }
                                received2 = true;
                            }
                        } catch (SocketTimeoutException e) {
                        	//si la socket depasse 40 sec sans reception, on doit generer un nouveau token et 
                        	// reset les timers de tous les clients
                            System.out.println("Timer ran out, reallocation random du token");
                            RellocateToken(values, address);
                            x2 = 1;
                        }
                    }
                    //on rentre dans cette boucle dans le cas ou le dernier datagramme recu est soir un RESET ou bien DELETEPORT
                    //car on doit toujours attendre un token normal
                    while (x2 == 1) {
                        socket.setSoTimeout(40000);
                        received2 = false;
                        //meme logique, sauf que pour sortir de cette boucle, on doit recevoir un token normal, sinon on reste ici.
                        while (!received2) {
                            try {
                                socket.receive(packet);
                                String receivedtest = new String(packet.getData(), 0, packet.getLength());
                                //meme logique
                                if (receivedtest.equals("Reset")) {
                                    System.out.println("Reset du timer du client 01");
                                    received2 = true;
                                } else if (receivedtest.contains("Deleteport")) {
                                    String[] partx = receivedtest.split("Deleteport");
                                    if (partx.length > 1) {
                                        int[] updatedValues = Arrays.stream(values)
                                                .filter(port -> port != Integer.parseInt(partx[1]))
                                                .toArray();
                                        values = updatedValues;
                                        System.out.println("Les Ports restants sont : ");
                                        for (int value : values) {
                                       	 char third = Integer.toString(value).charAt(2);
                                            System.out.println("Client 0"+third+", son port :"+value);
                                       }
                                        received2 = true;
                                        x2 = 1;
                                    }
                                } else {
                                    if (receivedtest.equals("NVToken")) {
                                        System.out.println("Nouveau Token Recu");
                                    } else {
                                        System.out.println("Token normal Recu");
                                    }
                                    x2 = 0;
                                    // token normal recu, client sort de la boucle while, Client peut faire sa demande a inter
                                    received2 = true;
                                }
                            } catch (SocketTimeoutException e) {
                                System.out.println("Timer ran out, reallocation random du token");
                                message = "Token";
                                RellocateToken(values, address);
                            }
                        }
                    }
                    //Client a le token, faire demande
                    if (x2 == 0) {
                        System.out.println("Client 01 envoie nom du service a inter ");
                        Sx = i.Sending(clientReferenceChain[iz]);
                        parts = Sx.split(" ", 3);
                        numService = parts[0];
                        nomService = parts[1];
                        descService = parts[2];
                        System.out.println(
                                "numero service = " + numService + " / nom service = " + nomService
                                        + " / description service = " + descService);

                        String received = new String(packet.getData(), 0, packet.getLength());
                        System.out.println("Message reçu dans Client 01 : " + received);
                        Thread.sleep(2000);// attente 2sec pour chaque demande, ca permet de voir la progression

                        //envoyer par udp au prochain client
                        DatagramSocket socket2 = new DatagramSocket();

                        message = "Token";
                        address = packet.getAddress();
                        //si ce client se termine, on doit supprimer son port des autres clients
                        if (iz == 15) {
                            Endofclient(values, address, 6611);
                            System.out.println("********Client termine, on enleve son port des autres client*********");
                        }

                        p = values;
                        values = checkstatus(p);
                        y1 = findPosition(values, 6611);
                        mod = (y1 + 1) % values.length;
                        int port = values[mod];
                        clientmod = Integer.toString(port).charAt(2);
                        DatagramPacket packet2 = new DatagramPacket(message.getBytes(), message.length(), address, port);
                        socket2.send(packet2);//envoi du token au prochain client

                        System.out.println("Message envoyé depuis Client 01 au Client 0" + clientmod);

                        socket2.close();
                        socket.close();
 	                   
 	               
 	                       }
 	        	 	 }
 	 			//fin parcours de la chaine de reference	 
 	 			}
        	 
        }
        catch(Exception e) 
    	{System.out.println("Exception : "+e.toString());}
	
}

    //cette methode permet de ne pas supprimer le port de ce client quand il appelle checkstatus
    // ca n'arrive qu'ici car on l'appelle au debut pour lancer la 1ere demande de tous
	 public static int[] SansPort1(int [] values, int portToRemove) {
	        int[] updatedValues = Arrays.stream(values)
	                                    .filter(port -> port != portToRemove)
	                                    .toArray();
	        return updatedValues;
	    }	
}
