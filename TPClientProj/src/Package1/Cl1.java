package Package1;
import java.rmi.registry.Registry;
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
public class Cl1 {
	public static int[] values = {9876, 1587, 6958, 5719 };
	public static void main(String[] args) throws Exception{
        try {
        	 String[] clientReferenceChain = {"Service1","Service0","Service4","Service12","Service11","Service10","Service9","Service8","Service7","Service6","Service5","Service4","Service3","Service2","Service1","Service0","FIN"};
  //, "S10", "S1", "S2", "S4", "S3", "S0", "S6", "S12", "S11", "S8", "S5", "S2", "S1", "S0", "S5", "S1", "S7", "S9", "S2.FIN"};

        	Registry r = LocateRegistry.getRegistry("localhost",1099);
        	 Iinter i = (Iinter) r.lookup("refinter");
        	 int x=0;
        	 //int x = i.add(9, 12);
        	 //System.out.println("voici le resultat: x= "+ x);
        	 for (String reference : clientReferenceChain) {
        	 	 if(reference.equals("FIN")){System.out.println("Fin client1");}
        	 	 else {	 
        	 		 System.out.println("Client envoie nom du service a inter ");
        	 		 String Sx = i.Sending(reference);
        	//System.out.println("debug only +:"+Sx);
        	 String[] parts = Sx.split(" ", 3);
        	 String numService = parts[0];
        	 String nomService = parts[1];
        	 String descService = parts[2];
        	 System.out.println("numero service = " + numService + " / nom service = " + nomService + " / description service = " + descService);
        	 
        	 //UDP entre les clients
        	
        	 //datagramme pour envoyer au prochain client
        	 DatagramSocket socket = new DatagramSocket();
             String message = "Token";
             InetAddress address = InetAddress.getLocalHost(); 
             int port = 9876; // Numéro de port pour le prochain client
            
             DatagramPacket packet = new DatagramPacket(message.getBytes(), message.length(), address, port);
           // if(!nomService.equals("Service4")&& x==0){
             socket.send(packet); 
             //if(nomService.equals("Service4")) x=1;}
             System.out.println("Token envoyé depuis Client 1 au Client 2");
             //thread.sleep(3000);
             //RECEPTION
             DatagramSocket sk2 = new DatagramSocket(2541);
             socket.setSoTimeout(30000);
 			byte[] buffer = new byte[1024];
             DatagramPacket receivedPacket = new DatagramPacket(buffer, buffer.length);
             
             boolean received = false;
             while (!received) {
                 try {
                     sk2.receive(packet); // Attente de la réception d'un datagramme
                     received = true; // Marque le datagramme comme reçu
                 } catch (SocketTimeoutException e) {
                     // Si aucun datagramme n'est reçu pendant le délai, continue la boucle
                	 DatagramSocket socket3 = new DatagramSocket();
                	 System.out.println("Timer ran out, reallocation du random du token");
                     InetAddress address2 = packet.getAddress(); // Utiliser l'adresse d'origine
                     String message2 = "Token";
                     int nouvPort = reallocateToken();
                     DatagramPacket packet2 = new DatagramPacket(message2.getBytes(), message2.length(), address2, nouvPort);
                     socket3.send(packet2);
                 }
             }
        	 
             socket.close();
 			sk2.close();
        	 	 }
        	 	 }
        	 
        	 
        }
        catch(Exception e) 
    	{System.out.println("Exception : "+e.toString());}
	
}
	public static int reallocateToken() {
		  Random random = new Random();
	        

	        // Génération d'un indice aléatoire pour sélectionner l'un des cinq entiers
	        int randomIndex = random.nextInt(values.length);

	        // Récupération de l'entier sélectionné aléatoirement
	        int selectedInt = values[randomIndex];

	        
	        switch (selectedInt) {
        	case 9876:		    
        		System.out.println("Nouveau token crée et envoyé au Client 02.");
        		break;
		    	
		    case 1587:		    
		    	System.out.println("Nouveau token crée et envoyé au Client 03.");
		    	break;
		    	
		    case 6958:
		    	System.out.println("Nouveau token crée et envoyé au Client 04.");
		    	break;
		    	
		    case 5719:		    
		    	System.out.println("Nouveau token crée et envoyé au Client 05.");
		    	break;
		    	
		   
	        // Affichage de l'entier sélectionné
	        }
	        return selectedInt;
		  	
	        
	}
}