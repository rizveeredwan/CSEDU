package sentencegenerator09;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;


public class OSG implements SentenceGenerator {
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
