import java.net.*;  
import java.io.*;  
import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerFileReceived extends Thread {

	private ServerSocket ss;
	
	public ServerFileReceived(String fileName, int fileSize, int port) {
		try {
			ss = new ServerSocket(port);
			saveFile(ss.accept(), fileName, fileSize);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void saveFile(Socket clientSock, String fileName, int filesize) throws IOException {
		DataInputStream dis = new DataInputStream(clientSock.getInputStream());
		FileOutputStream fos = new FileOutputStream("output.txt");
		byte[] buffer = new byte[4096];
		
		int read = 0;
		int totalRead = 0;
		int remaining = filesize;
		while((read = dis.read(buffer, 0, Math.min(buffer.length, remaining))) > 0) {
			totalRead += read;
			remaining -= read;
			System.out.println("read " + totalRead + " bytes.");
			fos.write(buffer, 0, read);
		}
		
		fos.close();
		dis.close();
	}
	
	public static void main(String args[])throws Exception{  

		ServerSocket ss = new ServerSocket(5555);  
		Socket s = ss.accept();  
		DataInputStream din=new DataInputStream(s.getInputStream());  
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
  
		String str;
		System.out.println("Server question: ");
		str =br.readLine();  
		dout.writeUTF(str);  
		dout.flush();  
  
		String fileName = din.readUTF();  
		System.out.println("Client reply: "+fileName); 

		System.out.println("Server question: ");
		str =br.readLine();  
		dout.writeUTF(str);  
		dout.flush(); 
  
		str = din.readUTF();  
		System.out.println("Client reply: "+str ); 
		int fileSize = Integer.parseInt(str);
		
		ServerFileReceived fs = new ServerFileReceived(fileName, fileSize, 5555);
		din.close();  
		s.close();  
		ss.close();  
	}  
}