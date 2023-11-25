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
public class Cl3 {
	public static int[] values = {1122, 2233, 3344 ,4455, 5511};
	public static void main(String[] args) throws Exception{
        try { Cl3 client3 = new Cl3();
        	
        	 String[] clientReferenceChain = {"Service2","Service0","Service13","Service12","Service11","Service10","Service9","Service8","Service7","Service6","Service5","Service4","Service3","Service2","Service1","Service0","FIN"};
  //, "S10", "S1", "S2", "S4", "S3", "S0", "S6", "S12", "S11", "S8", "S5", "S2", "S1", "S0", "S5", "S1", "S7", "S9", "S2.FIN"};
        	 InetAddress address = null;
         	
        	 Registry r = LocateRegistry.getRegistry("localhost",1099);
        	 Iinter i = (Iinter) r.lookup("refinter");
        	 int x=0;
        	 int x2=0;
        	 //System.out.println("voici le resultat: x= "+ x);
        	 
        	//creation d'un jump si reset
        	 outerloop:
        	 for (String reference : clientReferenceChain) {
        	 	 if(reference.equals("FIN")){System.out.println("Fin client3");}
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
                                x2=1;}
                        	else{
                    			// Attente de la réception d'un datagramme token
                           		if(receivedtest.equals("NVToken")) {System.out.println("Nouveau Token Recu");}
                           		else { System.out.println("Token Recu depuis Client3");}
                    			
                    			received2 = true; // Marque le datagramme comme reçu
                     }
                         } catch (SocketTimeoutException e) {
                        	 System.out.println("Timer ran out, reallocation du random du token");
                        	// int nouvPort = reallocateToken();
                        	 String message = "Token";
                        	RellocateToken(address);
                        	x2=1;
                			 }
                         
                         }
                     
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
                        			// Attente de la réception d'un datagramme token
                             else{ 		if(receivedtest.equals("NVToken")) {System.out.println("Nouveau Token Recu");}
                               		else { System.out.println("Token Recu depuis Client 02");}
                        			x2=0;
                        			received2 = true; // Marque le datagramme comme reçu
                             }
                             } catch (SocketTimeoutException e) {
                            	 System.out.println("Timer ran out, reallocation random du token");
                            	// int nouvPort = reallocateToken();
                            	 String message = "Token";
                            		RellocateToken(address);
                            		
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
            	 Thread.sleep(3000);
                
            	 // passer le token au prochain client
                 DatagramSocket socket2 = new DatagramSocket();
                 String message = "Token";
                 address = packet.getAddress(); // Utiliser l'adresse d'origine
                 int port = 3344; // Utiliser le port d'origine
               /*  if(nomService.equals("Service13")){Thread.sleep(10000);}
                     socket.send(packet); 
                 */    
                 
                 DatagramPacket packet2 = new DatagramPacket(message.getBytes(), message.length(), address, port);
                 socket2.send(packet2); // Envoi à l'adresse d'origine
                 System.out.println("Message envoyé depuis Client 3 au Client 4");

                 socket2.close();
                         			socket.close();}
                     
                     
        	 	 }}
        	 
        	 
        }
        catch(Exception e) 
    	{System.out.println("Exception : "+e.toString());}
	
}
	

	private static void RellocateToken(InetAddress address) {
		try{


		 Random random = new Random();
	       

	       // Génération d'un indice aléatoire pour sélectionner l'un des cinq entiers
	       int randomIndex = random.nextInt(values.length);

	       // Récupération de l'entier sélectionné aléatoirement
	       int selectedInt = values[randomIndex];
	       
	       DatagramSocket socketR = new DatagramSocket();
	       String msgr = "Reset";
	       
	       for (int i = 0; i < values.length; i++) {
	           //if (values[i] != selectedInt) {
	               // Envoyer le message "Reset" à tous les clients sauf celui sélectionné
	               int port = values[i];
	               DatagramPacket resetPacket = new DatagramPacket(msgr.getBytes(), msgr.length(), address, port);
	               socketR.send(resetPacket);

	               System.out.println("Message de reset envoyé au Client " + (i + 1));
	           //}
	       }
	       
	       String msg = "Token";
	       
	       switch (selectedInt) {
	       		
	       	case 5511:		    
		    	System.out.println("Nouveau token crée et envoyé au Client 01.");
		    	DatagramPacket packet1 = new DatagramPacket(msg.getBytes(), msg.length(), address, 5511);
				socketR.send(packet1); // Envoi du token à l'adresse d'origine
		    		break;
		    	
	       	case 1122:		    
			    	System.out.println("Nouveau token crée et envoyé au Client 02.");
			    	DatagramPacket packet2 = new DatagramPacket(msg.getBytes(), msg.length(), address, 1122);
					socketR.send(packet2); // Envoi du token à l'adresse d'origine
			    	break;
			    	
			    case 2233:
			    	System.out.println("Nouveau token crée et envoyé au Client 03.");
			    	DatagramPacket packet3 = new DatagramPacket(msg.getBytes(), msg.length(), address, 2233);
					socketR.send(packet3); // Envoi du token à l'adresse d'origine
			    	break;
			    	
			    case 3344:		    
			    	System.out.println("Nouveau token crée et envoyé au Client 04.");
			    	DatagramPacket packet4 = new DatagramPacket(msg.getBytes(), msg.length(), address, 3344);
					socketR.send(packet4); // Envoi du token à l'adresse d'origine
			    	break;
			    	
			    case 4455:
			    	System.out.println("Nouveau token crée et envoyé au Client 05.");
			    	DatagramPacket packet5 = new DatagramPacket(msg.getBytes(), msg.length(), address, 4455);
					socketR.send(packet5); // Envoi du token à l'adresse d'origine
			    	break;
	       // Affichage de l'entier sélectionné
	       }
	      
	      // String resetMessage = "Reset";
	       //byte[] resetBuffer = resetMessage.getBytes();
	       
	      
	       
		
		}
		catch (Exception e) {
	    System.out.println("Erreur lors de la relocalisation du token : " + e.getMessage());
			}
		}
}