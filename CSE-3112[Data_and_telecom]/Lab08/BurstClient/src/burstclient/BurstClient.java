package burstclient;
import java.io.*;
import java.net.*;
import java.util.Random;
public class BurstClient {

    public static void main(String[] args) throws IOException{
        FileWriter file = new FileWriter("FileOne");
        Socket client = new Socket("localhost",2200);
        DataInputStream in = new DataInputStream(client.getInputStream());
        DataOutputStream out = new DataOutputStream(client.getOutputStream());
        
        String come="*";
        String result="";

        while(true)
        {
            come = in.readUTF();
            if(come.length() == 1) {
                break;
            }
            boolean willMakeError=false;
            
            Random make = new Random();
            while(true)
            {
             int m = make.nextInt()%2;
             if(m>=0 && m<=1) 
             {
                 if(m==0) willMakeError = false;
                 else willMakeError = true;
                 break;
             }
            }
            
           
            
            //Randomization : I character error 
            Random rand = new Random();
            int v;
            while(true)
            {
                 v = rand.nextInt()%6;
                if(v>=0&&v<=5) break;
            }
            /*IF Want to generate random error*/
            int p = come.charAt(v)-'0';
            char ch;
             willMakeError=false; 
            if(p==0 && willMakeError) 
            {
                ch='1';
                String one="";
                //System.out.println("dhuke + ");
                for(int i=0;i<v;i++)
                {
                    one = one + come.charAt(i);
                }
                one = one+ch;
                //System.out.println("one = " + one);
                for(int i=v+1;i<=5;i++)
                {
                    one = one + come.charAt(i);
                }
                come =one;
            }
            else if(p==1 && willMakeError)
            {
                ch='0';
                String one="";
                //System.out.println("dhuke " );
                for(int i=0;i<v;i++)
                {
                    one = one + come.charAt(i);
                }
                one = one+ch;
                //System.out.println("one = " + one);
                for(int i=v+1;i<=5;i++)
                {
                    one = one + come.charAt(i);
                }
                come =one;   
            }
           
            System.out.println("The string which came = " + come);
            int p1 = (come.charAt(0)-'0') + (come.charAt(2) - '0') + (come.charAt(4)-'0');
            p1 = p1 % 2;
            int p2 = (come.charAt(1)-'0') + (come.charAt(3) - '0') + (come.charAt(5)-'0');
            p2 = p2 % 2;
            
            String error = "";
            ch = (char)(p1+'0');
            error = error + ch;
            ch = (char)(p2 + '0'); 
            error = error + ch;
            
            
            boolean resend =false;
            System.out.println("Error = " + error);
            if(error.compareTo("00") == 0) 
            {
                System.out.println("NO ERROR");
                for(int i=0;i<=3;i++)
                {
                    result = result + come.charAt(i);
                }
                
            }
            else
            {
                System.out.println("ERROR !! SEND AGAIN");
                resend = true;
            }
            
            if(resend)
            {
                out.writeUTF("0"); // ERROR NEED TO GET AGAIN
            }
            else
            {
                out.writeUTF("1"); //OKAY
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
