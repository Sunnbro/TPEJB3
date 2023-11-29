package packi;

import java.sql.SQLException;
import jakarta.ejb.Stateless;
import jakarta.persistence.EntityManager;
import jakarta.persistence.NoResultException;
import jakarta.persistence.PersistenceContext;
import jakarta.persistence.TypedQuery;

//ORDRE D'EXECUTION: Servercentral(run on server)->server1->server2->server3->server4->server5(peu importe pour les servers)->inter->Cl2->Cl3->Cl4->Cl5->Cl6->Cl1

@Stateless
public class ServeurCentral implements IServeurCentral {
	// on va utiliser Entitymanager pour communiquer avec La base de donnees
	@PersistenceContext
	EntityManager EM;
	
	//cette methode ajoute les services si ils n'existent pas deja
	public void addservices() {
		try {Long count = (Long) EM.createQuery("SELECT COUNT(s) FROM TBService s WHERE s.number BETWEEN 0 AND 15")
                .getSingleResult();

		if (count != 16) { 	for (int i = 0; i < 16; i++) {
	            String id = String.valueOf(i);
	            String prevId = String.valueOf(i);
	            String libelle = "Service" + i;
	            String description = "Description du Service" + i;
	            TBService service = new TBService(id, prevId, libelle, description);
	            EM.persist(service);//ajoute le service
	            }
			}
		}
		
		catch(Exception e) 
		{System.out.println("Exception : "+e.toString());
		}
	}

		
	   // final String url = "jdbc:mysql://localhost:3306/dbtest";
	    
	//cette methode ajoute le server si il n'existe pas deja   
	  public void Addserver(String id,String ip, String name, int port) throws SQLException {
	       
		  Long count = (Long) EM.createQuery("SELECT COUNT(s) FROM TBserver s WHERE s.name = :serverName")
                  .setParameter("serverName", name)
                  .getSingleResult();
		  if (count == 0) {
		  TBserver server = new TBserver(id , ip , name, port);
          EM.persist(server);//ajoute le server
		  }
		  }
	        
	//cette methode Renvoie les details du service( name, number , description) 
	  public String listServices(String name) throws SQLException {
		    TypedQuery<TBService> query = EM.createQuery("SELECT s FROM TBService s WHERE s.name = :serviceName", TBService.class);
		    query.setParameter("serviceName", name);
		    try {
		        TBService s = query.getSingleResult();
		        //concatener le resultat dans une seule chaine
		        String p1 = s.getnumber() + " " + s.getname() + " " + s.getdescription();
		        return p1;
		    } catch (NoResultException e) {
		        return "Service non trouvé"; // Gérer le cas où le service n'existe pas
		    }
		}



	


}
