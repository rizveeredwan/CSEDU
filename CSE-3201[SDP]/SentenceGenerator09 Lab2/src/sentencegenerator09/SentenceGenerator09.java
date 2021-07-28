package sentencegenerator09;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*; 






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
        while(flag == 0){
            
            System.out.println("Give 1 For adding word");
            System.out.println("Give 2 For having line");
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
