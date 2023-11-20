package packi;
import java.sql.SQLException;

import jakarta.ejb.Remote;

@Remote
public interface IServeurCentral extends Remote {
	
	 int add(int a,int b) throws Exception;
	 void addservices() throws Exception;
	 void Addserver(String id,String ip, String name, int port) throws SQLException ;
	 String listServices(String msg) throws SQLException;
	// void loadDriver() throws ClassNotFoundException;
	 //void Addserver(String ip, String name, int port) throws SQLException;
}
