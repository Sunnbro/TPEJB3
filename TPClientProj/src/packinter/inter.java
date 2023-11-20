package packinter;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.annotation.Annotation;
import java.net.Socket;
import java.rmi.Remote;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

import jakarta.ejb.Stateful;
import jakarta.ejb.Stateless;

@SuppressWarnings("unused")


public class inter extends java.rmi.server.UnicastRemoteObject implements Iinter {
	
public inter() throws Exception{}
	public int add(int a,int b) throws Exception{ return a+b;}
	
	public String Sending(String s) throws Exception {
		
		System.out.println("Message reçu du client, nom du server demandé: " + s);
		//sendViaTCP(s);
		String sa ="";
		  switch (s) {
		  case "Service0":
		    case "Service1":
		    case "Service2":
		    case "Service3":
		    
		    sa = sendViaTCPtoserver1(s);
		        break;
		    case "Service4":
		    case "Service5":
		    case "Service6":
		    sa = sendViaTCPtoserver2(s);
		        break;
		    case "Service7":
		    case "Service8":
		    case "Service9":
		    
		    sa = sendViaTCPtoserver3(s);
		        break;
		    case "Service10":
		    case "Service11":
		    case "Service12":
		    
		    sa = sendViaTCPtoserver4(s);
		        break;
		    case "Service13":
		    case "Service14":
		    case "Service15":
		    
		    sa = sendViaTCPtoserver5(s);
		        break;
	}
	return sa;	  
	}
	
	
	
	private String sendViaTCPtoserver1(String message) {
		try {
			
			
			
		Socket s1 = new Socket("localhost",2001); 
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
	
	private String sendViaTCPtoserver2(String message) {
		try {
			
		
		Socket s1 = new Socket("localhost",2002); 
		System.out.println("\n connecte au server distant \n");
		//
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

	private String sendViaTCPtoserver3(String message) {
		try {
		
		Socket s1 = new Socket("localhost",2003); 
		System.out.println("\n connecte au server distant \n");
		//
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
	
	private String sendViaTCPtoserver4(String message) {
		try {
			
			
			
		Socket s1 = new Socket("localhost",2004); 
		System.out.println("\n connecte au server distant \n");
		//
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
	
	private String sendViaTCPtoserver5(String message) {
		try {
		
		Socket s1 = new Socket("localhost",2005); 
		System.out.println("\n connecte au server distant \n");
		//
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
