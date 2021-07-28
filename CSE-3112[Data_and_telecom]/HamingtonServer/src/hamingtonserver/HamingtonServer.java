package hamingtonserver;
import java.io.*;
import java.net.*;

import java.io.FileReader;

public class HamingtonServer {
    public static void main(String[] args) throws FileNotFoundException, IOException {
       FileReader file = new FileReader("FileOne");
       ServerSocket server = new ServerSocket(2200);
       Socket socket = server.accept();
       DataOutputStream out = new DataOutputStream(socket.getOutputStream());
       
       String input="";
       while(true) {
           int ch = file.read();
           System.out.println(ch);
           if(ch == -1) {
               
               break;
           }
           String binaryString = Integer.toBinaryString(ch);
          
           while(binaryString.length()<8) {
              binaryString = '0' + binaryString;
           }
          
           input = input+binaryString;
          
       }
       System.out.println(input + " " + input.length());
       for(int i=0;i<input.length();i += 26) {
        char temp[] = new char[100];
        if((input.length()-i)<26) 
        {
            int v = 26 -(input.length() - i);
           
            for(int j = 1;j<=v;j++)
            {
                input = input + '0';
            }
        }
        
        String jakePathabo="";
        for(int j=0;j<90;j++) {
            temp[j] = '0';
        }
        /*Now to detect 2 bit errors we need to have extra 5 bits 
        according to the theory of 2*errorBit + 1 
        Now to calculate 5 extra bits we will need 16 bits
        so this time our array will be 26+5 = 31 bits -
        */
        //Choosing the 26 bits from the input stream
        String choose="";
        int positionOfTemp=31;
      
        for(int j = i;j<i+26;j++) {
            while(positionOfTemp == 1 || 
                    positionOfTemp == 2 ||
                     positionOfTemp == 4 ||
                     positionOfTemp == 8 ||
                     positionOfTemp == 16) 
            {
                     temp[positionOfTemp]='0';
                     positionOfTemp--;
                    
            }
            temp[positionOfTemp]= input.charAt(j);
            positionOfTemp--;
           
        }
        
        //Choosing the error bits 
        for(int j=0;j<=4;j++) // we will take power 2^0, 2^1,2^2,2^3,2^4
        {
            int sum = 0;
            
            for(int k=(1<<j);k<=31; k += (1<<(j+1))) // choosing the first positions  
            {
                int power = 1<<j;
                for(int l=k;l<k+power;l++)  //looping 2^jth numbers 
                   {
                       int v = temp[l]-'0';
                       sum += v;
                       
                   }
            
            }
            System.out.println();
            int v = sum % 2;
            char ch = (char)(v + '0');
            temp[1<<j]  = ch;
        }
 
        jakePathabo="";       
        for(int j=31;j>=1;j--){
            jakePathabo = jakePathabo + temp[j];
        }
        System.out.println(jakePathabo);
        System.out.println();
        System.out.println(jakePathabo);
        out.writeUTF(jakePathabo);  
        }
        String jakePathabo="*";
        out.writeUTF(jakePathabo);
       }
      
    
}
