package apriori;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

class FrequencyCoded{
    int transactionIdPos;
    int transactionId;
    int freq;
}

class CompareTrie implements Comparator<Trie>{

    public int compare(Trie o1, Trie o2) {
       
       if(o1.pattern.compareTo(o2.pattern)<0) return -1;
       if(o1.pattern.compareTo(o2.pattern)>0) return 1;
       return 0;
    }
    
}

public class Trie {
    Map<String,Trie>M;
    Trie parent;
    int totalFrequency;
    ArrayList<FrequencyCoded>realFreq;
    String symbol;
    int level;
    String pattern;
    public Trie(){
       M=new HashMap<String,Trie>();
       parent=null;
       totalFrequency=0;
       realFreq = new ArrayList<FrequencyCoded>();
       level=0;
    }
    
    //To compare two ItemInfo

    
    void apriori(Database db,Trie root,int minimumSupportCount){
        ArrayList<Trie>latestUpdated=new ArrayList<Trie>();
        ArrayList<ArrayList<String>>moves= new ArrayList<ArrayList<String>>();
        Map<String,Boolean>firstSet = new HashMap<String,Boolean>();
        for(int i=1;;i++){
            
            if(i==1){
                for(int j=0;j<db.transactions.size();j++){
                    for(int k=0;k<db.transactions.get(j).size();k++){
                        String edge = db.transactions.get(j).get(k);
                        if(root.M.containsKey(edge)){
                            Trie branch = M.get(edge);
                            branch.totalFrequency++;
                            FrequencyCoded temp = new FrequencyCoded();
                            temp.freq=1;
                            temp.transactionId=j;
                            temp.transactionIdPos=k;
                            branch.realFreq.add(temp);
                        }
                        else{
                            //child
                            Trie notun = new Trie();
                            notun.parent = root;
                            notun.totalFrequency = 1;
                            FrequencyCoded temp = new FrequencyCoded();
                            temp.freq=1;
                            temp.transactionId=j;
                            temp.transactionIdPos=k;
                            notun.realFreq.add(temp);
                            notun.symbol=edge;
                            notun.level=i;
                            notun.pattern = edge;
                            //link
                            root.M.put(edge, notun);
                            latestUpdated.add(notun);
                        }
                    }
                }
                Collections.sort(latestUpdated, new CompareTrie());
                for(int j=0;j<latestUpdated.size();j++){
                    ArrayList<String>temp=new ArrayList<String>();
                    for(int k=j+1;k<latestUpdated.size();k++){
                        //debug: System.out.print(latestUpdated.get(k).symbol+" ");
                        temp.add(latestUpdated.get(k).symbol);
                    }
                    //debug: System.out.println();
                    moves.add(temp);
                }
                latestUpdated = prunning(latestUpdated,moves,minimumSupportCount,i);
                    /*
                debug: System.out.println("moja");
                    for(int j=0;j<latestUpdated.size();j++){
                        for(int k=0;k<moves.get(j).size();k++){
                            System.out.print(moves.get(j).get(k)+" ");
                        }
                        System.out.println();
                    }
                    System.out.println("hoo");
                    break;*/
                
            }
            else if(i>=2){
                ArrayList<Trie>newPass = new ArrayList<Trie>();
                for(int j=0;j<latestUpdated.size();j++){
                    Trie child = latestUpdated.get(j);
                    for(int k=0;k<child.realFreq.size();k++){
                        FrequencyCoded temp = child.realFreq.get(k);
                        int id = temp.transactionId;
                        int pos=temp.transactionIdPos;
                        for(int l=0;l<moves.get(j).size();l++){
                            String appendEdge = moves.get(j).get(l);
                            int bsValue = binarySearch(appendEdge,id,db);
                            
                            if(bsValue != -1){
                                //add this
                                if(child.M.containsKey(appendEdge)){
                                    Trie branch = child.M.get(appendEdge);
                                    branch.totalFrequency++;
                                    FrequencyCoded f = new FrequencyCoded();
                                    f.transactionId=id;
                                    f.transactionIdPos=bsValue;
                                    f.freq=1;
                                    branch.realFreq.add(f);
                                }
                                else{
                                    Trie branch = new Trie();
                                    branch.parent=child;
                                    branch.totalFrequency=1;
                                    FrequencyCoded f = new FrequencyCoded();
                                    f.transactionId=id;
                                    f.transactionIdPos=bsValue;
                                    f.freq=1;
                                    branch.realFreq.add(f);
                                    branch.symbol=appendEdge;
                                    branch.level=child.level+1;
                                    branch.pattern=child.pattern+","+appendEdge;
                                    //link
                                    child.M.put(appendEdge,branch);
                                    newPass.add(branch);
                                }
                            }
                        }
                    }
                }
                latestUpdated = newPass;
                Collections.sort(latestUpdated,new CompareTrie());
                
                /*debug:if(i==3){
                    System.out.println("moja");
                    for(int j=0;j<latestUpdated.size();j++){
                        System.out.println(latestUpdated.get(j).pattern);
                    }
                    System.out.println("hoo");
                }*/
                
                latestUpdated = prunning(latestUpdated,moves,minimumSupportCount,i);
                /*debug: if(i==3){
                    printPattern(root);
                }*/
                latestUpdated = actualCandidate(latestUpdated,moves);
                if(latestUpdated.size() == 0){
                    break;
                }
                
            }
            System.out.println(i+" length done");
        }
    }
    
    
    int binarySearch(String targetString,int transactionId,Database db){
        int low=0;
        int high = db.transactions.get(transactionId).size()-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(db.transactions.get(transactionId).get(mid).compareTo(targetString) == 0){
                return mid;
            }
            if(db.transactions.get(transactionId).get(mid).compareTo(targetString) > 0){
                high=mid-1;
            }
            if(db.transactions.get(transactionId).get(mid).compareTo(targetString) < 0){
                low=mid+1;
            }
        }
        return -1;
    }
    
    ArrayList<Trie> actualCandidate(ArrayList<Trie>latestUpdated,ArrayList<ArrayList<String>>moves){
        Map<String,Boolean>M = new HashMap<String,Boolean>();
        //debug:System.out.println("map");
        for(int i=0;i<latestUpdated.size();i++){
            M.put(latestUpdated.get(i).pattern,true);
            //debug:System.out.println(latestUpdated.get(i).pattern);
        }
        //debug:System.out.println("map");
        int count=0;
        ArrayList<ArrayList<String>>save = new ArrayList<ArrayList<String>>();
        ArrayList<Trie>finalNodes=new ArrayList<Trie>();
        for(int i=0;i<latestUpdated.size();i++){
            String left[] = latestUpdated.get(i).pattern.split(",");
            ArrayList<String>tempMoves = new ArrayList<String>(); 
            count=0;
            for(int j=i+1;j<latestUpdated.size();j++){
                String right[] = latestUpdated.get(j).pattern.split(",");
                boolean ok = stringArrayCheck(left,right);
                if(ok==true){
                    if(left[left.length-1].compareTo(right[right.length-1])<0){
                        //can be merged
                        String temp=latestUpdated.get(i).pattern+","+right[right.length-1];
                        ok=allSubsetCheck(temp,M);
                        
                        //prune
                        if(ok){
                            count++;
                            tempMoves.add(right[right.length-1]);
                        }
                    }
                }
            }
            if(count>=1){
                  finalNodes.add(latestUpdated.get(i));
                  save.add(tempMoves);
                  //debug: System.out.println("inserted "+count);
            }
        }
        latestUpdated = finalNodes;
        moves = save;
        return finalNodes;
    }
    
    boolean allSubsetCheck(String full,Map<String,Boolean>M){
        String array[] = full.split(",");
        for(int i=0;i<array.length;i++){
          int base=i;
          String temp="";
          for(int j=0;j<array.length;j++){
              if(base != j){
                  if(temp==""){
                      temp=array[j];
                  }
                  else{
                      temp=temp+","+array[j];
                  }
              }
          }
          if(!M.containsKey(temp)){
              return false;
          }
        }
        return true;
    }
    
    boolean stringArrayCheck(String a[],String b[]){
        for(int i=0;i<a.length-1;i++){
            if(a[i].compareTo(b[i]) == 0){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    ArrayList<Trie> prunning(ArrayList<Trie>lastUpdated,ArrayList<ArrayList<String>>moves,int minimumSupportCount,int step){
        ArrayList<Trie>finalNodes=new ArrayList<Trie>();
        ArrayList<ArrayList<String>>tempMoves = new ArrayList<ArrayList<String>>();
        ArrayList<String>forSingleLength = new ArrayList<String>();
        for(int i=0;i<lastUpdated.size();i++){
            if(lastUpdated.get(i).totalFrequency>=minimumSupportCount){
                finalNodes.add(lastUpdated.get(i));
                if(step==1){
                    tempMoves.add(moves.get(i));
                }
                
                
            }
            else{
                lastUpdated.get(i).parent.M.remove(lastUpdated.get(i).symbol);
            }
        }
        if(step==1) {
            moves=tempMoves;
        }
        return finalNodes;
    }
    void printPattern(Trie root){
        Queue<Trie>trieQueue = new LinkedList<Trie>();
        Queue<String>stringQueue = new LinkedList<String>();
        trieQueue.add(root);
        stringQueue.add("");
        ArrayList<ArrayList<String>>pattern = new ArrayList<ArrayList<String>>();
        ArrayList<ArrayList<Integer>>count = new ArrayList<ArrayList<Integer>>();
        while(trieQueue.isEmpty() != true){
            Trie u = trieQueue.poll();
            String v = stringQueue.poll();
            for(Map.Entry<String,Trie>key : u.M.entrySet()){
                Trie child = key.getValue();
                String notun=key.getKey();
                if(v != "") {
                    notun = v+","+notun;
                }
                trieQueue.add(child);
                stringQueue.add(notun);
                if(pattern.size()<child.level){
                    ArrayList<String>make = new ArrayList<String>();
                    ArrayList<Integer>save = new ArrayList<Integer>();
                    pattern.add(make);
                    count.add(save);
                }
                pattern.get(child.level-1).add(notun);
                count.get(child.level-1).add(child.totalFrequency);
            }
        }
        int sum = 0;
        for(int i=0;i<pattern.size();i++){
            sum = sum + pattern.get(i).size();
            /*for(int j=0;j<pattern.get(i).size();j++){
                System.out.println(pattern.get(i).get(j)+" "+count.get(i).get(j));
            }*/
        }
        System.out.println(sum);
    }
}
