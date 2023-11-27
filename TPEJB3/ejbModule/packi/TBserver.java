package packi;

import java.io.Serializable;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name="tbservers")
public class TBserver implements Serializable {
	 @Id
	   private String id;
	   private String ipaddress;
	   @Column(name = "name_Column")
	   private String name;
	   private int port;
	   
	   
	   public TBserver() {
	      super();
	   }
	   public TBserver(String id) {
	      this.id = id;
	   }
	   public TBserver(String id,String ipaddress , String name, int port) {
	      this.id = id;
	      this.ipaddress = ipaddress;
	      this.name = name;
	      this.port = port;
	   }
	  
	   public String getId() {
		      return id;
		   }
	   
	   public String getipaddress() {
		      return ipaddress;
		   }
		   public void setipaddress(String ipaddress) {
		      this.ipaddress = ipaddress;
		   }
		   
	   public String getname() {
	      return name;
	   }
	   public void setname(String name) {
	      this.name = name;
	   }
	   public int getport() {
	      return port;
	   }
	   public void setport(int port) {
	      this.port = port;
	   }
	   
	   public String toString() {
	      return "Server IPaddress :" + ipaddress + " - Nom:" + name + " - port : " +	port;
	   }
}

