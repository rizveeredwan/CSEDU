import java.util.*;
import java.io.*;
import java.net.*;


class HashingString {

    int theHashValue(String a, int modNumber) {
      int sum=0;
      int stringLength=a.length();
      for(int i=0;i<=stringLength-1;i++) {
         char character = a.charAt(i);
         sum = sum + (character)%modNumber;
      }
      return sum;
    }
}


public class EcoClient2 {

  public static void main(String[] args) throws IOException {
       String hostName = args[0];
       int portNumber = Integer.parseInt(args[1]);
       try {
         Socket socket = new Socket(hostName,portNumber);
         PrintWriter out = 
         new PrintWriter(socket.getOutputStream(),true);
         BufferedReader in = 
         new BufferedReader(new InputStreamReader(socket.getInputStream()));    
         String found;
         while((found = in.readLine()) != null) {
           HashingString h = new HashingString();
           int value = h.theHashValue(found,7);
           System.out.println("Asche vai : " ); 
           String s="";  
           while(true) {
             int rem = value % 10;
             char c = (char)(rem + '0') ;
             s = s + c;
             value /= 10;
             if(value==0) break;                 
           }
           int len= s.length()-1;
           for(int i=0;i<=len/2;i++) {
             char ch= s.charAt(i);
             //s.charAt(i) = s.charAt(s.length()-1-i);
             s.charAt(s.length()-1-i) = ch;
             
           }
           out.println(found+s);           
         }
       }
       catch(Exception e) {
       System.out.println("There is Error in client");
       }
       System.out.println("Process is running very well");
  } 
}
