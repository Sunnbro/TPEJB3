package Package1;

import java.net.BindException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Arrays;
import java.util.Random;

public class Client {
	// cette methode supprime le port d'un client qui a termine du tableau values tous les clients 
	  protected static void Endofclient(int[] arr,InetAddress address, int portsrc) {
			try {
			DatagramSocket socketR = new DatagramSocket();
			String msgr = "Deleteport"+portsrc;
			for (int i = 0; i < arr.length; i++) {//pour chaque port/client
				
		           if (arr[i] != portsrc) {
		        	   char thirdDigitChar = Integer.toString(arr[i]).charAt(2);// prend le port 5511, et extrait le 3eme chiffre
		        	   // Envoyer le message "delete" à tous les clients sauf celui source
		        	   int port = arr[i];
		               DatagramPacket resetPacket = new DatagramPacket(msgr.getBytes(), msgr.length(), address, port);
		               socketR.send(resetPacket);//envoyer message pour supprimer le port

		               System.out.println("Message pour suppression du port "+portsrc+" envoyé au Client " + thirdDigitChar);
		           //}
		       }
		}
			socketR.close();
			}
			catch (Exception e) {
			    System.out.println("Erreur lors de l'envoi du tokenDLT : " + e.getMessage());
					}
	} 
	  //cette methode verifie quels port sont offline et les supprime du tableau donne en argument (initialement ce tableau contient tt les ports)
	  protected static int[] checkstatus(int[] arr) {
		  boolean isAvailable2;
	       for (int i = 0; i < arr.length; i++) {
	           //if (values[i] != selectedInt) {
	    	   int port1 = arr[i];
	    	   isAvailable2 = isPortAvailable(port1);//isportavailable retourne vrai si il est disponible
	    	   if(isAvailable2) {
	    		   char thirdDigitChar = Integer.toString(port1).charAt(2);// par exemple le port 5511, et extrait le 3eme chiffre
		        	
	    		   System.out.println("?*************? PORT DELETED : "+port1+" QUI APPARTIENT AU CLIENT 0"+thirdDigitChar+"?*************? ");
	    		   int[] updatedValues = Arrays.stream(arr)//mise a jour du tableau
	    				   	.filter(port -> port != port1)
                            .toArray();
        			 arr = updatedValues;
        			
	    	   }
	          
		
	       }
	       return arr;}
	 
	  //retourne la position d'un element dans un tableau
	  public static int findPosition(int[] values, int number) {
		    for (int i = 0; i < values.length; i++) {
		        if (values[i] == number) {
		            return i; 
		            }
		    }
		    return -1; 
		}
	  
	  //teste si un port est offline ou pas
	  public static boolean isPortAvailable(int port) {
	        try (DatagramSocket ignored = new DatagramSocket(port)) {
	            return true; // Le port est disponible
	        } catch (BindException e) {
	            return false; // Le port est déjà utilisé
	        } catch (Exception e) {
	            return false; // Une autre erreur s'est produite
	        }
	    }
	  
	  //methode qui cree un nouveau token et l'envoi a un client, plus un reset des timers a tous les clients.
	public static void RellocateToken(int[] valarr,InetAddress address) {
		try{
		
		   Random random = new Random();
	       int ntport = 0;
	       boolean foundAvailablePort = false;

	       while (!foundAvailablePort) {
	    	// Génération d'un indice random pour sélectionner l'un des six port
		       int randomIndex = random.nextInt(valarr.length);

		       // Récupération du port random sélectionné 
		       int selectedInt = valarr[randomIndex];
		       
	           if (!isPortAvailable(selectedInt)) {
	               ntport=selectedInt; //sauv le port pour lui envoyer le token apres, car on doit envoyer le nouveau token a un port qui ecoute
	               foundAvailablePort = true; // Met fin à la boucle
	           }
	       }
	       // envoyer ce token par socket UDP
	       DatagramSocket socketR = new DatagramSocket();
	       String msgr = "Reset";
	       boolean isAvailable2;// envoyer un message de reset a tous les cliens, si ils sont toujours online
	       for (int i = 0; i < valarr.length; i++) {
	          
	    	   int port = valarr[i];
	    	   isAvailable2 = isPortAvailable(port);
	    	   char thirdDigitChar = Integer.toString(valarr[i]).charAt(2);// prend le port 5511, et extrait le 3eme chiffre
	        	   
	              try { DatagramPacket resetPacket = new DatagramPacket(msgr.getBytes(), msgr.length(), address, port);
	               socketR.send(resetPacket);//envoi

	               System.out.println("Message de reset envoyé au Client 0" + thirdDigitChar);
	              }
	              catch(Exception ignored) {
	                    // Ignorer l'envoi du paquet si le port n'est pas disponible
	                }
	          
	       }
	       
	       String msg = "NVToken";
	       char thirdDigitChar = Integer.toString(ntport).charAt(2);// prend le port 5511, et extrait le 3eme chiffre
       	   System.out.println("Nouveau token crée et envoyé au Client 0"+thirdDigitChar+".");
       	   DatagramPacket packet1 = new DatagramPacket(msg.getBytes(), msg.length(), address, ntport);
       	   socketR.send(packet1); // Envoi du token à l'adresse d'origine
       	   socketR.close();
		
		}
		catch (Exception e) {
	    System.out.println("Erreur lors de la relocalisation du token : " + e.getMessage());
			}
		}
     
	
}
