import java.net.*;  
import java.io.*; 
import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class FileServer extends Thread {
	
	private ServerSocket ss;

	private void saveFile(Socket clientSock) throws IOException {
		DataInputStream dis = new DataInputStream(clientSock.getInputStream());
		FileOutputStream fos = new FileOutputStream("output.txt");
		byte[] buffer = new byte[4096];
		
		int filesize = 15123; // Send file size in separate msg
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
	
	public static void main(String[] args) throws Exception{
		ss = new ServerSocket(1988);  
		Socket s = ss.accept();  
		DataInputStream din=new DataInputStream(s.getInputStream());  
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
  
		String str="",str2="";  
		while(!str.equals("stop")){  
			str=din.readUTF();  
			System.out.println("client says: "+str);  
			str2=br.readLine();  
			dout.writeUTF(str2);  
			dout.flush();  
		}

		saveFile(s);  
		din.close();  
		s.close();  
		ss.close();  
	}

}