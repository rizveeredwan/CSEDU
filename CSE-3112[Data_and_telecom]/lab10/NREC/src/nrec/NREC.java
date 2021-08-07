package nrec;
import java.net.*;
import java.io.*;
import java.util.Random;


public class NREC {

    public static void main(String[] args) throws IOException{
        FileWriter f = new FileWriter("FileOne.txt");
        Socket socket = new Socket("localhost",2200);
        DataInputStream in = new DataInputStream(socket.getInputStream());
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        
        String come="";
        int lineCounter = -1;
        String temp="";
        while(true)
        {
            come = in.readUTF();
            lineCounter++;
            if(come.length() == 1) break;
            else
            {
                String number = "";
                boolean first = false;
                String ch="";
                //System.out.println(come + " asche ");
                
                //The Random Function For probabilistic calculation 
                /*Random r = new Random();
                int choice = r.nextInt()%16;
                if(choice<0) choice *= -1;
                String special = Integer.toString(choice);
                out.writeUTF(special);
                */
               for(int i=0;i<come.length();i++)
               {
                   ch= ""+come.charAt(i);
                   if(ch.compareTo("*")==0)
                   {
                       first = true;
                       continue;
                   }
                   if(first==false)
                   {
                       number = number + come.charAt(i);
                   }
                   else
                   {
                       temp = temp + come.charAt(i);
                   }
               }
               //System.out.println("lala ");
               int lala = Integer.parseInt(number);
              // System.out.println("lala = " + lala);
               if(lala == lineCounter)
               {
                   lineCounter++;
                   lineCounter = lineCounter % 16;
                   String pathabo= Integer.toString(lineCounter);
                   out.writeUTF(pathabo);
               }
               else
               {
                   lineCounter = lineCounter % 16;
                   String pathabo= Integer.toString(lineCounter);
                   out.writeUTF(pathabo);
               }
            }
            
        }
        System.out.println(temp);
        for(int i=0;i<temp.length();i++)
        {
            f.write(temp.charAt(i));
             f.flush();
        }
       
        System.out.println("BREAK");

    }
    
}
