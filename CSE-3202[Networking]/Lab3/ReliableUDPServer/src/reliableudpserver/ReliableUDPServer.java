package reliableudpserver;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import static java.lang.Integer.parseInt;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketTimeoutException;
import java.nio.ByteBuffer;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class ReliableUDPServer {
    
    public static void main(String[] args) throws IOException {
         Scanner scan = new Scanner(System.in);
         String fileName = scan.nextLine(); //the file Name
         
         byte data[];
         Path path = Paths.get(fileName); //reading the path 
         data = Files.readAllBytes(path); //reading all the bytes 

         
         DatagramSocket socket; //the binding socket 
         socket = new DatagramSocket(); //not waiting starting communication 
         DatagramPacket packetFirst; //first Packet 
         InetAddress host = InetAddress.getByName("localhost"); //the host name 
         int port = 2200; //the port 
         int size = data.length;
         
         //sending the file size 
         byte number[]=new byte[8];
         for(int i=0;i<=7;i++){
             number[i]=(byte)(size>>(64-(i+1)*8));
         }
         long test = ByteBuffer.wrap(number).getInt();
         packetFirst = new DatagramPacket(number,number.length,host,port);
         
         socket.setSoTimeout(5000); //timer set 
         boolean ok=true;
         while(ok){
             socket.send(packetFirst);
             try{
               byte buffer[] = new byte[1024];
               DatagramPacket packet = new DatagramPacket(buffer,buffer.length);
               socket.receive(packet);
               System.out.println("packet is received");
               ok=false;
             }
             catch(SocketTimeoutException e){
                 continue;
             }
         }
         
         
         int counter=0;
         while(counter<size){
              byte b[]=new byte[1];
              b[0]=data[counter];
              for(int i=0;i<=7;i++){
                  number[i]=(byte)(counter>>(i+1)*8);
              }
              ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
              outputStream.write(number);
              outputStream.write(b);
              byte pathao[] = outputStream.toByteArray();
              
              DatagramPacket sendPacket = new DatagramPacket(pathao,pathao.length,host,port); 
              socket.send(sendPacket);
              
              try{
               byte buffer[] = new byte[1024];
               DatagramPacket ack = new DatagramPacket(buffer,buffer.length);
               socket.receive(ack);
               byte different[] = ack.getData();
               System.out.println("packet is received");
               String msg= new String(different,0,different.length);
               boolean flag=false;
               String paisi="";
               int realNum=0;
               for(int j=0;j<msg.length();j++){
                   char ch = msg.charAt(j);
                   if(ch == ' ') {
                       flag = true;
                       continue;
                   }
                   if(flag == true){
                        paisi=paisi+msg.charAt(j);
                        realNum = realNum * 10 + (msg.charAt(j)-'0');
                   }
               }
               realNum = 0;
               for(int j=0;j<paisi.length();j++){
                   int v=paisi.charAt(j)-'0';
                   if(v>=0 && v <= 9){
                   realNum = realNum*10+(paisi.charAt(j)-'0');
                   }
               }
               if(realNum == counter){
                   counter++;
               }
               else {
                  continue; 
               }
              }
              catch(SocketTimeoutException e){
                  System.out.println("Socket Time out exception error. at case " + counter);
                  continue;
              }
              
         }
    }
    
}
