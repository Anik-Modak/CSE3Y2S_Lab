import java.io.*;
import java.net.*;
import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
  
class ServerConversation{  
	public static void main(String args[])throws Exception{  

	ServerSocket ss = new ServerSocket(5555);
	Socket s = ss.accept();

	DataInputStream dataIn = new DataInputStream(s.getInputStream());
	DataOutputStream dataOut = new DataOutputStream(s.getOutputStream());
	DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("dd-MMM-YYYY");
	DateTimeFormatter timeFormatter = DateTimeFormatter.ofPattern("h:mm a");

	while(true){
		String message = dataIn.readUTF();
		if(message.equals("EXIT"))
			 break;
		else if(message.equals("Hello")) 
			dataOut.writeUTF("Welcome");
		else if(message.equals("Date")){
			LocalDate date = 	LocalDate.parse(LocalDate.now().toString()); 	
			dataOut.writeUTF(dateFormatter.format(date));
		}
		else if(message.equals("Time")){
			LocalTime time = 	LocalTime.parse(LocalTime.now().toString());
 			dataOut.writeUTF(timeFormatter.format(time));
		}
		else if(message.equals("DateTime")){
			LocalDate date = 	LocalDate.parse(LocalDate.now().toString()); 	
			LocalTime time = 	LocalTime.parse(LocalTime.now().toString());
 			dataOut.writeUTF("Time : "+timeFormatter.format(time)+"\t"+"Date : "+dateFormatter.format(date));
		}
		else dataOut.writeUTF("Please Send Valid Message");
	}
	
	s.close();
	ss.close();
	}
}