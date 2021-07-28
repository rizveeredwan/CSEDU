package sentencegenerator09;

public class Context {
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
