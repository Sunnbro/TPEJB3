package packi;

import java.sql.SQLException;
import jakarta.ejb.Stateless;
import jakarta.persistence.EntityManager;
import jakarta.persistence.NoResultException;
import jakarta.persistence.PersistenceContext;
import jakarta.persistence.TypedQuery;


@Stateless
public class ServeurCentral implements IServeurCentral {//implements IServeurCentral{
	
	
	
	
	@PersistenceContext
	EntityManager EM;
	
	
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



	


}
