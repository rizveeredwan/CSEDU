package sentencegenerator09;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*; 

/*import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.locks.AbstractOwnableSynchronizer;

interface SentenceGenerator {
    List<String> dic = new ArrayList<String>();
    public void addWord(String s);
    public String wordChange(String s);
    public String makeLine();
}

class RSG implements SentenceGenerator{
    
    public int sizeVoc;
    public int wordNum;
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
      RSG.dic.add(s);
    }
    public String wordChange(String s){
      return s.toUpperCase();
    }
    public String makeLine(){
        System.out.println("Please give how many words do you want in your sentence.You are in RSG, max word number in line " + wordNum);
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        String sentence="";
        int length=dic.size();
        Random rand = new Random();
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length-1);
            String temp = dic.get(v);
            if(i == number){
                sentence=sentence+temp;
            }
            else {
                if(i == 1){
                    sentence=temp+" ";
                }
                else {
                    sentence = sentence + " "+temp;
                }
            }
        }
        return sentence;
    }
}


class IOSSG implements  SentenceGenerator{
       public int sizeVoc;
       public int wordNum;
    public IOSSG(){
       this.sizeVoc=2;
        //default
       this.dic.add("okay");
       this.dic.add("i ");
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
    }
    public String wordChange(String s){
        return s.toLowerCase();
    }
    public String makeLine(){
        List<String> tempo = new ArrayList<String>();
        System.out.println("Please give how many words do you want in your sentence.You are in IOSSG, max word number in line " + wordNum);
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        String sentence="";
        int length=dic.size();
        Random rand = new Random(length);
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length-1);
            String temp = dic.get(v);
            tempo.add(temp);
        }
        Collections.sort(tempo);
        for(int i=1;i<tempo.size();i+=2){
          Collections.swap(tempo, i, i-1);
        }
        for(int i=0;i<tempo.size();i++){
            
            String temp = tempo.get(i);
            if(i==number-1){
                sentence = sentence+temp;
            }
            else if(i == 0){
                sentence = temp+" ";
            }
            else {
                  sentence=sentence+temp+" ";
            }
        }
        return sentence;
    }
}

class OSG implements  SentenceGenerator {
    public int sizeVoc;
    public int wordNum;
    public OSG(){
        this.sizeVoc=2;
        //default
       this.dic.add("okay");
       this.dic.add("i ");
       System.out.println("please user give the size of OSG");
       Scanner scan = new Scanner(System.in);
       this.sizeVoc=scan.nextInt();
       System.out.println("Dictionary size been updated.Some words are by default in your dictionary");
       System.out.println("Please Give Max length of your sentence:(word number just)");
       this.wordNum=scan.nextInt();
    }
    public void addWord(String s){
       s=wordChange(s);
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
        temp=prac.toString();
        return temp;
    }
    public String makeLine(){
        List<Integer> tempo = new ArrayList<Integer>();
        System.out.println("Please give how many words do you want in your sentence.You are in OSG, max word number in line " + wordNum);
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        String sentence="";
        int length=dic.size();
        Random rand = new Random();
        for(int i=1;i<=number;i++){
            int v = rand.nextInt(length-1);
            tempo.add(v);
        }
        Collections.sort(tempo);
        for(int i=0;i<tempo.size();i++){
            
            String temp = dic.get(tempo.get(i));
            if(i==number-1){
                sentence = sentence+temp;
            }
            else if(i == 0){
                sentence = temp+" ";
            }
            else {
                  sentence=sentence+temp+" ";
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
*/


public class SentenceGenerator09 {

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
