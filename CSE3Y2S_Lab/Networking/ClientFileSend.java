import java.net.*;  
import java.io.*;  
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.Socket;

public class ClientFileSend {
	
	private Socket s;
	
	public ClientFileSend(String host, int port, String file) {
		try {
			s = new Socket(host, port);
			sendFile(file);
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}
	
	public void sendFile(String file) throws IOException {
		DataOutputStream dos = new DataOutputStream(s.getOutputStream());
		FileInputStream fis = new FileInputStream(file);
		byte[] buffer = new byte[4096];
		
		while (fis.read(buffer) > 0) {
			dos.write(buffer);
		}
		
		fis.close();
		dos.close();	
	}
	
	public static void main(String args[])throws Exception{
  
		Socket s=new Socket("localhost",1988);  
		DataInputStream din=new DataInputStream(s.getInputStream());  
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
  
		String str_server;  
		str_server =din.readUTF();  
		System.out.println("Server says: "+str_server);  
		System.out.println("Client reply: ");
		String fileName =br.readLine();  
		dout.writeUTF(fileName);  			
		dout.flush(); 
		
		str_server =din.readUTF();  
		System.out.println("Server says: "+str_server);  
		System.out.println("Client reply: ");
		String fileSize = br.readLine();  
		dout.writeUTF(fileSize);  			
		dout.flush(); 
		
		ClientFileSend fc = new ClientFileSend("localhost", 1988, fileName);
	}  
}