package sentencegenerator09;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;


public class IOSSG implements SentenceGenerator{
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
