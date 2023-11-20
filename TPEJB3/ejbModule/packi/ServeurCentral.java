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


import jakarta.annotation.PostConstruct;
import jakarta.ejb.Stateless;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.NoResultException;
import jakarta.persistence.Persistence;
import jakarta.persistence.PersistenceContext;
import jakarta.persistence.TypedQuery;
@SuppressWarnings("unused")

@Stateless
public class ServeurCentral implements IServeurCentral {//implements IServeurCentral{
	
	
	
	
	@PersistenceContext
	EntityManager EM;
	
	
	
	
	
//charger driver MySql
	
	
	public int add(int a,int b) throws Exception{ return a+b;}
	
	
	public void addservices() {
		try {Long count = (Long) EM.createQuery("SELECT COUNT(s) FROM TBService s WHERE s.number BETWEEN 0 AND 15")
                .getSingleResult();

		if (count != 16) { 	for (int i = 0; i < 16; i++) {
	            String id = String.valueOf(i);
	            String prevId = String.valueOf(i);
	            String libelle = "Service" + i;
	            String description = "Description du Service" + i;
	            TBService service = new TBService(id, prevId, libelle, description);
	            EM.persist(service);}
			}
		}
		
		catch(Exception e) 
		{System.out.println("Exception : "+e.toString());
		}
	}

	@Override
	public Class[] value() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Class<? extends Annotation> annotationType() {
		// TODO Auto-generated method stub
		return null;
	}
	
	
	    final String url = "jdbc:mysql://localhost:3306/dbtest";
	    
	    
	  public void Addserver(String id,String ip, String name, int port) throws SQLException {
	       
		  Long count = (Long) EM.createQuery("SELECT COUNT(s) FROM TBserver s WHERE s.name = :serverName")
                  .setParameter("serverName", name)
                  .getSingleResult();
		  if (count == 0) {
		  TBserver server = new TBserver(id , ip , name, port);
          EM.persist(server);
		  }
		  }
	        
	        
	  public String listServices(String name) throws SQLException {
		    TypedQuery<TBService> query = EM.createQuery("SELECT s FROM TBService s WHERE s.name = :serviceName", TBService.class);
		    query.setParameter("serviceName", name);
		    try {
		        TBService s = query.getSingleResult();
		        String p1 = s.getnumber() + " " + s.getname() + " " + s.getdescription();
		        return p1;
		    } catch (NoResultException e) {
		        return "Service non trouvé"; // Gérer le cas où le service n'existe pas
		    }
		}



	  public static void main(String[] args) {
		    try {ServeurCentral sr = new ServeurCentral();
		    //sr.loadDriver();
		    
		    }
		    catch (Exception e) {e.printStackTrace();}
		}


}
