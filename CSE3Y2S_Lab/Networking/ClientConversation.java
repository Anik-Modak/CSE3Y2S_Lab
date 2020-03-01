import java.net.*;  
import java.io.*; 
import java.util.*; 

class ClientConversation{  
	public static void main(String args[])throws Exception{  

	Socket s = new Socket("localhost", 5555);
	Scanner scan = new Scanner(System.in);
	DataInputStream dataIn = new DataInputStream(s.getInputStream());
	DataOutputStream dataOut = new DataOutputStream(s.getOutputStream());

	while(true){
		System.out.print("Type Your Message : ");
                	String sentMessage = scan.nextLine();
                	dataOut.writeUTF(sentMessage);
                	if(sentMessage.equals("EXIT")) 
			break;
                	String receivedMessage = dataIn.readUTF();
                	System.out.println("Server's Reply : " + receivedMessage);
	}
	s.close();
	}
}