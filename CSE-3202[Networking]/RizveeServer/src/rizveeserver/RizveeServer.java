package rizveeserver;

import java.io.*;
import java.net.*;
import java.util.*;

public class RizveeServer {

    public static void main(String[] args) throws IOException{
       ServerSocket rizveeServer = new ServerSocket(8080); //creating server socket 
       //server socket will be accepted
       Socket socket = rizveeServer.accept();
       BufferedReader read = new BufferedReader(new InputStreamReader(socket.getInputStream()));
       String search=read.readLine();
       System.out.println(search);
       
       //first GET word is rejected
       //and from last part HTTP/1.1 is rejected
       int length=search.length();
       String parse="";
       for(int i=4;i<length-9;i++){
           parse=parse+search.charAt(i);
       }
       System.out.println(parse);
       File file = new File(parse);
       
       String httpProtocol="HTTP/1.1 200 OK\r\n\r\n" + "<h1> Welcome to Rizvee's Server </h1> <br/>";
       if(file != null){
           socket.getOutputStream().write(httpProtocol.getBytes());
           byte[] array = new byte[(int)file.length()];
           BufferedInputStream newReader = new BufferedInputStream(new FileInputStream(file));
           newReader.read(array,0, array.length);
           (socket.getOutputStream()).write(array,0,array.length);
           socket.getOutputStream().flush();
           rizveeServer.close();
       }
       else {
        System.out.println("False in parsing.");
       }
       }
    }
   
