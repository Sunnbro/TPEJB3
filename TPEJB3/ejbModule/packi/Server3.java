package packi;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

 
@SuppressWarnings("unused")
public class Server3 {
	public static void main(String[] args) {
		Server3 inst = new Server3();
	      try {
	    	  //connexion au server central
	    	
	  		
	    	  
			//connexion a inter: accepted		
			 ServerSocket s2 = new ServerSocket(2003);
			 while(true) {
				 Socket s1 = new Socket("localhost",2008); 
			  		System.out.println("\n connecte au server Central \n");
			 Socket conn = s2.accept();
			 	
			 	ObjectInputStream in1 = new ObjectInputStream(conn.getInputStream());//pour recevoir de inter
			//ObjectOutputStream out1 = new ObjectOutputStream(conn.getOutputStream());// pour renvoyer a inter le resultat
				String S = (String)in1.readObject();
				System.out.println("message recu de inter: "+S);
				
			//envoyer nom server a central pour enregistrement.
				ObjectOutputStream outsrv = new ObjectOutputStream(s1.getOutputStream());
			 	outsrv.writeObject(inst.getClass().getSimpleName());
			 	outsrv.flush();
			 	
			//on doit envoyer le nom du service recu depuis inter a serv central
				ObjectOutputStream outsrv2 = new ObjectOutputStream(s1.getOutputStream());
			 	outsrv2.writeObject(S);
			 	outsrv2.flush();
				
			//on doit lire resultat de serv central	
			 ObjectInputStream insrv = new ObjectInputStream(s1.getInputStream());//pour recevoir de srv central
				
			 	
			      String sq = (String)insrv.readObject();//lire a partir du server central
			      System.out.println("result recu de Server central: "+sq);
			      // System.out.println("Resultat :" +sq);
			     
				//
				ObjectOutputStream out1 = new ObjectOutputStream(conn.getOutputStream());// pour renvoyer a inter le resultat
				 out1.writeObject(sq);
	             out1.flush();
	             outsrv.close();
	             outsrv2.close();
	             insrv.close();
	             out1.close();
	             in1.close(); 
				conn.close(); 
				s1.close();
				
				if("FIN".equals(S)) break;
		            } 
			 
		            s2.close();
		            
		            
		            
		      
		            
		            
		 }
		  catch(Exception e)			  {System.out.println("Exception : "+e.toString());}
	     
	     
}
	

    


}
