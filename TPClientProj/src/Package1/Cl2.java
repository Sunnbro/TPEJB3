package Package1;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.Properties;
import java.util.Random;

import javax.naming.InitialContext;

import packinter.Iinter;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketTimeoutException;
import java.rmi.registry.LocateRegistry;
@SuppressWarnings("unused")
public class Cl2 {
	public static int[] values = {1587, 6958, 5719 ,2541};
	public static void main(String[] args) throws Exception{
        try { Cl2 client2 = new Cl2();
        	
        	 String[] clientReferenceChain = {"Service2","Service0","Service13","Service12","Service11","Service10","Service9","Service8","Service7","Service6","Service5","Service4","Service3","Service2","Service1","Service0","FIN"};
  //, "S10", "S1", "S2", "S4", "S3", "S0", "S6", "S12", "S11", "S8", "S5", "S2", "S1", "S0", "S5", "S1", "S7", "S9", "S2.FIN"};

        	 Registry r = LocateRegistry.getRegistry("localhost",1099);
        	 Iinter i = (Iinter) r.lookup("refinter");
        	 int x=0;
        	 //System.out.println("voici le resultat: x= "+ x);
        	 for (String reference : clientReferenceChain) {
        	 	 if(reference.equals("FIN")){System.out.println("Fin client2");}
        	 	 else {
        //attendre que Client1 donne token
        	 		 
                	 DatagramSocket socket = new DatagramSocket(9876); // Même port que P1
                	 socket.setSoTimeout(30000);
                	 byte[] buffer = new byte[1024];

                     DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                    	 
                	 //reception token
                	 boolean received2 = false;
                     while (!received2) {
                         try {socket.receive(packet); 
                        // String recumsg = new String(packet.getData(), 0, packet.getLength());
                         
                        	//if(recumsg.equals("Reset")){
                        		//System.out.println("Reset du timer du client 2") ;
                        		//socket.setSoTimeout(30000);}
                        	//else{
                        			// Attente de la réception d'un datagramme
                        			System.out.println("Token Recu depuis Client1");
                        			received2 = true; // Marque le datagramme comme reçu
                        // }
                         } catch (SocketTimeoutException e) {
                        	 System.out.println("Timer ran out, reallocation du random du token");
                        	 int nouvPort = reallocateToken();
                        	 String message = "Token";
                        	// InetAddress address = packet.getAddress(); // Utiliser l'adresse d'origine
                             
                        	// DatagramSocket socket2 = new DatagramSocket();
                			 //DatagramPacket packet2 = new DatagramPacket(message.getBytes(), message.length(), address, nouvPort);
                			
                			// socket2.send(packet2); // Envoi du token à l'adresse d'origine
                             
                			 //il faut reset les timers des autres clients
                			
                			 //client2.Resettimers(5719); 
                			// client2.Resettimers(6958);
                			 //client2.Resettimers(address,1587);
                			 //client2.Resettimers(address,2541);
                			 }
                         
                         }
                     
                     
                     
               
        	 		 
        	 		 
        	 		 
        	 		 System.out.println("Client2 envoie nom du service a inter ");
        	 		 String Sx = i.Sending(reference);
        	 		 
        	//System.out.println("debug only +:"+Sx);
        	 		 
        	 String[] parts = Sx.split(" ", 3);
        	 String numService = parts[0];
        	 String nomService = parts[1];
        	 String descService = parts[2];
        	 System.out.println("numero service = " + numService + " / nom service = " + nomService + " / description service = " + descService);
        	 

             String received = new String(packet.getData(), 0, packet.getLength());
             System.out.println("Message reçu dans Client 2 : " + received);
        	 Thread.sleep(3000);
            
        	 // passer le token au prochain client
             DatagramSocket socket2 = new DatagramSocket();
             String message = "Token";
             InetAddress address = packet.getAddress(); // Utiliser l'adresse d'origine
             int port = 1587; // Utiliser le port d'origine
             
             
             DatagramPacket packet2 = new DatagramPacket(message.getBytes(), message.length(), address, port);
             socket2.send(packet2); // Envoi à l'adresse d'origine
             System.out.println("Message envoyé depuis Client 2 au Client 3");

             socket2.close();
             socket.close();
        	 	 }}
        	 
        	 
        }
        catch(Exception e) 
    	{System.out.println("Exception : "+e.toString());}
	
}
	public void Resettimers(InetAddress address,int port) {
		//EntityManagerFactory emf = Persistence.createEntityManagerFactory("TPEJB3");

		 RellocateThread RThread = new RellocateThread(address,port);//,entityManager);
	        RThread.start();}
	




	public static int reallocateToken() {
		  Random random = new Random();
	        

	        // Génération d'un indice aléatoire pour sélectionner l'un des cinq entiers
	        int randomIndex = random.nextInt(values.length);

	        // Récupération de l'entier sélectionné aléatoirement
	        int selectedInt = values[randomIndex];

	        
	        switch (selectedInt) {
	        		
			    case 1587:		    
			    	System.out.println("Nouveau token crée et envoyé au Client 03.");
			    	break;
			    	
			    case 6958:
			    	System.out.println("Nouveau token crée et envoyé au Client 04.");
			    	break;
			    	
			    case 5719:		    
			    	System.out.println("Nouveau token crée et envoyé au Client 05.");
			    	break;
			    	
			    case 2541:
			    	System.out.println("Nouveau token crée et envoyé au Client 01.");
			    	break;
	        // Affichage de l'entier sélectionné
	        }
	        return selectedInt;
		  	
	        
	}
}