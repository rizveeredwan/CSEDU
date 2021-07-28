package udp;

import java.io.*;
import java.net.*;


public class UDP {

    public static void main(String[] args) throws SocketException, IOException {
        
        //declaration
        DatagramSocket socket;
        DatagramPacket packet;
        int port=2200;
        
        //initialization
        socket = new DatagramSocket(port);
        byte temp[] = new byte[1024];
        packet = new DatagramPacket(temp,temp.length);
        
        //taking the value of n
        socket.receive(packet); 
        byte incoming[]=packet.getData();
        String inco=new String(incoming,0,packet.getLength());
        
        int numberOfMsg= Integer.parseInt(inco);
        System.out.println(numberOfMsg);
        String sendMsg="OK 0";
        DatagramPacket secondPacket=new DatagramPacket(sendMsg.getBytes(),sendMsg.getBytes().length,packet.getAddress(),packet.getPort());
        socket.send(secondPacket);
        
        int counterOfMsg=0;
        socket.setSoTimeout(10000);
        boolean ok=true;
        while(ok && counterOfMsg<numberOfMsg){
            
            try{
                 socket.receive(packet);
                 byte[] olitia=packet.getData();
                 String msg=new String(olitia,0,olitia.length);
                 System.out.println(msg);
                 ok=true;
                 counterOfMsg++;
                 String number = Integer.toString(counterOfMsg);
                 String line = "OK " + number;
                 System.out.println(line.getBytes().length);
                 DatagramPacket lastPacket=new DatagramPacket(line.getBytes(),line.getBytes().length,packet.getAddress(),packet.getPort());
                 socket.send(lastPacket);           
            }
            catch(SocketTimeoutException e){
                ok=false;
                System.out.println("Server received " + counterOfMsg + " messages");
                break; 
            }
            
        }
        
    }
    
}
