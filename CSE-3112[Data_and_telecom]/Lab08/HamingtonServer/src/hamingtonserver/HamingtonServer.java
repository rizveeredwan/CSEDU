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
       DataInputStream in = new DataInputStream(socket.getInputStream());
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
       for(int i=0;i<input.length();i += 4) {
        char temp[] = new char[100];
        /*if((input.length()-i)<26) 
        {
            int v = 26 -(input.length() - i);
           
            for(int j = 1;j<=v;j++)
            {
                input = input + '0';
            }
        }*/
        
        String jakePathabo="";
        for(int j=0;j<90;j++) {
            temp[j] = '0';
        }
       /* Now we will send 8 bits 
          4 data bit
          3 previous parity bits
          and overall one extra parity bit
        */
        String choose="";
        int positionOfTemp=7;
      
        for(int j = i;j<i+4;j++) {
            while(positionOfTemp == 1 || 
                    positionOfTemp == 2 ||
                     positionOfTemp == 4 
                     ) 
            {
                     temp[positionOfTemp]='0';
                     positionOfTemp--;
                    
            }
            temp[positionOfTemp]= input.charAt(j);
            positionOfTemp--;
           
        }
        
        //Choosing the error bits 
        for(int j=0;j<=2;j++) // we will take power 2^0, 2^1,2^2
        {
            int sum = 0;
            
            for(int k=(1<<j);k<=7; k += (1<<(j+1))) // choosing the first positions  
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
        int sum=0;
        for(int j=7;j>=1;j--){
            jakePathabo = jakePathabo + temp[j];
            int v1=temp[j]-'0';
            sum += v1;
        }
        sum = sum % 2;
        char ch= (char)(sum+'0');
        jakePathabo = jakePathabo + ch;
        System.out.println(jakePathabo);
        out.writeUTF(jakePathabo);
        String getMessage = in.readUTF();
          while(getMessage.compareTo("0") == 0)
          {
              out.writeUTF(jakePathabo);
          }
        }
        String jakePathabo="*";
        out.writeUTF(jakePathabo);
       }
      
    
}
