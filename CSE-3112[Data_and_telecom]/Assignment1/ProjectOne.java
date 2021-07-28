
import java.io.*;
import java.net.*;
import java.util.Random;

public class ProjectOne {

    public static void main(String[] args) {
      String hostName = args[0];
      int portNumber = Integer.parseInt(args[1]);
      try {
        Socket clientSocket = new Socket(hostName,portNumber);
         FileReader file = new FileReader("input.txt");
        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(),true);
         BufferedReader stdIn = new BufferedReader(file);
         String line;
         while ( (line = stdIn.readLine()) != null ) {
           System.out.println(line);   
           char[] stringToCharArray = line.toCharArray();
           int len = line.length();
           for(int i=0;i<len;i++) {
               int value = stringToCharArray[i];
               String test = Integer.toBinaryString(value);
               int tempVal2 = value << 1;
               int p = tempVal2;
               int count = 0;
               value = value << 1;
               while(p != 0) {
                   count += p % 10;
                   p /= 10;
               }
               if(count % 2==1) { 
                    value = value | 1;
                   
               }
               else {
                   value = value | 0;
               }
               test = Integer.toBinaryString(value);
               out.println(test);
           }
           out.println("10100");  
         }
          
      }
      catch(IOException e) {
         System.out.println("There was Error.");
      }        
     }
    
}

