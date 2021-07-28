package hamingtonclienttwo;
import java.io.*;
import java.net.*;
import java.math.*;
import java.util.Random;

public class HamingtonClientTwo {

   
    public static void main(String[] args) throws IOException{
        FileWriter file = new FileWriter("FileOne");
        Socket client = new Socket("localhost",2200);
        DataInputStream in = new DataInputStream(client.getInputStream());
        DataOutputStream out = new DataOutputStream(client.getOutputStream());
        
        String come="*";
        String result="";
         int clc = Integer.parseInt("11000110101",2);
        while(true) {
            come = in.readUTF();
            if(come.length() == 1) {
                break;
            }
            char temp[] = new char[50];
            char tempP[] = new char[50];
            
            int extraBitSum=0;
            
            //Calculation for Randomization 
            //Generating the random position 
            boolean randomization = false;
            int indexChoosing=0;
            while(!randomization)
            {
            Random r = new Random();
            indexChoosing = r.nextInt()%8;
            if(indexChoosing == 3 || indexChoosing == 5 || indexChoosing == 6 
                   || indexChoosing == 7) 
              {
                randomization=true;
              }
            }
            
            
            
            //saving into the temp array for calculation
            for(int i=0;i<=7;i++)
            {
                temp[7-i]=come.charAt(i);
            }
            
            //Performing the error making the error Willingly 
            if(temp[indexChoosing] == '0')
            {
                System.out.println("Making error in ghor " + indexChoosing);
                temp[indexChoosing] = '1';
            }
            else 
            {
                System.out.println("Making error in ghor " + indexChoosing);
                temp[indexChoosing] = '0';
            }
            
            boolean extraBit=false;
            //now checking the extra bit is okay or not
            int extraSum = 0;
            for(int i=7;i>=0;i--)
            {
                int v1 = temp[i]-'0';
                extraSum += v1;
            }
            extraSum = extraSum % 2;
            if(extraSum == 0) extraBit = true;
            else extraBit = false;
            
            
            //Checking the error parity bit 
            String Error="";
            
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
            
            int v = sum % 2;
            char ch = (char)(v + '0');
            Error = ch + Error;
        }
        boolean resend = false;
        System.out.println("the bit error string = " + Error + " And Extra Bit " + extraBit);    
        if(extraBit == true && Error.compareTo("000")== 0)
        {
            System.out.println("NO ERROR");
            for(int i=7;i>=1;i--)
            {
                if(i != 1 && i != 2 && i != 4)
                {
                    result = result + temp[i];
                }
            }    
        
        }
        else if(extraBit == true && Error.compareTo("000") != 0)
        {
            System.out.println("Double bit error detected.");
            resend = true;
        }
        else if(extraBit == false && Error.compareTo("000") != 0)
        {
            System.out.println("Single Bit error detected.");
            int v = Integer.parseInt(Error,2);
            int now = temp[v]-'0';
            now = (now + 1)%2;
            temp[v] = (char)(now + '0');
            System.out.println("Error at position " + v);
            for(int i=7;i>=1;i--)
            {
                if(i != 1 && i != 2 && i != 4)
                {
                    result = result + temp[i];
                }
            }    
        }
        else 
        {
             System.out.println("unambiguous error. Need to send data again");
             resend = true;
        }
        if(resend)
        {
            out.writeUTF("0");
        }
        else 
        {
            out.writeUTF("1");
        }
        
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
