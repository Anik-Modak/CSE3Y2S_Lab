import java.net.*;  
import java.io.*;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.Socket;

public class FileClient {
	
	private Socket s;
	
	public FileClient(String host, int port, String file) {
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
		byte[] buffer = new byte[80000];
		
		while (fis.read(buffer) > 0) {
			dos.write(buffer);
		}
 
		fis.close();
		dos.close();	
	}
	
	public static void main(String[] args) throws Exception{

		Socket s = new Socket("10.110.49.159", 1988);  
		DataInputStream din=new DataInputStream(s.getInputStream());  
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
  
		String str1, str2;  
 		str1 = din.readUTF();  
		System.out.println("Server says: "+str1);
		
		str2 = br.readLine();  
		dout.writeUTF(str2);  
		dout.flush(); 

		str1 = din.readUTF();  
		System.out.println("Server says: "+str1);
		
		str2 = br.readLine();  
		dout.writeUTF(str2);  
		dout.flush(); 

		dout.close();  
		s.close();

		FileClient fc = new FileClient("10.110.49.159", 1988, "SendFile.txt");  	
	}

}