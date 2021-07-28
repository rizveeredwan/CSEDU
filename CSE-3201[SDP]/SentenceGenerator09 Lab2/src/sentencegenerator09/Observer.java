package sentencegenerator09;

import java.util.*;

public class Observer {
   
   List<String> sharedBuffer = new ArrayList<String>(); 
   List<SentenceGenerator> object = new ArrayList<SentenceGenerator>();
   public Observer(){
   }
   void addSentenceGenerator(SentenceGenerator s){
       object.add(s);
   }
   void addInBuffer(String s){
     this.sharedBuffer.add(s); 
     this.notification(s);
   }
   void notification(String s){
       for(int i=0;i<object.size();i++){
           object.get(i).addWord(s);
       }
   }
}
  
