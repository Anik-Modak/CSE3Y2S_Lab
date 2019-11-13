import java.io.*;  
import java.net.*;  

public class ClientProgram{  
	public static void main(String[] args) {  
		try{      
			Socket s=new Socket("10.110.55.48", 5555);  
			DataOutputStream dout = new DataOutputStream(s.getOutputStream());  
			dout.writeUTF("Hi! I am Anik");  
			dout.flush();  
			dout.close();  
			s.close();  
		}catch(Exception e){System.out.println(e);}  
	}  
}  