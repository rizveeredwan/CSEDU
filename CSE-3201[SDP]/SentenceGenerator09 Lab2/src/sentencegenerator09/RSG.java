package sentencegenerator09;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class RSG implements SentenceGenerator{
    
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
