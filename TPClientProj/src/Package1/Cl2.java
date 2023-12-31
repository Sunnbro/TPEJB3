package Package1;

import java.rmi.registry.Registry;
import java.util.Arrays;
import packinter.Iinter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketTimeoutException;
import java.rmi.registry.LocateRegistry;
//ORDRE D'EXECUTION: Servercentral(run on server)->server1->server2->server3->server4->server5(peu importe pour les servers)->inter->Cl2->Cl3->Cl4->Cl5->Cl6->Cl1

//SI ON VEUT TESTER LE TIMER, ENLEVER LES COMMENTAIRES a la ligne 178, 

public class Cl2 extends Client {
    public static int[] values = {1122, 2233, 3344, 4455, 5566, 6611};

    public static void main(String[] args) throws Exception {
        try {
        	//la chaine de reference, elle contient les services de ce client
            String[] clientReferenceChain = {"Service2", "Service0", "Service13", "Service12", "Service11", "Service10", "Service9", "Service8", "Service7", "Service6", "Service5", "Service4", "Service3", "Service2", "Service1", "Service0", "FIN"};
            InetAddress address = null;
          //Utiliser RMI avec inter
            Registry r = LocateRegistry.getRegistry("localhost", 1099);
            Iinter i = (Iinter) r.lookup("refinter");
            int x2 = 0;
            int iter = 0;
            // dans client 2..6 on a pas la premiere partie comme le client 1, 
            // il attend directement un datagramme
            
            // cette boucle parcours tout le services, a chaque fois qu'un service est terminé, il envoie le token, 
            // puis repasse au debut de la boucle ou il va devoir attendre un datagramme token
           
            for (String reference : clientReferenceChain) {
                iter++;
                if (reference.equals("FIN")) {
                    System.out.println("Fin client2");
                    iter++;
                } else {
                    System.out.println("============================================================");
                    System.out.println("============================================================");
                    //preparation a la reception d'un datagramme

                    DatagramSocket socket = new DatagramSocket(1122); // Même port que P1
                   //mettre un timer sur la socket, si on recoit pas pendant 40secondes elle leve une exception(traitement)
                    socket.setSoTimeout(40000);
                    byte[] buffer = new byte[1024];

                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

                    // attendre token
                    boolean received2 = false;
                    while (!received2) {
                        try {
                            socket.receive(packet);// on essaie de recevoir
                            String receivedtest = new String(packet.getData(), 0, packet.getLength());
                            //si le message recu est un message reset, on doit reset le timer, 
                            // sortir de la boucle et relancer pour avoir un nouvelle attente
                            if (receivedtest.equals("Reset")) {
                                System.out.println("Reset du timer du client 2");
                                received2 = true; // Marque le datagramme comme reçu
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
                                // Attente de la réception d'un datagramme token
                                if (receivedtest.equals("NVToken")) {
                                    System.out.println("Nouveau Token Recu");
                                } 
                                //sinon cas normal, c'est un token recu depuis le client precedent
                                else {
                                    System.out.println("Token normal Recu");
                                }

                                received2 = true; // Marque le datagramme comme reçu
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
                        while (!received2) {
                            try {
                                socket.receive(packet);
                                String receivedtest = new String(packet.getData(), 0, packet.getLength());
                                if (receivedtest.equals("Reset")) {
                                    System.out.println("Reset du timer du client 02");
                                    received2 = true; // Marque le datagramme comme reçu
                                } else if (receivedtest.contains("Deleteport")) {
                                    String[] partx = receivedtest.split("Deleteport");
                                    if (partx.length > 1) {
                                        int[] updatedValues = Arrays.stream(values)
                                                .filter(port -> port != Integer.parseInt(partx[1]))
                                                .toArray();
                                        values = updatedValues;
                                        System.out.println("Les Ports restants sont : ");
                                        for (int value : values) {
                                            System.out.println(value);
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
                                    received2 = true; // Marque le datagramme comme reçu
                                }
                            } catch (SocketTimeoutException e) {
                                System.out.println("Timer ran out, reallocation random du token");
                                RellocateToken(values, address);
                            }
                        }
                    }
                  //Client a le token, faire demande
                    if (x2 == 0) {
                        System.out.println("Client 02 envoie nom du service a inter ");
                        String Sx = i.Sending(reference);

                        String[] parts = Sx.split(" ", 3);
                        String numService = parts[0];
                        String nomService = parts[1];
                        String descService = parts[2];
                        System.out.println("numero service = " + numService + " / nom service = " + nomService + " / description service = " + descService);

                        String received = new String(packet.getData(), 0, packet.getLength());
                        System.out.println("Message reçu dans Client 02 : " + received);
                        Thread.sleep(2000);

                        DatagramSocket socket2 = new DatagramSocket();
                        String message = "Token";
                        address = packet.getAddress(); // Utiliser l'adresse d'origine
                        if (iter == 16) {
                            // appel fonction pour supprimer le port 5511 de tous les autres clients
                            Endofclient(values, address, 1122);
                            System.out.println("********Client termine, on enleve son port des autres client*********");
                        }

                        int[] p = values;
                        values = checkstatus(p);
                        int y1 = findPosition(values, 1122);
                        int mod = (y1 + 1) % values.length;
                        int port = values[mod];
                        char clientmod = Integer.toString(port).charAt(2);
                        DatagramPacket packet2 = new DatagramPacket(message.getBytes(), message.length(), address, port);
                        
                        //SI ON VEUT TESTER LE TIMER, ENLEVER LES COMMENTAIRES SUIVANTS, 
                        //si le service en cours est le 12eme, on envoie pas, ca cause un depassement du timer
                        
                        //if (!nomService.equals("Service12")) {
                            socket2.send(packet2); // Envoi à l'adresse d'origine
                        //}
                            

                        System.out.println("Message envoyé depuis Client 02 au Client 0" + clientmod);

                        socket2.close();
                        socket.close();
                    }
                }
            }


        } catch (Exception e) {
            System.out.println("Exception : " + e.toString());
        }

    }

}
