import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;
import java.util.logging.Level;
import java.util.logging.Logger;


interface SentenceGenerator {
    
    public void addWord(String s);
    public String wordChange(String s);
    public String makeLine();
    public String FileMakeLine();

}

class OSG implements SentenceGenerator {
    public int sizeVoc;
    public int wordNum;
    List<String> dic = new ArrayList<String>();
    public OSG(){
        this.sizeVoc=2;
        //default
       this.dic.add("okay");
       this.dic.add("i");
       System.out.println("please user give the size of OSG");
       Scanner scan = new Scanner(System.in);
       this.sizeVoc=scan.nextInt();
       System.out.println("Dictionary size been updated.Some words are by default in your dictionary");
       System.out.println("Please Give Max length of your sentence:(word number just)");
       this.wordNum=scan.nextInt();
    }
    public void addWord(String s){
       s=wordChange(s);
       if(this.dic.size()<this.sizeVoc){
       this.dic.add(s);
       for(int i=0;i<this.dic.size();i++){
           System.out.println(this.dic.get(i));
       }
       }
       else {
        System.out.println("more words exceeding the capability of dictionary size.");          
      }
    }
    public String wordChange(String s){
        String temp = s.toUpperCase();
        char prac[]=temp.toCharArray();
        for(int i=0;i<temp.length()/2;i++){
            char ch = prac[i];
            char ch1 = prac[temp.length()-1-i];
            prac[i]=ch1;
            prac[temp.length()-1-i]=ch;
        }
        int length=temp.length();
        temp="";
        for(int i = 0; i<length;i++){
            temp=temp+prac[i];
        }
        return temp;
    }
    public String makeLine(){
        List<Integer> tempo = new ArrayList<Integer>();
        System.out.println("Please give how many words do you want in your sentence.You are in OSG, max word number in line " + wordNum);
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        if(number>this.wordNum){
            System.out.println("defined word number is lesser.");
            number=this.wordNum;
        }
        String sentence="";
        int length=dic.size();
        Random rand = new Random();
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length);
            tempo.add(v);
        }
        Collections.sort(tempo);
        for(int i=0;i<tempo.size();i++){
            
            String temp = dic.get(tempo.get(i));
            if(i == 0){
                sentence = temp;
            }
            else {
                  sentence=sentence+" "+temp;
            }
        }
        return sentence;
    }
    public String FileMakeLine(){
        List<Integer> tempo = new ArrayList<Integer>();
       
        int number = this.wordNum;
        if(number>this.wordNum){
            System.out.println("defined word number is lesser.");
            number=this.wordNum;
        }
        String sentence="";
        int length=dic.size();
        Random rand = new Random();
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length);
            tempo.add(v);
        }
        Collections.sort(tempo);
        for(int i=0;i<tempo.size();i++){
            
            String temp = dic.get(tempo.get(i));
            if(i == 0){
                sentence = temp;
            }
            else {
                  sentence=sentence+" "+temp;
            }
        }
        return sentence;
    }
}

class RSG implements SentenceGenerator{
    
    public int sizeVoc;
    public int wordNum;
    List<String> dic = new ArrayList<String>();
    public RSG(){
        this.sizeVoc=2;
        //default
       this.dic.add("RIZVEE");
       this.dic.add("SDP");
       this.dic.add("SP");
       System.out.println("please user give the size of RSG");
       Scanner scan = new Scanner(System.in);
       this.sizeVoc=scan.nextInt();
       System.out.println("Dictionary size been updated.Some words are by default in your dictionary");
       System.out.println("Please Give Max length of your sentence:(word number just)");
       this.wordNum=scan.nextInt();
    }
    public void addWord(String s){
      s=this.wordChange(s);
      //System.out.println(s);
      if(this.dic.size()<this.sizeVoc){
       this.dic.add(s);
       System.out.println("Words been added in the list.");
       for(int i=0;i<this.dic.size();i++){
           System.out.println(this.dic.get(i));
       }
    }
      else {
        System.out.println("more words exceeding the capability of dictionary size.");          
      }
    }
    public String wordChange(String s){
      return s.toUpperCase();
    }
    public String makeLine(){
        System.out.println("Please give how many words do you want in your sentence.You are in RSG, max word number in line " + wordNum);
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        if(number>this.wordNum){
            System.out.println("defined word number is lesser.");
            number=this.wordNum;
        }
        String sentence="";
        int length=dic.size();
        Random rand = new Random();
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length);
            String temp = dic.get(v);
                if(i == 1){
                    sentence=temp;
                }
                else {
                    sentence = sentence + " " + temp;
                }
        }
        return sentence;
    }
    public String FileMakeLine(){
       
        int number = this.wordNum;
        if(number>this.wordNum){
            System.out.println("defined word number is lesser.");
            number=this.wordNum;
        }
        String sentence="";
        int length=dic.size();
        Random rand = new Random();
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length);
            String temp = dic.get(v);
                if(i == 1){
                    sentence=temp;
                }
                else {
                    sentence = sentence + " " + temp;
                }
        }
        return sentence;
    }
}
class IOSSG implements SentenceGenerator{
       public int sizeVoc;
       public int wordNum;
       List<String> dic = new ArrayList<String>();
    public IOSSG(){
       this.sizeVoc=2;
        //default
       this.dic.add("okay");
       this.dic.add("i");
       this.dic.add("am");
       this.dic.add("here");
       System.out.println("please user give the size of IOSSG");
       Scanner scan = new Scanner(System.in);
       this.sizeVoc=scan.nextInt();
       System.out.println("Dictionary size been updated.Some words are by default in your dictionary");
       System.out.println("Please Give Max length of your sentence:(word number just)");
       this.wordNum=scan.nextInt();
    }
    public void addWord(String s){
       s=wordChange(s);
       if(this.dic.size()<this.sizeVoc){
       this.dic.add(s);
       }
       else {
        System.out.println("more words exceeding the capability of dictionary size.");          
      }
    }
    public String wordChange(String s){
        return s.toLowerCase();
    }
    public String makeLine(){
        List<String> tempo = new ArrayList<String>();
        System.out.println("Please give how many words do you want in your sentence.You are in IOSSG, max word number in line " + wordNum);
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        if(number>this.wordNum){
            System.out.println("defined word number is lesser.");
            number=this.wordNum;
        }
        String sentence="";
        int length=dic.size();
        Random rand = new Random();
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length);
            String temp = dic.get(v);
            tempo.add(temp);
        }
        Collections.sort(tempo);
        for(int i=1;i<tempo.size();i+=2){
          Collections.swap(tempo, i, i-1);
        }
        for(int i=0;i<tempo.size();i++){
            
            String temp = tempo.get(i);
            
            if(i == 0){
                sentence = temp;
            }
            else {
                  sentence=sentence+" "+temp;
            }
        }
        return sentence;
    }
    public String FileMakeLine(){
        List<String> tempo = new ArrayList<String>();
        int number = this.wordNum;
        if(number>this.wordNum){
            System.out.println("defined word number is lesser.");
            number=this.wordNum;
        }
        String sentence="";
        int length=dic.size();
        Random rand = new Random();
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length);
            String temp = dic.get(v);
            tempo.add(temp);
        }
        Collections.sort(tempo);
        for(int i=1;i<tempo.size();i+=2){
          Collections.swap(tempo, i, i-1);
        }
        for(int i=0;i<tempo.size();i++){
            
            String temp = tempo.get(i);
            
            if(i == 0){
                sentence = temp;
            }
            else {
                  sentence=sentence+" "+temp;
            }
        }
        return sentence;
    }
}
class Context {
    SentenceGenerator s;
    
    public void addingWord(SentenceGenerator temp,String given){
        s=temp;
        s.addWord(given);
    }
    public String makingLine(SentenceGenerator temp){
        s=temp;
        String line = s.makeLine();
        return line;
    }
}
class Vocabulary extends Thread {
  
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
public class Vocabulary09 {

    public static void main(String[] args) throws IOException {
        int flag=0;
        System.out.println("First making vocabulary of RSG");
        RSG rsg = new RSG();
        //for(int i=0;i<)
        System.out.println("First making vocabulary of IOSSG");
        IOSSG iossg = new IOSSG();
        System.out.println("First making vocabulary of OSG");
        OSG osg = new OSG();
        Context context=new Context();
        Vocabulary vocabulary = new Vocabulary();
        vocabulary.addSentenceGenerator(rsg);
        vocabulary.addSentenceGenerator(iossg);
        vocabulary.addSentenceGenerator(osg);
        vocabulary.start();
        File creat = new File("Dictionary.txt");
        creat.createNewFile();
        while(flag == 0){
            
            System.out.println("Give 1 For adding word");
            System.out.println("Give 2 For having line");
            System.out.println("Give 3 to add in common buffer");
            System.out.println("Give 0 to exit.");
            Scanner scan = new Scanner(System.in);
            int v = scan.nextInt();
            if(v == 0){
                System.out.println("bye");
                if(vocabulary.special != null)vocabulary.special.interrupt();
                break;
            }
            if(v == 3){
                System.out.println("adding in common buffer");
                scan.nextLine();
                vocabulary.addInBuffer();
            }
            else {
             System.out.println("Give 1 For RSG, 2 for IOSSG, 3 for OSG");
            int u = scan.nextInt();
            SentenceGenerator sg = null;
            if(u==1) sg=rsg;
            if(u==2) sg=iossg;
            if(u==3) sg=osg;
            
            if(v==1){
                scan.nextLine();
                String s = scan.nextLine();
                context.addingWord(sg,s);
            }
            else if(v == 2){
                String s=context.makingLine(sg);
                System.out.println("made line = "+s);
            }    
            } 
        }
    }
    
}

