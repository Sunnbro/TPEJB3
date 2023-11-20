package packi;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.annotation.Annotation;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import jakarta.ejb.Stateless;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import jakarta.persistence.PersistenceContext;
@SuppressWarnings("unused")

@Stateless
public class ServeurCentral {//implements IServeurCentral{

	
	public static void main(String[] args) {
		ServeurCentral sr = new ServeurCentral();
		  sr.StartComSrvs(2006);
	      sr.StartComSrvs(2007);
	      sr.StartComSrvs(2008);
	      sr.StartComSrvs(2009);
	      sr.StartComSrvs(2010);
	     
	     
}
	
//charger driver MySql
	
	public void StartComSrvs(int port) {
		//EntityManagerFactory emf = Persistence.createEntityManagerFactory("TPEJB3");

		 ServerThread serverThread = new ServerThread(port);//,entityManager);
	        serverThread.start();}


	


}
