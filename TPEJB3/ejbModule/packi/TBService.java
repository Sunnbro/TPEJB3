package packi;

import java.io.Serializable;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name="tbservices")
public class TBService implements Serializable {
	 @Id
	   private String id;
	   private String number;
	   @Column(name = "name_Column")
	   private String name;
	   private String description;
	   
	   
	   public TBService() {
	      super();
	   }
	   public TBService(String id) {
	      this.id = id;
	   }
	   public TBService(String id,String number , String name, String description) {
	      this.id = id;
	      this.number = number;
	      this.name = name;
	      this.description = description;
	   }
	  
	   public String getId() {
		      return id;
		   }
	   
	   public String getnumber() {
		      return number;
		   }
		   public void setnumber(String number) {
		      this.number = number;
		   }
		   
	   public String getname() {
	      return name;
	   }
	   public void setname(String name) {
	      this.name = name;
	   }
	   public String getdescription() {
	      return description;
	   }
	   public void setdescription(String description) {
	      this.description = description;
	   }
	   
	   public String toString() {
	      return "Service Numero :" + number + " - Nom:" + name + " - Description : " +	description;
	   }
}

