package apriori;

import java.util.*;




public class Apriori {

    public static void main(String[] args) {
      
       
       ArrayList<ArrayList<String>>generatedItemset = new ArrayList<ArrayList<String>>();
       ArrayList<ArrayList<Integer>>generatedItemsetFrequency = new ArrayList<ArrayList<Integer>>();
       
       //Database load
       Database database = new Database();
       //database.loadDatabase("input.txt");
       //database.loadDatabase("transactions.txt");
       database.loadDatabase("connect.txt"); 
       //database.loadDatabase("T40I10D100K.txt"); 
       double minimumSupport = Math.ceil((90/100.0)*database.transactions.size());
       int minimum_support_count = (int)minimumSupport; //2
       Scanner scan = new Scanner(System.in);
       System.out.println("Give 1 for optimized 2 for normal optmized");
       int choice = scan.nextInt();
       if(choice == 1){
       Apriori optimized = new Apriori();
       optimized.optimizedSolution(database, minimum_support_count);
       System.out.println("done");
       return;
       }
       ArrayList<Integer>join=new ArrayList<Integer>();
       ArrayList<Integer>prune=new ArrayList<Integer>();
       double past = System.currentTimeMillis();
       System.out.println("AfterJoining  AfterPrunning  ActualFrequentPattern");
       //read single element
       Apriori apriori = new Apriori();
       Map<String,Integer> M = new HashMap<String,Integer>();
       
       database.readSingleElement(M);
       join.add(apriori.countElementsInMap(M));
       M = apriori.pruning(M,minimum_support_count);
       prune.add(apriori.countElementsInMap(M));
       //debug: apriori.printMap(M);
       apriori.saveGeneratedItems(generatedItemset, generatedItemsetFrequency, M);
       System.out.println("Level 1: " + join.get(0)+" "+prune.get(0)+" "+generatedItemset.get(0).size());
       //apriori.printMap(M);
       
       //two length section
       ArrayList<String>twoLength = apriori.allPossibleTwoLengthCombination(generatedItemset.get(0));
       join.add(twoLength.size());
       M.clear();
       for(int i=0;i<twoLength.size();i++){
           M.put(twoLength.get(i), new Integer(0));
       }
       database.readTwoLengthElement(M);
       M = apriori.pruning(M, minimum_support_count);
       prune.add(apriori.countElementsInMap(M));
       apriori.saveGeneratedItems(generatedItemset, generatedItemsetFrequency, M);
       Collections.sort(generatedItemset.get(1));
       generatedItemsetFrequency.get(1).clear();
       apriori.copyFrequencyFromMap(generatedItemset.get(1), generatedItemsetFrequency.get(1), M);
       System.out.println("Level 2 : "+join.get(1)+" "+prune.get(1)+" "+generatedItemset.get(1).size());
       
       //n length section
       //i=2 means this actually wants to make 3 lengths, which will be saved into position 2
       int max_length_itemset=2;
       ArrayList<String>possibleCandidate,actualCandidate;
       for(int i=2;generatedItemset.get(i-1).size()!= 0;i++){
           possibleCandidate = apriori.makeNLengthItemset(generatedItemset.get(i-1),i-1);
           //join
           join.add(possibleCandidate.size());
           if(possibleCandidate.size() == 0){
               break;
           }
           actualCandidate = apriori.findingActualCandidateNItemSet(possibleCandidate, M);
           if(actualCandidate.size()==0){
               break;
           }
           //prune
           prune.add(actualCandidate.size());
           
           //debug: System.out.println((i+1)+" length candidates");
           M = database.optimizedGeneratingNLengthResult(actualCandidate);
           
           //debug: System.out.println((i+1)+ " length patterns");
           //M = database.databaseScanForNLength(i+1);
           apriori.generatingRealCandidate(generatedItemset,generatedItemsetFrequency,actualCandidate,M,minimum_support_count);
           System.out.println("Level "+(i+1)+" : "+join.get(i)+" "+prune.get(i)+" "+generatedItemset.get(i).size());
           //debug: System.out.println((i+1)+" Length done");
       }
       int result=0;
       for(int i=0;i<generatedItemset.size();i++){
           result += generatedItemset.get(i).size();
       }
       System.out.println(result);
       double present = System.currentTimeMillis();
       System.out.println((present-past)/1000);
       //apriori.print_frequent_itemset(generatedItemset, generatedItemsetFrequency);
       
    }
    
    
    void print_frequent_itemset(ArrayList<ArrayList<String>>generatedItemset,ArrayList<ArrayList<Integer>>generatedItemsetFrequency){
        for(int i=0;i<generatedItemset.size();i++){
            for(int j=0;j<generatedItemset.get(i).size();j++){
                System.out.println(generatedItemset.get(i).get(j)+" "+generatedItemsetFrequency.get(i).get(j));
            }
        }
    }
    
    void generatingRealCandidate(ArrayList<ArrayList<String>>generatedItemset,ArrayList<ArrayList<Integer>>generatedItemsetFrequency,ArrayList<String>actualCandidate,Map<String,Integer>M,int min_support){
        ArrayList<String>temp=new ArrayList<String>();
        ArrayList<Integer>tempFrequency = new ArrayList<Integer>();
        for(int i=0;i<actualCandidate.size();i++){
            if(M.containsKey(actualCandidate.get(i))){
                if(M.get(actualCandidate.get(i))>=min_support){
                    temp.add(actualCandidate.get(i));
                    tempFrequency.add(M.get(actualCandidate.get(i)));
                }
            }
        }
        generatedItemset.add(temp);
        generatedItemsetFrequency.add(tempFrequency);
        return;
    }
    
    ArrayList<String> makeNLengthItemset(ArrayList<String>currentItemSet,int baseLength){
        ArrayList<String>temp = new ArrayList<String>();
        for(int i=0;i<currentItemSet.size();i++){
            String leftSide[] = currentItemSet.get(i).split(",");
            String leftSideString = convertStringArrayToString(leftSide,0,baseLength);
            //debug: System.out.println(leftSideString+" "+"leftSideString");
            for(int k=i+1;k<currentItemSet.size();k++){
                String rightSide[] = currentItemSet.get(k).split(",");
                String rightSideString = convertStringArrayToString(rightSide,0,baseLength);
                //debug: System.out.println(rightSideString+" "+"rightSideString");
                //debug: System.out.println("compare value = "+leftSideString.compareTo(rightSideString));
                if(leftSideString.compareTo(rightSideString)<0){
                    break;
                }
                if(leftSideString.compareTo(rightSideString)>0){
                    continue;
                }
                if(leftSideString.compareTo(rightSideString) == 0){
                    String merge = currentItemSet.get(i);
                    merge = merge + ","+rightSide[rightSide.length-1];
                    temp.add(merge);
                }
            }
        }
        return temp;
    }
    
    ArrayList<String> findingActualCandidateNItemSet(ArrayList<String>possibleCandidate,Map<String,Integer>M){
        ArrayList<String>actualCandidate = new ArrayList<String>();
        for(int i=0;i<possibleCandidate.size();i++){
            String array[] = possibleCandidate.get(i).split(",");
            boolean status = allSmallerSubsetChecking(array,M);
            if(status==true){
                actualCandidate.add(possibleCandidate.get(i));
            }
        }
        return actualCandidate;
    }
    
    boolean allSmallerSubsetChecking(String array[],Map<String,Integer>M){
        for(int i=0;i<array.length;i++){
            int notTake=i;
            String temp="";
            for(int j=0;j<array.length;j++){
                if(notTake == j) continue;
                if(temp.length()==0){
                    temp=array[j];
                }
                else{
                    temp=temp+","+array[j];
                }
            }
            if(M.containsKey(temp)){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    String convertStringArrayToString(String temp[],int index,int baseLength){
        String result="";
        result = result + temp[index];
        for(int i=index+1;i<=baseLength-1;i++){
            result = result+" "+temp[i];
        }
        return result;
    }
    
    Map<String,Integer> pruning(Map<String,Integer>M,int minimum_support_count){
        Map<String,Integer>temp = new HashMap<String,Integer>();
        for(Map.Entry<String,Integer>key : M.entrySet()){
           if(key.getValue()>=minimum_support_count){
               temp.put(key.getKey(), key.getValue());
           }
       }
       return temp;
    }
    void saveGeneratedItems(ArrayList<ArrayList<String>>generatedItemset,ArrayList<ArrayList<Integer>>generatedItemsetFrequency,Map<String,Integer> M){
        ArrayList<String>temp = new ArrayList<String>();
        ArrayList<Integer>tempFrequency = new ArrayList<Integer>();
        for(Map.Entry<String,Integer>key : M.entrySet()){
            temp.add(key.getKey());
            //tempFrequency.add(key.getValue());
        }
        Collections.sort(temp);
        for(int i=0;i<temp.size();i++){
            tempFrequency.add(M.get(temp.get(i)));
        }
        generatedItemset.add(temp);
        generatedItemsetFrequency.add(tempFrequency);
        return;
    }
    void printMap(Map<String,Integer>M){
        for(Map.Entry<String,Integer>key : M.entrySet()){
           System.out.print(key.getKey()+" "+key.getValue());
           System.out.println();
       }
    }
    ArrayList<String> allPossibleTwoLengthCombination(ArrayList<String>oneLength){
        ArrayList<String>twoLength = new ArrayList<String>();
        for(int i=0;i<oneLength.size();i++){
            String s=oneLength.get(i);
            for(int j=i+1;j<oneLength.size();j++){
                twoLength.add(s+","+oneLength.get(j));
            }
        }
        return twoLength;
    }
    void printArrayListString(ArrayList<String>temp){
        for(int i=0;i<temp.size();i++){
            System.out.println(temp.get(i));
        }
    }
    void copyFrequencyFromMap(ArrayList<String>s,ArrayList<Integer>f,Map<String,Integer>M){
        for(int i=0;i<s.size();i++){
            f.add(M.get(s.get(i)));
        }
        return;
    }
    void optimizedSolution(Database db,int minimumSupportCount){
        double past =System.currentTimeMillis();
        Trie root = new Trie();
        root.apriori(db, root, minimumSupportCount);
        double present = System.currentTimeMillis();
        root.printPattern(root); 
        System.out.println(present-past);
    }
    
    int countElementsInMap(Map<String,Integer>M){
       int count=0;
       for(Map.Entry<String,Integer>key : M.entrySet()){
           count=count+1;
       }
       return count;
    }
}
