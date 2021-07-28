package synctdmclient;
import java.io.*;
import java.net.*;

public class SyncTDMClient {
    public static void main(String[] args) throws IOException {
       Socket client = new Socket("localhost",2200);
       BufferedReader read = new BufferedReader(
               new InputStreamReader(client.getInputStream()));
       
       FileWriter file1 = new FileWriter("FileOne"); //opening file objects
       FileWriter file2 = new FileWriter("FileTwo");
       FileWriter file3 = new FileWriter("FileThree");
       FileWriter file4 = new FileWriter("FileFour");
       FileWriter file5 = new FileWriter("FileFive");
       
       PrintWriter write1 = new PrintWriter(file1);
       PrintWriter write2 = new PrintWriter(file2);
       PrintWriter write3 = new PrintWriter(file3);
       PrintWriter write4 = new PrintWriter(file4);
       PrintWriter write5 = new PrintWriter(file5);
       
       String msg="";
       int c;
       while((c=read.read())!= -1) {
           msg = msg + (char)c;
       }
       System.out.println(msg);
       int flag=1;
       int counter=0;
       for(int i=0;i<msg.length();i++){
           counter++; 
           if(flag==1){
               if(counter%6==0){
                   flag++;
               }
               String str="";
               str = str + msg.charAt(i);
               String str1="";
               str1 = str1 + '#';
               
               if(str.compareTo(str1) == 0) continue;
               
               file1.write(msg.charAt(i));
              // System.out.print(msg.charAt(i));
               
           }
           else if(flag==2){
               if(counter%6==0){
                   flag++;
               }
               String str="";
               str = str + msg.charAt(i);
               String str1="";
               str1 = str1 + '#';
               
               
               if(str.compareTo(str1) == 0) continue;

               
               file2.write(msg.charAt(i));
              // System.out.print(i);
           }
           else if(flag==3){
               if(counter%6==0){
                   flag++;
               }
                String str="";
                str = str + msg.charAt(i);
                String str1="";
                str1 = str1 + '#';
                
                if(str.compareTo(str1) == 0) continue;
                
                file3.write(msg.charAt(i));
               // System.out.print(i);
       
           }
           else if(flag == 4){ 
               if(counter%6==0){
                   flag++;
               }
                
                String str="";
                str = str + msg.charAt(i);
                String str1="";
                str1 = str1 + '#';
                
                if(str.compareTo(str1) == 0) continue;
                
                file4.write(msg.charAt(i));
                //System.out.print(i);
               //}
               }
               
           else if(flag == 5) {
               if(counter%6==0){
                   flag = 1;
               }
               
               String str="";
               str = str + msg.charAt(i);
               String str1="";
               str1 = str1 + '#';
               
               if(str.compareTo(str1) == 0) continue;
               
               file5.write(msg.charAt(i));
              // System.out.print(i);
               
           }
       }
       file1.close();
       file2.close();
       file3.close();
       file4.close();
       file5.close();
       
      client.close();
      
    }
    
}
