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
public class Cl3 extends Client{
	public static int[] values = {1122, 2233, 3344, 4455, 5511};
	public static void main(String[] args) throws Exception{
        try { Cl3 client3 = new Cl3();
        	
        	 String[] clientReferenceChain = {"Service2","Service0","Service13","Service12","Service11","Service10","Service9","Service8","Service7","Service6","Service5","Service4","Service3","Service2","Service1","Service0","FIN"};
  //, "S10", "S1", "S2", "S4", "S3", "S0", "S6", "S12", "S11", "S8", "S5", "S2", "S1", "S0", "S5", "S1", "S7", "S9", "S2.FIN"};
        	 InetAddress address = null;
         	
        	 Registry r = LocateRegistry.getRegistry("localhost",1099);
        	 Iinter i = (Iinter) r.lookup("refinter");
        	 int x=0;
        	 int x2=0;
        	 int iter=0;
        	 //System.out.println("voici le resultat: x= "+ x);
        	 
        	//creation d'un jump si reset
        	 //outerloop:
        	 for (String reference : clientReferenceChain) {
        		 iter++;
        		 if(reference.equals("FIN")){System.out.println("Fin client3");
					}
        	 	 else {
        	 		System.out.println("============================================================");
        	 		System.out.println("============================================================");
        //attendre que Client1 donne token
        	 		 
                	 DatagramSocket socket = new DatagramSocket(2233); // Même port que P1
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
                        		System.out.println("Reset du timer du client 3");
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
                           		else { System.out.println("Token normal Recu ");}
                    			
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
                         			System.out.println("Reset du timer du client 03");
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
                         				else { System.out.println("Token normal Recu");}
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
            	 		 System.out.println("Client 03 envoie nom du service a inter ");
            	 		 String Sx = i.Sending(reference);
            	 		 
            	//System.out.println("debug only +:"+Sx);
            	 		 
            	 String[] parts = Sx.split(" ", 3);
            	 String numService = parts[0];
            	 String nomService = parts[1];
            	 String descService = parts[2];
            	 System.out.println("numero service = " + numService + " / nom service = " + nomService + " / description service = " + descService);
            	 

                 String received = new String(packet.getData(), 0, packet.getLength());
                 System.out.println("Message reçu dans Client 03 : " + received);
            	 //Thread.sleep(2000);
                
            	 // passer le token au prochain client
                 DatagramSocket socket2 = new DatagramSocket();
                 String message = "Token";
                 address = packet.getAddress(); // Utiliser l'adresse d'origine
                 if(iter==16) {
  	               //appel fonction pour supprimer le port 5511 de tous les autres clients
             	  Endofclient(values,address,2233);
             	  System.out.println("********MSG DE DELETE ENVOYE*********");
  	               }
                 //int port = 3344; // Utiliser le port d'origine
               /*  if(nomService.equals("Service13")){Thread.sleep(10000);}
                     socket.send(packet); 
                 */    
                 int y1 = findPosition(values,2233);
	                 int mod = (y1+1)%values.length;
	                 int port = values[mod];
	                char clientmod = Integer.toString(port).charAt(2);
	               DatagramPacket packet2 = new DatagramPacket(message.getBytes(), message.length(), address, port);
	               socket2.send(packet2); // Envoi à l'adresse d'origine
	               System.out.println("Message envoyé depuis Client 03 au Client 0"+clientmod);

                 socket2.close();
                         			socket.close();}
                     
                     
        	 	 }}
        	 
        	 
        }
        catch(Exception e) 
    	{System.out.println("Exception : "+e.toString());}
	
}
	
	
}