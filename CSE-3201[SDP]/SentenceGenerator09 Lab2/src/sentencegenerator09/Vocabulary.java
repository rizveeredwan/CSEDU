package sentencegenerator09;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Vocabulary extends Thread {
  
   List<String> sharedBuffer = new ArrayList<String>(); 
   List<SentenceGenerator> object = new ArrayList<SentenceGenerator>();
   Scanner scan;
   Thread special;
   boolean flag;
   public Vocabulary() throws FileNotFoundException, IOException{
    scan = new Scanner(System.in);
    FileReader reader = new FileReader("Dictionary.txt");
    BufferedReader buff = new BufferedReader(reader);
    String line="";
    
    while((line=buff.readLine()) != null){
        if(line != null){
            if(line.length()>0){
                sharedBuffer.add(line);
            }
        }
    }
    flag=true;
   }
   void addSentenceGenerator(SentenceGenerator s){
       object.add(s);
   }
   void addInBuffer() throws IOException{
     String s = scan.nextLine();
     boolean ok=false;
     if(!ok){
       for(int i=0;i<object.size();i++){
           System.out.println("New Vocabulary being added");
           object.get(i).addWord(s);
       }
     }
   }
   void notification(String s){
       for(int i=0;i<object.size();i++){
           System.out.println("New Vocabulary being added");
           object.get(i).addWord(s);
           System.out.println("New line being made"); 
           String line = object.get(i).FileMakeLine(); 
           System.out.println(line);
       }
   }
   public void run(){
     while(!interrupted()){
        
         FileReader reader;
         try {
             reader = new FileReader("Dictionary.txt");
             BufferedReader buff = new BufferedReader(reader);
             List<String>newEle=new ArrayList<String>();
             String line="";
    
             while((line=buff.readLine()) != null){
            if(line != null){
            if(line.length()>0){
                newEle.add(line);
            }
            }
            }
             buff.close();
             reader.close();
             boolean changed=false;
            for(int i=0;i<newEle.size();i++){
              String one= newEle.get(i);
              boolean ok=false;
            for(int j=0;j<sharedBuffer.size();j++){
                 String two=sharedBuffer.get(j);
                 if(one.equals(two)){
                     ok=true;
                     break;
                 }
            }
            if(!ok){
                changed=true;
                flag=true;
                this.notification(one);
            }
          }
          if(changed){
            int length=sharedBuffer.size();
            while(length !=0){
                sharedBuffer.remove(0);
                length--;
            }
            for(int i=0;i<newEle.size();i++){
                String s = newEle.get(i);
                sharedBuffer.add(s);
            }
          }
          else {
            int length=sharedBuffer.size();
            while(length !=0){
                sharedBuffer.remove(0);
                length--;
            }
            for(int i=0;i<newEle.size();i++){
                String s = newEle.get(i);
                sharedBuffer.add(s);
            }    
          }
          
         }
         catch (FileNotFoundException ex) {
             Logger.getLogger(Vocabulary.class.getName()).log(Level.SEVERE, null, ex);
         } catch (IOException ex) {
             Logger.getLogger(Vocabulary.class.getName()).log(Level.SEVERE, null, ex);
         }
     }  
   }
   public void start(){
       special = new Thread(this,"fileCheakingThread");
       special.start();
   }
}
