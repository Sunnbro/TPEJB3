package packinter;

import java.rmi.Remote;

public interface Iinter extends Remote{
	String Sending(String s) throws Exception;
}
