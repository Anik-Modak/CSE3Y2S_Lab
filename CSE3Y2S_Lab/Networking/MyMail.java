import java.io.*;
import java.net.*;

public class MyMail {
    public static void main(String[] args ) throws Exception{
        String server = "localhost";
        int port = 25;
        String from= "anikmail@modak.com";
        String to = "happymail@modak.com";
        Socket socket = new Socket(server, port);
        PrintWriter os = new PrintWriter(socket.getOutputStream(),true);
        BufferedReader bReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        
        System.out.println("HELO " + InetAddress.getLocalHost().getHostName());
        os.println("HELO "+"modak.com");
        System.out.println("Response1: "+bReader.readLine());
        
        System.out.println("MAIL From:<" + from + ">");
        os.println("MAIL From:<" + from + ">");
        System.out.println("Response 2: "+bReader.readLine());
        
        System.out.println("RCPT TO:<" + to + ">");
        os.println("RCPT TO:<" + to + ">");
        System.out.println("Response 3: "+bReader.readLine());
        
        System.out.println("DATA");
        os.println("DATA");
        System.out.println("Response 4: "+bReader.readLine());
        
        os.println("From: anikmail@modak.com");
        os.println("To: happymail@modak.com");
        os.println("Subject: VU Programming Contest");
	os.println();
        os.println("Hi Happy, VU programming contest will be held on 15th December.");
       
        System.out.println("Send");
        os.println(".");
        System.out.println("Response 5: "+bReader.readLine());
        
        System.out.println("QUIT");
        os.println("QUIT");
        System.out.println("Response 6: "+bReader.readLine());
	
	System.out.println("Goodbye");
	System.out.println("Response 7: "+bReader.readLine());
    }
}

