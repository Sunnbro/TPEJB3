package packinter;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;


public class inter extends java.rmi.server.UnicastRemoteObject implements Iinter {
	
public inter() throws Exception{}
	public String Sending(String s) throws Exception {
		
		System.out.println("Message reçu du client, nom du server demandé: " + s);
		//sendViaTCP(s);
		String sa ="";
		  switch (s) {
		  case "Service0":
		    case "Service1":
		    case "Service2":
		    case "Service3":
		    
		    sa = sendViaTCPtoserver(s,2001); 
		        break;
		    case "Service4":
		    case "Service5":
		    case "Service6":
		    sa = sendViaTCPtoserver(s,2002);
		        break;
		    case "Service7":
		    case "Service8":
		    case "Service9":
		    
		    sa = sendViaTCPtoserver(s,2003);
		        break;
		    case "Service10":
		    case "Service11":
		    case "Service12":
		    
		    sa = sendViaTCPtoserver(s,2004);
		        break;
		    case "Service13":
		    case "Service14":
		    case "Service15":
		    
		    sa = sendViaTCPtoserver(s,2005);
		        break;
	}
	return sa;	  
	}
	
	
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	private String sendViaTCPtoserver(String message,int port) {
		try {
			
			
			
		Socket s1 = new Socket("localhost",port); 
		System.out.println("\n connecte au server distant \n");
		
		ObjectOutputStream out1 = new ObjectOutputStream(s1.getOutputStream());
	 	out1.writeObject(message);
	 	out1.flush();
	 	
	 	
	 	
		
		
		ObjectInputStream in1 = new ObjectInputStream(s1.getInputStream());
		String S1 = (String)in1.readObject();
		System.out.println("message recu du server (Requete effectue): "+S1);
		out1.close();
		in1.close();
		s1.close();
		return S1;
		
		}catch(Exception e) 
		{System.out.println("Exception : "+e.toString());
		return null;}
		
		}

	
	public static void main (String[] args) throws Exception{
	    inter p = new inter();
	    Registry r = LocateRegistry.createRegistry(1099);
	    r.rebind("refinter", p);
	}
	

}
