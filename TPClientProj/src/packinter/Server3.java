package packinter;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Properties;
import javax.naming.InitialContext;
import packi.IServeurCentral;
import packi.ServeurCentral;

 
public class Server3 {
	public static void main(String[] args) {
		Server3 inst = new Server3();
		 try {
	    	  Properties props = new Properties();
				 props.put("java.naming.factory.url.pkgs","org.jboss.ejb.client.naming");
				//juste pour affichage
				 InitialContext context = new InitialContext(props);
				 String Appname = "";
				 String moduleName ="TPEJB3";
				 String distinctName = "";
			 	 String BeanName = ServeurCentral.class.getSimpleName();
			 	 String InterfaceName = IServeurCentral.class.getName();
				 String name = "ejb:"+ Appname + "/" + moduleName +"/"+ distinctName +"/"+ BeanName +"/"+ InterfaceName+"///";
				 System.out.println(name);
				//juste pour affichage
				 IServeurCentral i = (IServeurCentral) context.lookup("ejb:/TPEJB3/ServeurCentral!packi.IServeurCentral");
				 i.addservices();
			      
					//connexion a inter: accepted		
					 ServerSocket s2 = new ServerSocket(2003);
					 while(true) {
						
					 Socket conn = s2.accept();
					 // prendre les infos necessaires
					 // nom du server
					 String Sx = inst.getClass().getSimpleName();
					 // Adresse IP du client
					 String clientAddress = conn.getInetAddress().getHostAddress(); 
					 // Numero du port
		             int clientPort = conn.getPort();	
		             
		             //envoyer nom server a servercentral pour enregistrement.
		             //APPELER AVEC RMI	
		             i.Addserver("1",clientAddress, Sx, clientPort);
		             
		             //Recevoir de inter avec TCP le nom du service
					 	ObjectInputStream in1 = new ObjectInputStream(conn.getInputStream());
					 	String S = (String)in1.readObject();
						System.out.println("message recu de inter: "+S);
						
			
						//demander le number,name,description de ce service depuis la bdd avec RMI
			   		    String sq = i.listServices(S);
						System.out.println("result recu de Server central: "+sq);
						//renvoyer a Inter
						ObjectOutputStream out1 = new ObjectOutputStream(conn.getOutputStream());// pour renvoyer a inter le resultat
						 out1.writeObject(sq);
			             out1.flush();
			          
			             out1.close();
			             in1.close(); 
						conn.close(); 
						// si FIN on sort
						if("FIN".equals(S)) break;
				            } 
				            s2.close();
					 }
				  catch(Exception e)			  {System.out.println("Exception : "+e.toString());}
			     
		}
			}
