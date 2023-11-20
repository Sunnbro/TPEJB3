package packi;
import java.sql.SQLException;

import jakarta.ejb.Remote;

@Remote
public interface IServeurCentral extends Remote {
	 void StartComSrvs(int port) throws Exception;
	 void addservices() throws Exception;
	 void Addserver(String ip, String name, int port) throws SQLException;
}
