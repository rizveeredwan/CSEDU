package assignmentthreeclient;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

class ControlClient{
     String fileName;
     DatagramSocket socket;
     DatagramPacket packet;
     int port;
     public ControlClient(String s) throws SocketException, IOException{
         fileName = s;
         port=3369;
         socket = new DatagramSocket(port);
         byte firstPacket[] = new byte[1024];
         packet = new DatagramPacket(firstPacket,firstPacket.length);
         System.out.println("ase");
         socket.receive(packet);
         String get = new String(firstPacket,0,firstPacket.length);
         System.out.println(get);
     }     
}

public class AssignmentThreeClient {

    public static void main(String[] args) throws IOException {
        ControlClient control = new ControlClient("input");
    }
    
}
