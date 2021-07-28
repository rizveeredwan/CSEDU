import java.util.*;
import java.net.*;
import java.io.*;

class HashingString {

    int theHashValue(String a, int modNumber) {
      int sum=0;
      int stringLength=a.length();
      for(int i=0;i<=stringLength-1;i++) {
         char character = a.charAt(i);
         sum = sum + (character)%modNumber;
      }
      return sum%modNumber;
    }
}


public class EcoServer2 {

   public static void main(String[] args) throws IOException{
       int portNumber = Integer.parseInt(args[0]);
       try {
         ServerSocket server = new ServerSocket(portNumber);
         Socket clientSocket = server.accept();
         PrintWriter out = 
         new PrintWriter(clientSocket.getOutputStream(),true);
         BufferedReader in = 
         new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
         BufferedReader input = 
         new BufferedReader(new InputStreamReader(System.in));
         String line;
         while(true) {
           line = input.readLine();
           HashingString h = new HashingString();
           int savedValue = h.theHashValue(line,7);
           out.println(line);
           line = in.readLine();
           
           int length = line.length();
            
           int hp=0;
           for(int i=0;i<=length-1;i++) {
              if(line.charAt(i)>='0' && line.charAt(i)>='9') {
                hp = hp * 10 + (int)(line.charAt(i)-'0'); 
              }
           }
           
           if(hp==savedValue) { 
             System.out.println("Data Transfer was ok");
           }
           else {
             System.out.println("The System is Faulty"); 
           }         
         }
         
       }
       catch(IOException e) {
          System.out.println("There was Error");
       }
       System.out.println("Hello");
   }

}
