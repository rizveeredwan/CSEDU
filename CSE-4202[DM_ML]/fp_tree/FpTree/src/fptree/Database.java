package fptree;

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
    
    //function to sort the database according to the frequency
    void sortDatabase(HeaderTable header,int minimumSupportCount){
        Map<String,Integer>M=new HashMap<String,Integer>();
        for(int i=0;i<header.headerTable.size();i++){
            M.put(header.headerTable.get(i).item, i);
        }
        ArrayList<ArrayList<Item>>tempArray=new ArrayList<ArrayList<Item>>();
        //sort the transactions
        for(int i=0;i<transactions.size();i++){
            ArrayList<Item>temp=new ArrayList<Item>();
            for(int j=0;j<transactions.get(i).size();j++){
                Item object = new Item();
                if(M.containsKey(transactions.get(i).get(j)) == false) continue; //
                object.count= header.headerTable.get(M.get(transactions.get(i).get(j))).count;
                object.item=header.headerTable.get(M.get(transactions.get(i).get(j))).item;
                temp.add(object);
            }
            if(temp.size() > 0) {
                Collections.sort(temp,new CompareItem());
                tempArray.add(temp);
            }
        }
        transactions.clear();
        for(int i=0;i<tempArray.size();i++){
            ArrayList<String>temp=new ArrayList<String>();
            for(int j=0;j<tempArray.get(i).size();j++){
                temp.add(tempArray.get(i).get(j).item);
            }
            transactions.add(temp);
        }
        
    }
    void printDatabase(){
        for(int i=0;i<transactions.size();i++){
            for(int j=0;j<transactions.get(i).size();j++){
                System.out.print(transactions.get(i).get(j)+" ");
            }
            System.out.println();
        }
    }
}
