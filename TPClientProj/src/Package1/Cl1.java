package Package1;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketTimeoutException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Arrays;

import packinter.Iinter;


public class Cl1 extends Client {
    public static int[] values = {1122, 2233, 3344, 4455, 5566, 6611};

    public static void main(String[] args) throws Exception {
        try {
            String[] clientReferenceChain = {"Service1", "Service0", "Service4", "Service12", "Service11", "Service10",
                    "Service9", "Service8", "Service7", "Service6", "Service5", "Service4", "Service3", "Service2",
                    "Service1", "Service0", "FIN"};
            Registry r = LocateRegistry.getRegistry("localhost", 1099);
            Iinter i = (Iinter) r.lookup("refinter");

            System.out.println("============================================================");
            System.out.println("============================================================");
            System.out.println("Client1 envoie nom du service a inter ");

            String Sx = i.Sending(clientReferenceChain[0]);
            String[] parts = Sx.split(" ", 3);
            String numService = parts[0];
            String nomService = parts[1];
            String descService = parts[2];

            System.out.println(
                    "numero service = " + numService + " / nom service = " + nomService + " / description service = "
                            + descService);

            DatagramSocket socketf = new DatagramSocket();
            String message = "Token";
            InetAddress address = InetAddress.getLocalHost();
            int[] p = SansPort1(values, 6611);
            values = checkstatus(p);
            int y1 = findPosition(values, 6611);
            int mod = (y1 + 1) % values.length;
            int port1 = values[mod];
            char clientmod = Integer.toString(port1).charAt(2);

            DatagramPacket packetf = new DatagramPacket(message.getBytes(), message.length(), address, port1);
            socketf.send(packetf);

            System.out.println("Message envoyé depuis Client 01 au Client 0" + clientmod);

            socketf.close();

            for (int iz = 1; iz < clientReferenceChain.length; iz++) {
                if (clientReferenceChain[iz].equals("FIN")) {
                    System.out.println("Fin client1");
                } else {
                    System.out.println("============================================================");
                    System.out.println("============================================================");

                    DatagramSocket socket = new DatagramSocket(6611);
                    socket.setSoTimeout(40000);
                    byte[] buffer = new byte[1024];
                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

                    boolean received2 = false;
                    int x2 = 0;

                    while (!received2) {
                        try {
                            socket.receive(packet);
                            String receivedtest = new String(packet.getData(), 0, packet.getLength());

                            if (receivedtest.equals("Reset")) {
                                System.out.println("Reset du timer du client 2");
                                received2 = true;
                                x2 = 1;
                            } else if (receivedtest.contains("Deleteport")) {
                                String[] partx = receivedtest.split("Deleteport");
                                if (partx.length > 1) {
                                    int[] updatedValues = Arrays.stream(values)
                                            .filter(port -> port != Integer.parseInt(partx[1]))
                                            .toArray();
                                    values = updatedValues;
                                    System.out.println("Les Ports restants sont : ");
                                    for (int value : values) {
                                   	 char third = Integer.toString(value).charAt(2);
                                        System.out.println("Client 0"+third+", son port :"+value);
                                   }
                                    received2 = true;
                                    x2 = 1;
                                }
                            } else {
                                if (receivedtest.equals("NVToken")) {
                                    System.out.println("Nouveau Token Recu");
                                } else {
                                    System.out.println("Token normal Recu");
                                }
                                received2 = true;
                            }
                        } catch (SocketTimeoutException e) {
                            System.out.println("Timer ran out, reallocation random du token");
                            message = "Token";
                            RellocateToken(values, address);
                            x2 = 1;
                        }
                    }

                    while (x2 == 1) {
                        socket.setSoTimeout(40000);
                        received2 = false;

                        while (!received2) {
                            try {
                                socket.receive(packet);
                                String receivedtest = new String(packet.getData(), 0, packet.getLength());

                                if (receivedtest.equals("Reset")) {
                                    System.out.println("Reset du timer du client 01");
                                    received2 = true;
                                } else if (receivedtest.contains("Deleteport")) {
                                    String[] partx = receivedtest.split("Deleteport");
                                    if (partx.length > 1) {
                                        int[] updatedValues = Arrays.stream(values)
                                                .filter(port -> port != Integer.parseInt(partx[1]))
                                                .toArray();
                                        values = updatedValues;
                                        System.out.println("Les Ports restants sont : ");
                                        for (int value : values) {
                                       	 char third = Integer.toString(value).charAt(2);
                                            System.out.println("Client 0"+third+", son port :"+value);
                                       }
                                        received2 = true;
                                        x2 = 1;
                                    }
                                } else {
                                    if (receivedtest.equals("NVToken")) {
                                        System.out.println("Nouveau Token Recu");
                                    } else {
                                        System.out.println("Token normal Recu");
                                    }
                                    x2 = 0;
                                    received2 = true;
                                }
                            } catch (SocketTimeoutException e) {
                                System.out.println("Timer ran out, reallocation random du token");
                                message = "Token";
                                RellocateToken(values, address);
                            }
                        }
                    }

                    if (x2 == 0) {
                        System.out.println("Client 01 envoie nom du service a inter ");
                        Sx = i.Sending(clientReferenceChain[iz]);
                        parts = Sx.split(" ", 3);
                        numService = parts[0];
                        nomService = parts[1];
                        descService = parts[2];
                        System.out.println(
                                "numero service = " + numService + " / nom service = " + nomService
                                        + " / description service = " + descService);

                        String received = new String(packet.getData(), 0, packet.getLength());
                        System.out.println("Message reçu dans Client 01 : " + received);
                        Thread.sleep(2000);

                        DatagramSocket socket2 = new DatagramSocket();

                        message = "Token";
                        address = packet.getAddress();

                        if (iz == 15) {
                            Endofclient(values, address, 6611);
                            System.out.println("********Client termine, on enleve son port des autres client*********");
                        }

                        p = values;
                        values = checkstatus(p);
                        y1 = findPosition(values, 6611);
                        mod = (y1 + 1) % values.length;
                        int port = values[mod];
                        clientmod = Integer.toString(port).charAt(2);
                        DatagramPacket packet2 = new DatagramPacket(message.getBytes(), message.length(), address, port);
                        socket2.send(packet2);

                        System.out.println("Message envoyé depuis Client 01 au Client 0" + clientmod);

                        socket2.close();
                        socket.close();
 	                   
 	               
 	                       }
 	        	 	 }
 	 			//fin parcours de la chaine de reference	 
 	 			}
        	 
        }
        catch(Exception e) 
    	{System.out.println("Exception : "+e.toString());}
	
}

	
	 public static int[] SansPort1(int [] values, int portToRemove) {
	        int[] updatedValues = Arrays.stream(values)
	                                    .filter(port -> port != portToRemove)
	                                    .toArray();
	        return updatedValues;
	    }	
}
