package Package1;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.Arrays;
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
public class Cl5 extends Client{
	public static int[] values = {1122, 2233, 3344, 4455, 5511};
	public static void main(String[] args) throws Exception{
        try { Cl5 client5 = new Cl5();
        	
        	 String[] clientReferenceChain = {"Service2","Service0","Service13","Service12","Service11","Service10","Service9","Service8","Service7","Service6","Service5","Service4","Service3","Service2","Service1","Service0","FIN"};
  //, "S10", "S1", "S2", "S4", "S3", "S0", "S6", "S12", "S11", "S8", "S5", "S2", "S1", "S0", "S5", "S1", "S7", "S9", "S2.FIN"};
        	 InetAddress address = null;
         	
        	 Registry r = LocateRegistry.getRegistry("localhost",1099);
        	 Iinter i = (Iinter) r.lookup("refinter");
        	 int x=0;
        	 int x2=0;
        	 int iter=0;
        	 //System.out.println("voici le resultat: x= "+ x);
        	 //outerloop:
        	 for (String reference : clientReferenceChain) {
        		 iter++;
        		 if(reference.equals("FIN")){System.out.println("Fin client5");
					}
        	 	 else {
        	 		System.out.println("============================================================");
        	 		System.out.println("============================================================");
        //attendre que Client1 donne token
        	 		 
                	 DatagramSocket socket = new DatagramSocket(4455); // Même port que P1
                	 socket.setSoTimeout(40000);
                	 byte[] buffer = new byte[1024];
                	 
                     DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                     
                     
                   //reception token
                	 boolean received2 = false;
                     while (!received2) {
                         try {socket.receive(packet); 
                        // String recumsg = new String(packet.getData(), 0, packet.getLength());
                         String receivedtest = new String(packet.getData(), 0, packet.getLength());
                        	if(receivedtest.equals("Reset")){
                        		System.out.println("Reset du timer du client 5");
                        		received2 = true; // Marque le datagramme comme reçu
                                x2=1;
                        	}
                        	else if(receivedtest.contains("Deleteport")) {
                        		 String[] partx = receivedtest.split("Deleteport");
                        		    if (partx.length > 1) {
                    			int[] updatedValues = Arrays.stream(values)
	                                    .filter(port -> port != Integer.parseInt(partx[1]))
	                                    .toArray();
                    			values = updatedValues;
                    			System.out.println("Les Ports restants sont : ");
 	 					        for (int value : values) {
 	 					            System.out.println(value);}
                    			received2 = true;
                    			x2=1;
                        		    }
                    		}
                    		
                        	
                        	//socket.setSoTimeout(40000);}
                        	else{
                
                        		// Attente de la réception d'un datagramme token
                           		if(receivedtest.equals("NVToken")) {System.out.println("Nouveau Token Recu");}
                           		else { System.out.println("Token Recu depuis Client4");}
                    			
                    			received2 = true; // Marque le datagramme comme reçu
                     }
                         } catch (SocketTimeoutException e) {
                        	 System.out.println("Timer ran out, reallocation random du token");
                        	// int nouvPort = reallocateToken();
                        	 String message = "Token";
                        		RellocateToken(values,address);
                        		x2=1;
                			 }
                         
                         }
                     // peut etre avec while
                     while(x2==1) {
                     socket.setSoTimeout(40000);
                     received2 = false;
                     while (!received2) {
                         try {socket.receive(packet); 
                         	// String recumsg = new String(packet.getData(), 0, packet.getLength());
                         	String receivedtest = new String(packet.getData(), 0, packet.getLength());
                         			if(receivedtest.equals("Reset")){
                         			System.out.println("Reset du timer du client 05");
                         			received2 = true; // Marque le datagramme comme reçu
                             	}
                         			else         		if(receivedtest.contains("Deleteport")) {
                               		 String[] partx = receivedtest.split("Deleteport");
                         		    if (partx.length > 1) {
                     			int[] updatedValues = Arrays.stream(values)
 	                                    .filter(port -> port != Integer.parseInt(partx[1]))
 	                                    .toArray();
                     			values = updatedValues;
                     			System.out.println("Les Ports restants sont : ");
 	 					        for (int value : values) {
 	 					            System.out.println(value);}
                     			received2 = true;
                     			x2=1;
                         		    }
                     		}
                            		
                    			// Attente de la réception d'un datagramme token
                         			else{
                         				if(receivedtest.equals("NVToken")) {System.out.println("Nouveau Token Recu");}
                         				else { System.out.println("Token Recu depuis Client 05");}
                         				x2=0;
                         				received2 = true; // Marque le datagramme comme reçu
                         			}
                          } 
                         catch (SocketTimeoutException e) {
                        	 System.out.println("Timer ran out, reallocation random du token");
                        	// int nouvPort = reallocateToken();
                        	 String message = "Token";
                        		RellocateToken(values,address);
                        		
                			 }
                         
                         }
                     }
                         if(x2==0) {
            	 		 System.out.println("Client5 envoie nom du service a inter ");
            	 		 String Sx = i.Sending(reference);
            	 		 
            	//System.out.println("debug only +:"+Sx);
            	 		 
            	 String[] parts = Sx.split(" ", 3);
            	 String numService = parts[0];
            	 String nomService = parts[1];
            	 String descService = parts[2];
            	 System.out.println("numero service = " + numService + " / nom service = " + nomService + " / description service = " + descService);
            	 

                 String received = new String(packet.getData(), 0, packet.getLength());
                 System.out.println("Message reçu dans Client 5 : " + received);
            	 Thread.sleep(2000);
                
            	 // passer le token au prochain client
                 DatagramSocket socket2 = new DatagramSocket();
                 String message = "Token";
                 address = packet.getAddress(); // Utiliser l'adresse d'origine
                 if(iter==16) {
  	               //appel fonction pour supprimer le port 5511 de tous les autres clients
             	  Endofclient(values,address,4455);
             	  System.out.println("********MSG DE DELETE ENVOYE*********");
  	               }
                 int port = 5511; // Utiliser le port d'origine
                
                 
                 DatagramPacket packet2 = new DatagramPacket(message.getBytes(), message.length(), address, port);
                 socket2.send(packet2); // Envoi à l'adresse d'origine
                // if(isPortAvailable(address, port)) {
                 System.out.println("Message envoyé depuis Client 5 au Client 1");
                 //}
                 //else {System.out.println("Client 1 n'est pas disponible");}

                 socket2.close();
                         			socket.close();
                     }
        	 	 }}
        	 
        	 
        }
        catch(Exception e) 
    	{System.out.println("Exception : "+e.toString());}
	
}
	


}