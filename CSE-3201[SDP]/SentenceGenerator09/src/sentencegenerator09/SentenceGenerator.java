package sentencegenerator09;

import java.util.ArrayList;
import java.util.List;

public interface SentenceGenerator {
    
    public void addWord(String s);
    public String wordChange(String s);
    public String makeLine();
    public String FileMakeLine();
}
