package datagramclient;
import java.io.*;
import java.net.*;

public class DatagramClient {

    
    public static void main(String[] args) throws UnknownHostException, SocketException, IOException {
       DatagramSocket socket=null;
       int port=2200;
       //initialization 
       socket = new DatagramSocket();
       InetAddress host=InetAddress.getByName("localhost");
       
       BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
       String number = in.readLine();
       byte buffer[]=number.getBytes();
       DatagramPacket packet=new DatagramPacket(buffer,buffer.length,host,port);
       socket.send(packet);
       System.out.println("Message been sent from client");   
       
       int counterOfMsg=Integer.parseInt(number);
       int counter=0;
       socket.setSoTimeout(1000);
       
       byte joss[] = new byte[65500];
       DatagramPacket asche=new DatagramPacket(joss,joss.length);
       socket.receive(asche);
       byte accept[] = asche.getData();
       String check=new String(accept,0,asche.getLength());
       System.out.println(check); 
       
       while(counter<counterOfMsg){
           
           System.out.println("please give line:");
           String line=in.readLine();
           DatagramPacket lastPacket=new DatagramPacket(line.getBytes(),line.getBytes().length,host,port);
           socket.send(lastPacket);
           long sendTime=System.currentTimeMillis();
           try{
             byte buff[]=new byte[1024];
             DatagramPacket income=new DatagramPacket(buff,buff.length);
             socket.receive(income);
             long receiveTime=System.currentTimeMillis();
             byte came[]=income.getData();
             String s = new String(came,0,income.getLength());
             System.out.println(s); 
             System.out.println("message took time " + (receiveTime-sendTime) + "milli seconds");
           }
           catch(SocketTimeoutException e){
               System.out.println("Message not been sent.");
               System.out.println(line);
           }
           counter += 1; 
           
       }
       
    }
    
}
