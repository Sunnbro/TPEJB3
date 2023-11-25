package Package1;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Random;

public class Client {
	
	public static void RellocateToken(InetAddress address) {
		try{
			int[] values = {1122, 2233, 3344 ,4455, 5511};

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
	       
	       String msg = "NVToken";
	       
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
