import java.io.*;
import java.net.*;
import java.util.*;


public class server1{
  public static void main(String[] args)
{
	
   int portNumber = Integer.parseInt(args[0]);

try{

ServerSocket serverSocket = new ServerSocket(portNumber);

Socket clientSocket = serverSocket.accept();

PrintWriter out = new PrintWriter("output.txt");

BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));


String line;
while((line = in.readLine())!=null){
String s;
int val1=0;
int val = Integer.parseInt(line);
int val2 = val;

while(val2 != 0)
{
	val1 = val1 + val%10;
	val2 = val2/10;
}
	
if(val1%2 == 0)
{
        
        String test="";
        int len=line.length();
        for(int i=0;i<len-1;i++) {
          test = test + line.charAt(i);
        }
        int man = Integer.parseInt(test,2);
        char ch = (char)man;
        out.print(ch);
	out.flush();
}
  
}

}

catch(Exception e)
{
   System.out.println("YAAY, vul :(");
}

}

}

