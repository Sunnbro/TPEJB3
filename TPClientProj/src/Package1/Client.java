package Package1;

import java.io.IOException;
import java.net.BindException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketAddress;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class Client {
	
	//protected static int[] values = {1122, 2233, 3344, 4455, 5511};
	 //AU LIEU D'ENVOYER AU PROCHAIN EXPLICITEMENT, ET PUISQUE on SUPPRIME QUAND un est termine, EN ENVOIE AU NEXT
	//  public static int[] getValues() {
	  //      return values;
	    //}
	
	 /* public static void removePort(int portToRemove) {
	        int[] updatedValues = Arrays.stream(values)
	                                    .filter(port -> port != portToRemove)
	                                    .toArray();
	        values = updatedValues;
	    }
	*/
	  protected static void Endofclient(int[] arr,InetAddress address, int portsrc) {
			try {
			DatagramSocket socketR = new DatagramSocket();
			String msgr = "Deleteport"+portsrc;
			for (int i = 0; i < arr.length; i++) {
				
		           if (arr[i] != portsrc) {
		        	   char thirdDigitChar = Integer.toString(arr[i]).charAt(2);// prend le port 5511, et extrait le 3eme chiffre
		        	   // Envoyer le message "delete" à tous les clients sauf celui source
		        	   int port = arr[i];
		               DatagramPacket resetPacket = new DatagramPacket(msgr.getBytes(), msgr.length(), address, port);
		               socketR.send(resetPacket);

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
	  protected static int[] checkstatus(int[] arr) {
		  boolean isAvailable2;
	       for (int i = 0; i < arr.length; i++) {
	           //if (values[i] != selectedInt) {
	    	   int port1 = arr[i];
	    	   isAvailable2 = isPortAvailable(port1);
	    	   if(isAvailable2) {
	    		   char thirdDigitChar = Integer.toString(port1).charAt(2);// prend le port 5511, et extrait le 3eme chiffre
		        	
	    		   System.out.println("?*************? PORT DELETED : "+port1+" QUI APPARTIENT AU CLIENT 0"+thirdDigitChar+"?*************? ");
	    		   int[] updatedValues = Arrays.stream(arr)
	    				   	.filter(port -> port != port1)
                            .toArray();
        			 arr = updatedValues;
        			
	    	   }
	          
		
	       }
	       return arr;}
	 
	  public static int findPosition(int[] values, int number) {
		    for (int i = 0; i < values.length; i++) {
		        if (values[i] == number) {
		            return i; 
		            }
		    }
		    return -1; 
		}
	  public static boolean isPortAvailable(int port) {
	        try (DatagramSocket ignored = new DatagramSocket(port)) {
	            return true; // Le port est disponible
	        } catch (BindException e) {
	            return false; // Le port est déjà utilisé
	        } catch (Exception e) {
	            return false; // Une autre erreur s'est produite
	        }
	    }
	public static void RellocateToken(int[] valarr,InetAddress address) {
		try{
		
		   Random random = new Random();
	       int ntport = 0;
	       boolean foundAvailablePort = false;

	       while (!foundAvailablePort) {
	    	// Génération d'un indice aléatoire pour sélectionner l'un des cinq entiers
		       int randomIndex = random.nextInt(valarr.length);

		       // Récupération de l'entier sélectionné aléatoirement
		       int selectedInt = valarr[randomIndex];
		       
	           if (!isPortAvailable(selectedInt)) {
	               ntport=selectedInt;
	             //  System.out.println(ntport+"???????????????????????????????");
	               foundAvailablePort = true; // Met fin à la boucle
	           }
	       }
	       
	       DatagramSocket socketR = new DatagramSocket();
	       String msgr = "Reset";
	       boolean isAvailable2;
	       for (int i = 0; i < valarr.length; i++) {
	           //if (values[i] != selectedInt) {
	    	   int port = valarr[i];
	    	   isAvailable2 = isPortAvailable(port);
	    	   char thirdDigitChar = Integer.toString(valarr[i]).charAt(2);// prend le port 5511, et extrait le 3eme chiffre
	        	  
	          // if (isAvailable2) {
	               // Envoyer le message "Reset" à tous les clients sauf celui sélectionné
	               
	              try { DatagramPacket resetPacket = new DatagramPacket(msgr.getBytes(), msgr.length(), address, port);
	               socketR.send(resetPacket);

	               System.out.println("Message de reset envoyé au Client 0" + thirdDigitChar);
	              }
	              catch(Exception ignored) {
	                    // Ignorer l'envoi du paquet si le port n'est pas disponible
	                }
	              
	           //}
	          
	       }
	       
	       String msg = "NVToken";
	       
	      /* System.out.println("Nouveau token crée et envoyé au Client "+randomIndex+".");
	    	DatagramPacket packet1 = new DatagramPacket(msg.getBytes(), msg.length(), address, selectedInt);
			socketR.send(packet1); // Envoi du token à l'adresse d'origine
	    	*/
	      
	       
	      // System.out.println(ntport);
	    	   
	       switch (ntport) {
	       		
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
	       
	      
	       socketR.close();
		
		}
		catch (Exception e) {
	    System.out.println("Erreur lors de la relocalisation du token : " + e.getMessage());
			}
		}
     
	
}
