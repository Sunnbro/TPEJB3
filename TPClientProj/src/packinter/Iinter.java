package packinter;

import java.rmi.Remote;

public interface Iinter extends Remote{
	int add(int a,int b) throws Exception;
	 String Sending(String s) throws Exception;
}
