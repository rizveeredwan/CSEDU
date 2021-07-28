package assignmentthree;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;
import java.nio.file.*;
import java.util.logging.Level;
import java.util.logging.Logger;

class Control extends Thread{
   String fileName;
   byte data[]; //file data 
   int sequenceFieldSize; 
   byte sentData[][]; //the saved data 
   int winStart,winEnd;
   DatagramSocket socket; //datagram socket
   int port;
   InetAddress inetAddress;
   Thread thread;
   boolean received[];
   
   Control(String s) throws SocketException, UnknownHostException, IOException{
       fileName=s;
       int port=3369;
       socket = new DatagramSocket(); //datagram socket connection established 
       inetAddress = InetAddress.getByName("localhost");
       thread = new Thread("receive thread");
       socket.setSoTimeout(5000);
   }
   public void fileRead() throws IOException{
       Path path = Paths.get(fileName); //reading the path 
       data = Files.readAllBytes(path); //reading all the bytes 
       
   }
   public void sequentialDistribution() throws IOException{
       
       
       
       int length=data.length;
       sequenceFieldSize=0;
       while(length != 0){
           sequenceFieldSize++;
           length /= 2;
       }
       sentData = new byte[data.length+5][10];
       received = new boolean[data.length+5];
       for(int i=0;i<data.length;i++){
           received[i]=false;
       }
       for(int i=0;i<data.length;i++){
           //data ke byte e nilam 
           byte c[];
           c= new byte[1];
           c[0]=data[i];
           //converting number to byte array
           byte number[] = new byte[4];
           number[0]=(byte) (i>>24);
           number[1]=(byte) (i>>16);
           number[2]=(byte) (i>>8);
           number[3]=(byte) (i>>0);
           //getting the number 
           int value = ByteBuffer.wrap(number).getInt();
           //for marging two byte arrays
           ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
           outputStream.write(number);
           outputStream.write(c);
           sentData[i]=outputStream.toByteArray();
           //completion of writing into byte array
       }
       
       thread.start();
       winStart=0;
       winEnd=0;
       System.out.println("damn");
   }
   public void pathao(int st,int en) throws IOException{
      for(int i=st;i<=winEnd && i <= en;i++){
         DatagramPacket packet;
         System.out.println("Ei");
         packet = new DatagramPacket(sentData[i],sentData[i].length,inetAddress,port); //made packet
         socket.send(packet);
      }  
   }
   public void run(){
      
      while(true){
         DatagramPacket receivePacket;
         byte array[] = new byte[4];
         receivePacket = new DatagramPacket(array,array.length);
          try {
              socket.receive(receivePacket);
              int number=ByteBuffer.wrap(array).getInt();
              if(number == 0){
                  received[number]=true;
                  continue;
              }
              else {
                  for(int i=number;i>-1;i--){
                      if(received[i]==false){
                          received[i]=true;
                      }
                      else {
                          break;
                      }
                  }
              }
              
           } 
           catch (SocketTimeoutException e) {
               System.out.println("Time out exception.Threads been resumed.");
               for(int i=winStart;i<data.length ;i+=1){
                   if(received[i] == true) {
                       winStart++;
                   }
                   else {
                       break;
                   }
               }
               if(winStart>=data.length){
                   break;
               }
               else {
                try {
                       pathao(winStart,winStart+5);
                   } catch (IOException ex) {
                       System.out.println("problem in pathao");
                   }
               }
               continue;
           } 
           catch (IOException ex) {
              System.out.println("IOError");
          }
          
   }
}
}


public class AssignmentThree {

    
    public static void main(String[] args) throws IOException {
            Control control = new Control("input");
            control.fileRead();
            control.sequentialDistribution();
            control.pathao(control.winStart, control.winEnd);
    }
    
}
