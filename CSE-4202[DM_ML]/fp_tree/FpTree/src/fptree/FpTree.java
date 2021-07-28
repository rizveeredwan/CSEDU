package fptree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

//each row in header table 
class Item{
    String item; 
    int count;
    ArrayList<FpTree>link=new ArrayList<FpTree>();
    public Item(){
       item="";
    }
}

//To compare two Item
class CompareItem implements Comparator<Item>{

    public int compare(Item o1, Item o2) {
       
       if(o1.count<o2.count)return 1;
       if(o1.count>o2.count)return -1;
       if(o1.count == o2.count){
           if(o1.item.compareTo(o2.item)<0) return -1;
           if(o1.item.compareTo(o2.item)>0) return 1;
           return 0;
       }
       return 0;
    }
    
}

//header table 
class HeaderTable{
   ArrayList<Item>headerTable = new ArrayList<Item>();
   Map<String,Integer>M = new HashMap<String,Integer>();
   
   //function to initiate header table
   void init(Database db,int minimumSupportCount){
       for(int i=0;i<db.transactions.size();i++){
           for(int j=0;j<db.transactions.get(i).size();j++){
               if(M.containsKey(db.transactions.get(i).get(j))){
                   //if already inserted in header table
                   int index = M.get(db.transactions.get(i).get(j));
                   headerTable.get(index).count++;
               }
               else{
                   Item object=new Item();
                   object.item=db.transactions.get(i).get(j);
                   object.count=1;
                   headerTable.add(object);
                   M.put(db.transactions.get(i).get(j), headerTable.size()-1);
               }
           }
       }
       Collections.sort(headerTable, new CompareItem());
       M.clear();
       //taking the items which satisfy minimum support count 
       ArrayList<Item>tempHeaderTable = new ArrayList<Item>();
       for(int i=0;i<headerTable.size();i++){
           if(headerTable.get(i).count>=minimumSupportCount){
               tempHeaderTable.add(headerTable.get(i));       
           }
           else break;
       }
       headerTable = tempHeaderTable;
       for(int i=0;i<headerTable.size();i++){
           M.put(headerTable.get(i).item, i);
       }
       return;
   }
   //function to print header table 
   void printHeaderTable(){
       for(int i=0;i<headerTable.size();i++){
           System.out.println("Item = "+headerTable.get(i).item+" Count = "+headerTable.get(i).count+" link = "+headerTable.get(i).link.size());
       }
   }
}


class PatternInformation{
    String pattern;
    int freqency;
}

class GlobalCounter{
    int value;
}


//class fp tree 
public class FpTree {
    
    Map<String,FpTree>child = new HashMap<String,FpTree>();
    int count;
    String item;
    FpTree parent;
    boolean takenNode;
    boolean lastNode;
    
    public FpTree(){
        parent=null;
        takenNode=false;
        lastNode=false;
        item="";
    }
    
    public static void main(String[] args) {
       Database database = new Database();
       //database.loadDatabase("chess.txt");
       database.loadDatabase("mushroom.txt"); 
       
       double minimumSupport = Math.ceil((20/100.0)*database.transactions.size());
       int minimumSupportCount = (int)minimumSupport;
       
       HeaderTable headerTable = new HeaderTable();
       headerTable.init(database,minimumSupportCount);
       //headerTable.printHeaderTable();
       database.sortDatabase(headerTable, minimumSupportCount);
       //debug: database.printDatabase();
       //adding into tree
       double time1 = System.currentTimeMillis();
       FpTree tree=new FpTree();
       for(int i=0;i<database.transactions.size();i++){
           tree.addTransaction(tree, 0, database.transactions.get(i),headerTable);
       }
       //debug: tree.printFpTree(tree); 
       //debug: headerTable.printHeaderTable();
       
       //pattern Information section 
       
       HeaderTable headerTable2 = new HeaderTable();
       FpTree copy=new FpTree();
       copy.copyFpTree(tree, copy, headerTable2);
       
       ArrayList<PatternInformation>generatedPatterns=new ArrayList<PatternInformation>();
       
       GlobalCounter countCpb=new GlobalCounter();
       countCpb.value=0;
       
       for(int i=headerTable2.headerTable.size()-1;i>=0;i--){
           
         copy.patternMining(copy,headerTable2.headerTable.get(i).link,"",headerTable2,minimumSupportCount,generatedPatterns,countCpb);
           
           
           //System.out.println(headerTable2.headerTable.get(i).item);
           //System.out.println("DDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
       }
       
       System.out.println("pattern Genertation Completed");
       System.out.println("size = "+generatedPatterns.size());
       System.out.println("Counter Conditional Pattern Base "+countCpb.value);
       /*for(int i=0;i<generatedPatterns.size();i++){
           System.out.println(generatedPatterns.get(i).pattern+" "+generatedPatterns.get(i).freqency);
       }*/
       double time2 = System.currentTimeMillis();
       System.out.println((time2-time1)/1000);
    }
    
    
    //function to generate pattern
    void patternMining(FpTree tree,ArrayList<FpTree>lastNodes,String made,HeaderTable h,int minSupCnt,ArrayList<PatternInformation>generatedPatterns,GlobalCounter countCpb){
         
       
        
        //debug: System.out.println("main string "+made+" last node size = "+lastNodes.size());
        //frequency checking
        int count = 0;
        for(int i=0;i<lastNodes.size();i++){
            count += lastNodes.get(i).count;
        }
        String madeAlready="";
        if(made.length() == 0){
            madeAlready=lastNodes.get(0).item;
        }
        else{
            madeAlready=made+","+lastNodes.get(0).item;
        }
        
        
        if(count >= minSupCnt){
            //frequent item sets 
            PatternInformation temp=new PatternInformation();
            temp.pattern=madeAlready;
            temp.freqency = count;
            generatedPatterns.add(temp);
        }
        
        
        //generating conditional prefix tree 
        HeaderTable headerTableCpb = new HeaderTable(); 
        FpTree cpb=makeConditionalPatternBase(tree,lastNodes,headerTableCpb);
        
        //modify headerTable
        HeaderTable updated = sortHeaderTable(headerTableCpb,minSupCnt);
        HeaderTable base=updated;
        
        FpTree prefixTree=null;
        HeaderTable headertablePrefixTree=null;
        if(updated.headerTable.size() != headerTableCpb.headerTable.size()){
            //have to make new prefix tree, some nodes got deleted 
            prefixTree = new FpTree();
            headertablePrefixTree=new HeaderTable();
            Map<String,Boolean>valid=new HashMap<String,Boolean>();
            for(int i=0;i<updated.headerTable.size();i++){
                valid.put(updated.headerTable.get(i).item, true);
            }
            makePrefixTree(cpb,prefixTree,valid,headertablePrefixTree);
        }
        else{
            //cpb and prefix tree are same
            prefixTree = cpb;
            headertablePrefixTree=headerTableCpb;
        }
        countCpb.value++;
        boolean singlePath = singlePathChecking(prefixTree);
        
        if(singlePath==true){
           ArrayList<String>takenItems=new ArrayList<String>();
           ArrayList<Integer>takenItemsFreq = new ArrayList<Integer>();
           genereatePatternsFromSingleBranch(prefixTree,takenItems,takenItemsFreq,madeAlready,count,generatedPatterns,minSupCnt);
        }
        else{
            for(int i=0;i<headertablePrefixTree.headerTable.size();i++){
               patternMining(prefixTree,headertablePrefixTree.headerTable.get(i).link,madeAlready,headertablePrefixTree,minSupCnt,generatedPatterns,countCpb);
            }
        }
                
    }
    
    void genereatePatternsFromSingleBranch(FpTree tree,ArrayList<String>takenItems,ArrayList<Integer>takenItemsFreq,String baseString,int baseStringFreq,ArrayList<PatternInformation>generatedPatterns,int minSupC){
       
        boolean nonLeaf=true;
        for(Map.Entry<String,FpTree>key : tree.child.entrySet()){
            nonLeaf=false;
            //taken
            takenItems.add(key.getKey());
            takenItemsFreq.add(key.getValue().count);
            genereatePatternsFromSingleBranch(key.getValue(),takenItems,takenItemsFreq,baseString,baseStringFreq,generatedPatterns,minSupC);
        
            //not taken
            int sz=takenItems.size()-1;
            takenItems.remove(sz);
            takenItemsFreq.remove(sz);
            genereatePatternsFromSingleBranch(key.getValue(),takenItems,takenItemsFreq,baseString,baseStringFreq,generatedPatterns,minSupC);
        }
        if(nonLeaf){
            if(takenItems.size() > 0){
                String s="";
                int minFreq=1000000000;
                for(int i=0;i<takenItems.size();i++){
                    if(s.length() == 0){
                        s=takenItems.get(i);
                    }
                    else{
                        s=s+","+takenItems.get(i);
                    }
                }
                for(int i=0;i<takenItemsFreq.size();i++){
                    minFreq=Math.min(minFreq,takenItemsFreq.get(i));
                }
                s=s+","+baseString;
                minFreq = Math.min(minFreq,baseStringFreq);
                
                if(minFreq >= minSupC){
                    PatternInformation temp=new PatternInformation();
                    temp.pattern=s;
                    temp.freqency=minFreq;
                    generatedPatterns.add(temp);
                }
            }
        }
        return; 
    }
    
    
    boolean singlePathChecking(FpTree tree){
        int cnt=0;
        boolean result=true;
        for(Map.Entry<String,FpTree>key : tree.child.entrySet()){
            cnt++;
            if(cnt>1) return false;
            result = result & singlePathChecking(key.getValue());
        }
        return result;
    }
    
    //function to make prefix tree from cpb
    void makePrefixTree(FpTree tree,FpTree prefixTree,Map<String,Boolean>valid,HeaderTable h){
        for(Map.Entry<String,FpTree>key : tree.child.entrySet()){
            if(valid.containsKey(key.getKey())){
                //this string is valid to take
                if(prefixTree.child.containsKey(key.getKey())){
                    //going down
                    prefixTree.child.get(key.getKey()).count += tree.child.get(key.getKey()).count;
                    h.headerTable.get(h.M.get(key.getKey())).count += tree.child.get(key.getKey()).count;
                    makePrefixTree(tree.child.get(key.getKey()),prefixTree.child.get(key.getKey()),valid,h);
                    
                }
                else{
                    //child creation
                    FpTree temp = new FpTree();
                    temp.count=0;
                    temp.item=key.getKey();
                    temp.parent=prefixTree;
                    
                    //link 
                    prefixTree.child.put(key.getKey(),temp);
                    
                    //update into header 
                    if(!h.M.containsKey(key.getKey())){
                         Item item =new Item();
                         item.count=0;
                         item.item=key.getKey();
                         h.headerTable.add(item);
                         h.M.put(item.item, h.headerTable.size()-1);
                         
                    }
                    
                    h.headerTable.get(h.M.get(key.getKey())).link.add(temp);
                    
                    h.headerTable.get(h.M.get(key.getKey())).count += tree.child.get(key.getKey()).count;
                    
                    prefixTree.child.get(key.getKey()).count += tree.child.get(key.getKey()).count;
                    makePrefixTree(tree.child.get(key.getKey()),prefixTree.child.get(key.getKey()),valid,h);
                }
            }
            else{
                //bypass
                makePrefixTree(tree.child.get(key.getKey()),prefixTree,valid,h);
            }
        }
        
    }
    
    //function is to sort header table and delete redundant data 
    HeaderTable sortHeaderTable(HeaderTable h,int minSupCnt){
        HeaderTable updated=new HeaderTable();
        for(int i=0;i<h.headerTable.size();i++){
            if(h.headerTable.get(i).count >= minSupCnt){
                updated.headerTable.add(h.headerTable.get(i));
            }
        }
        Collections.sort(updated.headerTable,new CompareItem());
        for(int i=0;i<updated.headerTable.size();i++){
            updated.M.put(updated.headerTable.get(i).item, i);
        }
        
        return updated;
    }
    
    //function to makke conditional pattern base
    FpTree makeConditionalPatternBase(FpTree tree,ArrayList<FpTree>lastNodes,HeaderTable h){
      
      flagChangeNode(tree,lastNodes,true);
      FpTree cpb = new FpTree();
      
      //make conditional pattern base
      treeConditionalPatternBase(tree,cpb,h);
      flagChangeNode(tree,lastNodes,false); 
      
      
      return cpb;
      
    }
    
    void treeConditionalPatternBase(FpTree tree,FpTree cpb,HeaderTable h){
        for(Map.Entry<String,FpTree>key : tree.child.entrySet()){
            if(key.getValue().takenNode==true){
                if(cpb.child.containsKey(key.getKey())){
                    //if cpb has child for this string
                    treeConditionalPatternBase(tree.child.get(key.getKey()),cpb.child.get(key.getKey()),h);
                    if(cpb.parent != null){
                        //not root
                        cpb.count += cpb.child.get(key.getKey()).count;
                        int index = h.M.get(cpb.item);
                        h.headerTable.get(index).count += cpb.child.get(key.getKey()).count;
                    }
                }
                else{
                    FpTree temp = new FpTree();
                    temp.count=0;
                    temp.item=key.getKey();
                    temp.parent=cpb;
                    
                    //update into parent
                    cpb.child.put(key.getKey(),temp);
                    
                    //update into header
                    if(h.M.containsKey(key.getKey()) == false){
                        Item item =new Item();
                        item.count=0;
                        item.item=key.getKey();
                        h.headerTable.add(item);
                        h.M.put(item.item, h.headerTable.size()-1);    
                    }
                    h.headerTable.get(h.M.get(key.getKey())).link.add(temp);
                    
                    //recursion call
                    treeConditionalPatternBase(tree.child.get(key.getKey()),cpb.child.get(key.getKey()),h);
                    
                    if(cpb.parent != null){
                        //not root
                        cpb.count += cpb.child.get(key.getKey()).count;
                        int index = h.M.get(cpb.item);
                        h.headerTable.get(index).count += cpb.child.get(key.getKey()).count;
                    }
                }
            }
            else if(key.getValue().lastNode==true){
                //return the frequency
                int v = key.getValue().count;
                if(cpb.parent != null){
                    cpb.count += v;
                    
                    //update into header
                    int index = h.M.get(cpb.item);
                    h.headerTable.get(index).count += v;
                    
                }
            }
                
        }
    }
    
    //function to change the flags of the node
    void flagChangeNode(FpTree tree,ArrayList<FpTree>lastNodes,boolean flag){
        Queue<FpTree>Q = new LinkedList<FpTree>();
        for(int i=0;i<lastNodes.size();i++){
            lastNodes.get(i).lastNode=flag;
            Q.add(lastNodes.get(i));
        }
        while(Q.isEmpty() != true){
            FpTree u = Q.peek();
            Q.remove();
            if(u.parent != null){
                u.parent.takenNode=flag;
                Q.add(u.parent);
            }
        }
        return;
    }
    
    void addTransaction(FpTree tree,int idx,ArrayList<String>transactions,HeaderTable headerTable){
        
        if(idx>=transactions.size()) {
            return;
        }
        
        if(tree.child.containsKey(transactions.get(idx))){
            tree.child.get(transactions.get(idx)).count++;
            tree.addTransaction(tree.child.get(transactions.get(idx)), idx+1, transactions,headerTable);
        }
        else{
            //child creation
            FpTree branch=new FpTree();
            branch.count=1;
            branch.item=transactions.get(idx); 
            branch.parent=tree;
            //linking part 
            tree.child.put(transactions.get(idx), branch);
            //update in header table
            headerTable.headerTable.get(headerTable.M.get(transactions.get(idx))).link.add(branch);
            //recursion call
            tree.addTransaction(tree.child.get(transactions.get(idx)), idx+1, transactions,headerTable);
        }
        return;
    }
    
    //function to copy fp tree
    void copyFpTree(FpTree base,FpTree copy,HeaderTable newTable){
        Queue<FpTree>Q_base = new LinkedList<FpTree>();
        Queue<FpTree>Q_copy = new LinkedList<FpTree>();
        
        Q_base.add(base);
        Q_copy.add(copy);
         
        while(Q_base.isEmpty() != true){
            FpTree u_base=Q_base.poll();
            FpTree u_copy=Q_copy.poll();
            for(Map.Entry<String,FpTree>key : u_base.child.entrySet()){
                //child node
                FpTree temp=new FpTree();
                temp.count=u_base.child.get(key.getKey()).count;
                temp.item=key.getKey();
                temp.parent=u_copy;
                temp.takenNode=false;
                
                //parent node
                u_copy.child.put(temp.item, temp);
                
                //update in headerTable
                if(newTable.M.containsKey(temp.item)){
                    int index=newTable.M.get(temp.item);
                    newTable.headerTable.get(index).count += temp.count;
                    newTable.headerTable.get(index).link.add(temp);
                }
                else{
                    Item object = new Item();
                    object.count=temp.count;
                    object.item=temp.item;
                    object.link.add(temp);
                    
                    newTable.headerTable.add(object);
                    newTable.M.put(temp.item,newTable.headerTable.size()-1);
                }
                
                Q_base.add(u_base.child.get(key.getKey()));
                Q_copy.add(u_copy.child.get(key.getKey()));
            }
        }
        /*debug
        base.printFpTree(base); 
        System.out.println("done*******************");
        copy.printFpTree(copy);
        System.out.println("done*******************");
        */
        Collections.sort(newTable.headerTable,new CompareItem());
        newTable.M.clear();
        for(int i=0;i<newTable.headerTable.size();i++){
            newTable.M.put(newTable.headerTable.get(i).item,i);
        }
        //debug: newTable.printHeaderTable();
    }
    
    
    
    void printFpTree(FpTree tree){
       
       for(Map.Entry<String,FpTree>key : tree.child.entrySet()){    
           System.out.println("item = "+key.getKey()+" "+tree.child.get(key.getKey()).count);
           tree.printFpTree(tree.child.get(key.getKey()));
       }
       System.out.println("branch end");  
    }
    
    
}
