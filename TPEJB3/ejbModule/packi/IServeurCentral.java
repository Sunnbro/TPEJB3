package packi;
import java.sql.SQLException;

import jakarta.ejb.Remote;

@Remote
public interface IServeurCentral{
	
	 void addservices() throws Exception;
	 void Addserver(String id,String ip, String name, int port) throws SQLException ;
	 String listServices(String msg) throws SQLException;
	
}
