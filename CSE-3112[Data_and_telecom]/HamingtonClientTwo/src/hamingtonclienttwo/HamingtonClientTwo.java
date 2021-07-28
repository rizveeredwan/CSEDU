package hamingtonclienttwo;
import java.io.*;
import java.net.*;

public class HamingtonClientTwo {

   
    public static void main(String[] args) throws IOException{
        FileWriter file = new FileWriter("FileOne");
        Socket client = new Socket("localhost",2200);
        DataInputStream in = new DataInputStream(client.getInputStream());
        
        String come="*";
        String result="";
        
        while(true) {
            come = in.readUTF();
            if(come.length() == 1) {
                break;
            }
            char temp[] = new char[50];
            char tempP[] = new char[50];
            
            for(int i=0;i<=30;i++)
            {
                temp[31-i]=come.charAt(i);
            }
            //Generating the error 
            for(int i=31;i>=1;i--)
            {
                if(i != 1 && i != 2 && i != 4 && i != 8 && i != 16)
                {
                    result = result + temp[i];
                }
            }
            String Error="";
            
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
            
            int v = sum % 2;
            char ch = (char)(v + '0');
            Error = ch + Error;
        }
        System.out.println("the bit error string = " + Error);    
        }
        System.out.println(result);
        for(int i=0;i<result.length();i += 8)
        {
            if(result.length()-i<8) break;
            else {
                String binaryString="";
                for(int j=i;j<i+8;j++)
                {
                    binaryString = binaryString + result.charAt(j);
                }
                int value = Integer.parseInt(binaryString,2);
                if(value == 0) continue;
                char ch = (char)value;
                //System.out.println(ch);
                file.write(ch);
                file.flush();
            }
        }
    }
    
}
