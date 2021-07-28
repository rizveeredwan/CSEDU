package fptree;

import java.util.HashMap;
import java.util.Map;

public class PatternMining {
    Map<String,PatternMining>child = new HashMap<String,PatternMining>();
    int count;
    String item;
    FpTree parent;
    boolean takenNode;
    PatternMining(){
        parent=null;
        item="";
        count=0;
        takenNode=false;
    }
    void init(FpTree tree,PatternMining patternTree){
        
    }
}
