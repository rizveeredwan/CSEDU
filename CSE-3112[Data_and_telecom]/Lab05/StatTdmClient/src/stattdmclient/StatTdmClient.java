package stattdmclient;
import java.io.*;
import java.net.*;



public class StatTdmClient {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
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
       int flag=0;
       System.out.println(msg);
       for(int i=0;i<msg.length(); i++) {
           if(msg.charAt(i) == '*') {
               flag++;
               if(flag==10) flag=0;
               continue;
           }
           if(flag==1) { // work of first file 
               write1.print(msg.charAt(i));
           }
           else if(flag==3) { // work of second file 
               write2.print(msg.charAt(i)); 
           }
           else if(flag == 5) { // work of third file 
                write3.print(msg.charAt(i));
           }
           else if(flag == 7) { //work of fourth file 
                write4.print(msg.charAt(i));
           }
           else if(flag==9) { // work of fifth file 
              write5.print(msg.charAt(i));   
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
    

