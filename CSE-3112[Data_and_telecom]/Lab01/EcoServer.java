import java.io.*;
import java.net.*;
import java.util.*;


public class EcoServer {

  public static void main (String[] args) throws IOException{
       int portNumber = Integer.parseInt(args[0]);
       try {
        ServerSocket server = new ServerSocket(portNumber);
        Socket socketForClient = server.accept();
        PrintWriter out = 
        new PrintWriter(socketForClient.getOutputStream(),true);
        BufferedReader in = 
        new BufferedReader(new InputStreamReader (socketForClient.getInputStream()));
       String Input;
       while((Input = in.readLine()) != null) {
         System.out.println("Came this : " + Input);
         out.println(Input + " <- pathaisi eta ");
       }
       }
       catch(IOException e) {
          System.out.println("There was Error");
       }
  }
}
















