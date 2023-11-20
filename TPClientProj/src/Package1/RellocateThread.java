package Package1;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class RellocateThread extends Thread {
	private int port;
	private InetAddress address;
	public RellocateThread(InetAddress address ,int port){
		this.address = address;
		this.port = port;
	}
	
	public void run() 
	{
		try {	
			 DatagramSocket socket2 = new DatagramSocket();
        	 byte[] buffer = new byte[1024];

            // DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            
			 //InetAddress address = packet.getAddress(); // Utiliser l'adresse d'origine
             
             String msgreset = "Reset";
             DatagramPacket packet3 = new DatagramPacket(msgreset.getBytes(), msgreset.length(), address, port);
             socket2.send(packet3);
             
             socket2.close();
		}
     
    	catch(Exception e)			  {System.out.println("Exception : "+e.toString());}
	}
	

}
