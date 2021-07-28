package assignmenttwoclient;

import java.net.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

class ClientListen extends Thread {
     Client client;
    public ClientListen(Client c) {
        this.client = c;
            
    }
    public void run() {
        String s="";
        while(true) {
            try {
                s = this.client.read.readLine();
                System.out.println(s);
            } catch (IOException ex) {
                Logger.getLogger(ClientListen.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
    }
     
}

class ClientTalk extends Thread {
     Client client;
    public ClientTalk(Client c) {
        this.client = c;
            
    }
    public void run() {
        String s="";
        while(!interrupted()) {
            try {
                s = this.client.console.readLine();
                this.client.print.println(s);
                if(s.compareTo("bye")==0) {
                    this.client.destroyThreads(client);
                }
                
            } catch (IOException ex) {
                Logger.getLogger(ClientListen.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
    }
    
}

class Client {
    String host;
    int port;
    Socket s;
    BufferedReader read;
    BufferedReader console;
    PrintWriter print;
    ClientListen clientListen;
    ClientTalk   clientTalk;
    public Client(String s, int value) {
        host = s;
        port = value;
    }
    
    public void work() throws IOException {
        s = new Socket(host,port);
        read = 
        new BufferedReader(new InputStreamReader(s.getInputStream()));
        console = 
        new BufferedReader(new InputStreamReader(System.in));
        print = new PrintWriter(s.getOutputStream(),true);
        ClientListen clientListen = new ClientListen(this);
        ClientTalk clientTalk = new ClientTalk(this);
        clientListen.start();
        clientTalk.start();
    }
    public void destroyThreads(Client c) throws IOException {
        if(c.clientListen != null) c.clientListen.interrupt();
        if(c.clientTalk != null) c.clientTalk.interrupt();
        s.close(); 
        int variable=0;
        System.exit(variable);
    }
}


public class AssignmentTwoClient {
    public static void main(String[] args) throws IOException {
          String hostName="localhost";
          int portNumber = 2200;
          Client c = new Client(hostName,portNumber);
          c.work();
          
    }
    
}
