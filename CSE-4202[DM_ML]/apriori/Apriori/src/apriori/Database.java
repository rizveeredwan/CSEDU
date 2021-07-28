package apriori;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Database {
    ArrayList<ArrayList<String>>transactions=new ArrayList<ArrayList<String>>();
    void loadDatabase(String fileName){
        BufferedReader br;
        FileReader fr;
        try{
            fr = new FileReader(fileName);
            br = new BufferedReader(fr);
            int number_of_transactions = Integer.parseInt(br.readLine());
            for(int i=0;i<number_of_transactions;i++){
                String line = br.readLine();
                String itemset[] = line.split(" ");
                ArrayList<String>temp=new ArrayList<String>();
                for(int j=0;j<itemset.length;j++){
                    temp.add(itemset[j]);
                }
                Collections.sort(temp);//sorting the itemsets 
                transactions.add(temp);
            }
        }
        catch(Exception e){
             e.printStackTrace();
        }
    }
    
    void readSingleElement(Map<String,Integer> M){
        for(int i=0;i<transactions.size();i++){
            for(int j=0;j<transactions.get(i).size();j++){
                if(M.containsKey(transactions.get(i).get(j)) == true){
                    Integer obj = M.get(transactions.get(i).get(j));
                    Integer update = new Integer(obj.intValue()+1);
                    M.replace(transactions.get(i).get(j), update);
                }
                else{
                    Integer obj = new Integer(1);
                    M.put(transactions.get(i).get(j),obj);
                }
            }
       }
    }
    
    void readTwoLengthElement(Map<String,Integer>M){
        //debug: printMap(M);
        for(int i=0;i<transactions.size();i++){
            for(int j=0;j<transactions.get(i).size();j++){
                String temp=transactions.get(i).get(j);
                for(int k=j+1;k<transactions.get(i).size();k++){
                    String notun = temp+","+transactions.get(i).get(k);
                    //System.out.println(notun);
                    if(M.containsKey(notun)){
                        Integer obj = M.get(notun);
                        Integer update = new Integer(obj.intValue()+1);
                        M.replace(notun,update);
                    }
                    else{
                       // System.out.println("String Error Exists");
                    }
                }
            }
        }
    }
    
    Map<String,Integer> databaseScanForNLength(int targetLength){
        Map<String,Integer>M = new HashMap<String,Integer>();
        ArrayList<String>madeAlready = new ArrayList<String>();
        for(int i=0;i<transactions.size();i++){
            madeAlready.clear();
            generatingNLengthMapResult(i,0,madeAlready,targetLength,M);
        }
        return M;
    }
    
    void generatingNLengthMapResult(int transactionId,int index,ArrayList<String>madeAlready,int targetLength,Map<String,Integer>M){
        
        if(madeAlready.size() == targetLength){
            String temp=madeAlready.get(0);
            for(int i=1;i<madeAlready.size();i++){
                temp=temp+","+madeAlready.get(i);
            }
            if(M.containsKey(temp)){
                int value = M.get(temp);
                M.replace(temp, value+1);
            }
            else{
                M.put(temp, 1);
            }
            return;
        }
        if(index >= transactions.get(transactionId).size()){
            return;
        }
        
        //nisi
        madeAlready.add(transactions.get(transactionId).get(index));
        generatingNLengthMapResult(transactionId,index+1,madeAlready,targetLength,M);
        madeAlready.remove(transactions.get(transactionId).get(index));
        
        //nei nai
        generatingNLengthMapResult(transactionId,index+1,madeAlready,targetLength,M);
        return;
    }
    
    Map<String,Integer> optimizedGeneratingNLengthResult(ArrayList<String>actualCandidate){
        Map<String,Integer>M = new HashMap<String,Integer>();
        for(int i=0;i<actualCandidate.size();i++){
           M.put(actualCandidate.get(i),0);
           String array[] = actualCandidate.get(i).split(",");
           boolean ok=true;
           int count=0;
           for(int j=0;j<transactions.size();j++){
               ok=true;
               for(int k=0;k<array.length;k++){
                   ok=binarySearch(array[k],j);
                   if(ok==false) break;
               }
               if(ok){
                   count++;
               }
           }
           M.replace(actualCandidate.get(i), count);
        }
        return M;
    }
    
    boolean binarySearch(String targetString,int transactionId){
        int low=0;
        int high = transactions.get(transactionId).size()-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(transactions.get(transactionId).get(mid).compareTo(targetString) == 0){
                return true;
            }
            if(transactions.get(transactionId).get(mid).compareTo(targetString) > 0){
                high=mid-1;
            }
            if(transactions.get(transactionId).get(mid).compareTo(targetString) < 0){
                low=mid+1;
            }
        }
        return false;
    }
    void printMap(Map<String,Integer>M){
        for(Map.Entry<String,Integer>key : M.entrySet()){
           System.out.print(key.getKey()+" "+key.getValue());
           System.out.println();
       }
    }
    
    
}
