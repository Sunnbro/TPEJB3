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
@SuppressWarnings("unused")
class ServerThread extends Thread {
	private int port;

	    public ServerThread(int port) {
	        this.port = port;
	    }

	    public void run() {
	    	try {
	    		
	   		 ServerSocket s3 = new ServerSocket(port);
	   		 while(true) {
	   		 Socket conn = s3.accept();//accepter cnx du server I
	   		    
	   			ObjectInputStream inclass1 = new ObjectInputStream(conn.getInputStream());//pour recevoir de server
	   			String Sx2 = (String)inclass1.readObject();
	   			System.out.println("nom de serverI: "+Sx2);
	   			ObjectInputStream in1 = new ObjectInputStream(conn.getInputStream());//pour recevoir de server
	   			
	   			String S = (String)in1.readObject();
	   			System.out.println("Demande recu depuis"+Sx2+": "+S);
	   		 String clientAddress = conn.getInetAddress().getHostAddress(); // Adresse IP du client
             int clientPort = conn.getPort();
             
            // System.out.println("server's port:"+clientPort+"and adresse ip:" + clientAddress);
             
             
             // ON AJOUTE LE SERVER A LA BASE DE DONNEES
             this.Addserver(clientAddress, Sx2, clientPort);
             
             
             // ON EXECUTE LA REQUETE
	   			this.loadDriver();
	   		      String sq = this.listServices(S);
	   		      System.out.println("Resultat server central :" +sq);
	   		     
	   			
	   			//
	   			ObjectOutputStream out1 = new ObjectOutputStream(conn.getOutputStream());// pour renvoyer a serverI le resultat
	   			 out1.writeObject(sq);
	              out1.flush();
	              out1.close();
	              inclass1.close();
	              in1.close(); 
	   			conn.close(); 
	   			if("FIN".equals(S)) break;
	   	            } 
	   	            s3.close();
	   	      
	   	            
	   	            
	   	 }catch(ClassNotFoundException e) {System.err.println("Pilote JDBC introuvable !");}
	   	  catch(SQLException e) 		  {System.out.println("SQLException: " + e.getMessage());}
	   	  catch(Exception e)			  {System.out.println("Exception : "+e.toString());}
	       
	   	}
	    
	    
	    
	  void loadDriver() throws ClassNotFoundException {
	        try {
	            Class.forName("com.mysql.cj.jdbc.Driver");
	        } catch (ClassNotFoundException e) {
	            throw new ClassNotFoundException("Pilote JDBC introuvable !", e);
	        }
	    }

	    final String url = "jdbc:mysql://localhost:3306/dbtest";
	    
	    
	  public void Addserver(String ip, String name, int port) throws SQLException {
	        Connection conn = null;
	        PreparedStatement preparedStatement = null;
	        ResultSet rs = null;

	        try {
	            conn = DriverManager.getConnection(url, "root", "root");

	            //verifier si la ROW existe deja dans la bdd
	            
	            String checkQuery = "SELECT COUNT(*) AS count FROM servers WHERE name = ?";
	            preparedStatement = conn.prepareStatement(checkQuery);
	            
	            preparedStatement.setString(1, name);
	            
	            rs = preparedStatement.executeQuery();
	            rs.next();
	            int count = rs.getInt("count");

	            if (count == 0) { String query = "INSERT INTO servers (ipaddress, name, port) VALUES (?, ?, ?)";

	            preparedStatement = conn.prepareStatement(query);
	            preparedStatement.setString(1, ip);
	            preparedStatement.setString(2, name);
	            preparedStatement.setString(3, String.valueOf(port));


	            preparedStatement.executeUpdate();
	            System.out.println("Serveur Ajoute avec succes: nom:"+name+" ipaddress:"+ip+" port:"+port);}
	            
	          
	        }
	    catch (SQLException e) {
	                e.printStackTrace();}
	     finally {
	            // Assurez-vous de fermer les ressources dans le bloc finally
	            if (rs != null) {
	                rs.close();
	            }
	            if (preparedStatement != null) {
	                preparedStatement.close();
	            }
	            if (conn != null) {
	                conn.close();
	            }
	        }

	        // Retournez la chaîne complète
	      
	    }

	//recuperer le service : requete sql
	    
	  private String listServices(String msg) throws SQLException {
	        Connection conn = null;
	        PreparedStatement preparedStatement = null;
	        ResultSet rs = null;

	        StringBuilder resultStringBuilder = new StringBuilder();

	        try {
	            conn = DriverManager.getConnection(url, "root", "root");
	            String query = "SELECT number, name, description FROM services WHERE name=?";
	            
	            preparedStatement = conn.prepareStatement(query);
	            preparedStatement.setString(1, msg);

	            rs = preparedStatement.executeQuery();
	            while (rs.next()) {
	                String serviceInfo = rs.getString("number") + " " + rs.getString("name") + " " + rs.getString("description");
	                System.out.println("Requete effectuée");

	                // Ajoutez le résultat à StringBuilder
	                resultStringBuilder.append(serviceInfo).append("\n");
	            }
	        }
	    catch (SQLException e) {
	                e.printStackTrace();}
	     finally {
	            // Assurez-vous de fermer les ressources dans le bloc finally
	            if (rs != null) {
	                rs.close();
	            }
	            if (preparedStatement != null) {
	                preparedStatement.close();
	            }
	            if (conn != null) {
	                conn.close();
	            }
	        }

	        // Retournez la chaîne complète
	        return resultStringBuilder.toString();
	    }
	    }
	
	