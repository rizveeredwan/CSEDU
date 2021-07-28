package assignmenttwoserver;
import java.io.*;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

class TalkingListeningThread extends Thread {
    
    MainServer object;
    Client client;
    public TalkingListeningThread(MainServer m,Client c){
        this.object=m;
        this.client=c;
    }
    public void run()  {
        while(!interrupted()) {
            String s;
            int idx=0;
            try {
                s = this.client.read.readLine();
                Socket tempSocket = this.client.s;
                //System.out.println("ase server e = " + s + " connected establishment " + this.object.numberOfClients);
                for(int i=1;i<=this.object.numberOfClients;i++) {
                    if(this.object.connectionList[i] != tempSocket) {
                        PrintWriter p=new PrintWriter(this.object.connectionList[i].getOutputStream(),true);
                        p.println(s);
                    }
                    else {
                        idx=i;
                    }
                }
                if(s.compareTo("bye")==0) {
                    
                    for(int i=idx+1;i<=this.object.numberOfClients;i++) {
                        this.object.connectionList[i-1]=this.object.connectionList[i];
                    }
                    this.object.numberOfClients--;
                    //System.out.println("Remainining  = " + this.object.numberOfClients);
                    this.client.read.close();
                    this.client.out.close();
                    this.client.s.close();
                    this.client.destroyThread(client);
                }
            } catch (IOException ex) {
                Logger.getLogger(TalkingListeningThread.class.getName()).log(Level.SEVERE, null, ex);
            }
            
        }
    }
}

class Client {
    MainServer object;
    Socket s;
    BufferedReader read;
    PrintWriter out;
    TalkingListeningThread talkingListeningThread;
    public Client(MainServer m,Socket s) throws IOException {
        this.object=m;
        this.s= s;
        read = 
        new BufferedReader(new InputStreamReader(s.getInputStream()));
        out = 
        new PrintWriter(s.getOutputStream(),true);  
        talkingListeningThread = new TalkingListeningThread(this.object,this);
    }
    public void work() {
        talkingListeningThread.start();
    }
    public void destroyThread(Client c) throws IOException {
        talkingListeningThread.interrupt();
        Client p;
        p=c;
        p.s.close();
       // System.out.println("Ei porjonto hoi");
    }
}


class MainServer {
    int portNumber;
    Socket connectionList[];
    boolean start;
    int numberOfClients;
    AcceptingClientsThread threadOne;
    ServerSocket server;
    Socket socket;
    public MainServer(int value) throws IOException {
        this.portNumber = value;
        this.connectionList = new Socket[50];
        this.start=false;
        this.numberOfClients=0;
        server = new ServerSocket(this.portNumber);
        threadOne = new AcceptingClientsThread(this);
        threadOne.start();
    }
    public void killThreads() {
        this.threadOne.interrupt();
    }
}

class AcceptingClientsThread extends Thread {
    
    MainServer object;
    Client client;
    public AcceptingClientsThread(MainServer m) {
        this.object = m;
    }
    
    public void run(){
        while(true) {
            try {
               // System.out.println("ase");
                this.object.socket= this.object.server.accept();
               // System.out.println("ase " + this.object.socket);
                boolean found=true;
                for(int i=1;i<this.object.numberOfClients;i++) {
                    if(this.object.socket==this.object.connectionList[i]) {
                        found=false;
                        break;
                    }
                }
                if(found==true) {
                    //if(this.object.start==false) {
                        this.object.start=true;
                        this.object.numberOfClients++;
                        this.object.connectionList[this.object.numberOfClients]= this.object.socket;
                        Client client = new Client(object,this.object.socket);   
                        client.work();
                    //}
                }
            } catch (IOException ex) {
                System.out.println("Error in excepting");
                Logger.getLogger(AcceptingClientsThread.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
}


public class AssignmentTwoServer {
    public static void main(String[] args) throws IOException {
         int portNumber = 2200;
         MainServer m = new MainServer(portNumber);
         
    }
    
}

