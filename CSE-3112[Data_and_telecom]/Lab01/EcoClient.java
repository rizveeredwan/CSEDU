import java.util.*;
import java.io.*;
import java.net.*;


public class EcoClient  {

  public static void main(String[] args) throws IOException {
      String hostName = args[0];
      int portNumber = Integer.parseInt(args[1]);
      try {
         Socket clientSocket = new Socket(hostName,portNumber);
         PrintWriter out = 
         new PrintWriter(clientSocket.getOutputStream(),true);
         BufferedReader in = 
         new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
         BufferedReader stdIn = 
         new BufferedReader(new InputStreamReader(System.in));
         String input;
         while ( (input = stdIn.readLine()) != null ) {
      
           out.println(input);
           System.out.println("Echo : " + in.readLine());       
         }   
      }
      catch(IOException e) {

      }
  }
}  

		
