package stattdmserver;
import java.io.*;
import java.net.*;

public class StatTdmServer {
    public static void main(String[] args) throws IOException {
       ServerSocket server = new ServerSocket(2200); //opening server socket
       Socket socket = server.accept(); //the medium socket
       
       PrintWriter out = new PrintWriter(socket.getOutputStream(),true); //the output medium
       BufferedReader extreme = new BufferedReader(new InputStreamReader(socket.getInputStream())); 
       
       FileReader file1 = new FileReader("FileOne"); //opening file objects
       FileReader file2 = new FileReader("FileTwo");
       FileReader file3 = new FileReader("FileThree");
       FileReader file4 = new FileReader("FileFour");
       FileReader file5 = new FileReader("FileFive");
       
       BufferedReader read1 = new BufferedReader(file1); //scanners to read files 
       BufferedReader read2 = new BufferedReader(file2);
       BufferedReader read3 = new BufferedReader(file3);
       BufferedReader read4 = new BufferedReader(file4);
       BufferedReader read5 = new BufferedReader(file5);
       
       int definedCharNumber = 6; //The Frame size 
       int totalChar = 6*5; //total frame character size
       
       boolean done1=false,done2=false,done3=false,done4=false,done5=false;
      
       
       while(true) {
         
           if(done1==true && 
              done2== true && 
              done3 == true &&
              done4 == true && 
              done5 == true) break;
              
               String jakePathabo="*"; //The string which will be sent
               int charCounter=0;
               while(charCounter!=6){
                 int c = read1.read();
                 if(c== -1) {
                     charCounter++;
                     done1 = true;
                     break;
                 }
                 else {
                    charCounter++;
                    jakePathabo = jakePathabo + (char)c;
                 }
             }
             jakePathabo = jakePathabo + "*"; //1st file read complete 
             
             jakePathabo = jakePathabo + "*"; // 2nd file read start 
             
             charCounter = 0;
             while(charCounter!=6){
                 int c = read2.read();
                 if(c== -1) {
                     charCounter++;
                     done2 = true;
                     break;
                 }
                 else {
                    jakePathabo = jakePathabo + (char)c;
                    charCounter++;
                 }
             }
             
             jakePathabo = jakePathabo + "*"; // 2nd file read complete 
             
             jakePathabo = jakePathabo + "*"; // 3rd file read start 
             
             charCounter = 0;
             while(charCounter!=6){
                 int c = read3.read();
                 if(c== -1) {
                     charCounter++;
                     done3 = true;
                     break;
                 }
                 else {
                     charCounter++;
                     jakePathabo = jakePathabo + (char)c;
                 }
             }
             jakePathabo = jakePathabo + "*"; // 3rd file read complete 
             
             jakePathabo = jakePathabo + "*"; // 4th file read start
             
             charCounter = 0;
             while(charCounter!=6){
                 int c = read4.read();
                 if(c== -1) {
                     charCounter++;
                     done4 = true;
                     break;
                 }
                 else {
                     charCounter++;
                     jakePathabo = jakePathabo + (char)c;
                 }
             }
             jakePathabo = jakePathabo + "*"; // 4th file read complete
             
             jakePathabo = jakePathabo + "*"; // 5th file read start 
             charCounter = 0;
             while(charCounter!=6){
                 int c = read5.read();
                 if(c== -1) {
                     charCounter++;
                     done5 = true;
                     break;
                 }
                 else {
                     charCounter++;
                     jakePathabo = jakePathabo + (char)c;
                 }
             }
             jakePathabo = jakePathabo + "*"; // 5th file read complete
             
             System.out.println(jakePathabo);
              out.print(jakePathabo);
       }             

        read1.close();
        read2.close();
        read3.close();
        read4.close();
        read5.close();
        
        out.close();
        extreme.close();
        socket.close();
        server.close();       
         
     
    }
    
}
