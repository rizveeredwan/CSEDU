package burstserver;
import java.io.*;
import java.net.*;

import java.io.FileReader;

public class BurstServer {
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
        
        /*We are using burst error detection for two bits"*/
        /*So our data = 4 bits and t = 2 */
        /*total length = 6 bits */
        
        String jakePathabo="";
        for(int j=0;j<90;j++) {
            temp[j] = '0';
        }
       /* Now we will send 6 bits 
          4 data bit
          2 parity bits for burst error length 2 
          suppost Data bit D1 D2 D3 D4
          p1 = D1^D3
          p2 = D2 ^ D4
          and sending [D1 D2 D3 D4] [p1 p2]
        */
        String choose="";
        int positionOfTemp=6;
        for(int j=1; j<=4;j++)
        {
            //Data bits 
            temp[j] = input.charAt(i+j-1);
        }
        //Parity bits
        int sum = (temp[1]-'0') + (temp[3] - '0');
        sum = sum % 2;
        temp[5] = (char)(sum + '0');
        sum = (temp[2]-'0') + (temp[4] - '0');
        sum = sum % 2;
        temp[6] = (char)(sum + '0'); 
        jakePathabo="";   
        for(int j=1;j<=6;j++){
            jakePathabo = jakePathabo + temp[j];
        }
        //The made string 
        System.out.println(jakePathabo);
        out.writeUTF(jakePathabo);
        String getMessage = in.readUTF();
          while(getMessage.compareTo("0") == 0)
          {
              out.writeUTF(jakePathabo); // the accepted message 
          }
        }
        String jakePathabo="*";
        out.writeUTF(jakePathabo);
       }
}
