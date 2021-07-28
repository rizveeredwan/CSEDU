package reliableudpclient;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.nio.ByteBuffer;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ReliableUDPClient {

    
    public static void main(String[] args) throws SocketException, IOException {
        
      FileWriter writer = new FileWriter("output");
      DatagramSocket socket;
      int port = 2200; //the port 
      socket = new DatagramSocket(port); // waiting for communication at this port 
      DatagramPacket packet;
      byte totFileSize[] = new byte[1024];
      packet = new DatagramPacket(totFileSize,totFileSize.length);
      socket.receive(packet);
      int totFileLength = ByteBuffer.wrap(totFileSize).getInt();
      
      String s = "ok"+" "+Long.toString(totFileLength);
      DatagramPacket sendFirstPacket;
      sendFirstPacket = new DatagramPacket(s.getBytes(),s.getBytes().length,packet.getAddress(),packet.getPort());
      socket.send(sendFirstPacket);
      //System.out.println("packet is sent " + packet.getAddress().toString() + " " + packet.getPort());
      socket.setSoTimeout(5000);
      int counter = -1;
      byte data[] = new byte[totFileLength];
      
      while(counter != (totFileLength-1)){
            
          byte buffer[]=new byte[1024];
          DatagramPacket peteChai;
          peteChai = new DatagramPacket(buffer,buffer.length);
          try{
             socket.receive(peteChai); 
             byte number[] = new byte[8];
             byte c[] = new byte[1];
             for(int j=0;j<=7;j++){
                 number[j]=buffer[j];
             }
             c[0]=buffer[8];
             int value = ByteBuffer.wrap(number).getInt();
             if((value-counter)==1) {
               counter++;   
               System.out.println("received " + counter);
               data[counter]=c[0];
               System.out.println(data[counter]);
               
             }
             throw new SocketTimeoutException();
          }        
          catch(SocketTimeoutException e){
               s = "ok"+" "+Integer.toString(counter);
               System.out.println("s = " + s);
               DatagramPacket ack;
               ack = new DatagramPacket(s.getBytes(),s.getBytes().length,packet.getAddress(),packet.getPort());
               socket.send(ack);
          }
      }
      
      FileOutputStream fs = new FileOutputStream("output");
      fs.write(data);
      fs.close();
  }
}
