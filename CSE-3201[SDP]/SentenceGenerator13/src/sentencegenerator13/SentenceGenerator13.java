/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sentencegenerator13;

import java.util.*;
import java.io.*;
import java.net.*;

public class SentenceGenerator13
{

    public static void main(String[] args)
    {
        boolean flag = true;
        
        while(flag){
            System.out.println("Choose Sentence Generator");
            System.out.println("1 for Random Sentence Generator(RSG)");
            System.out.println("2 for Index Odd Sorted Sentence Generator(IOSSG)");
            System.out.println("3 for Reverse Sentence Generator(OSG)");
            System.out.println("0 to quit");
            
            boolean inFlag = true;
            
            Scanner sc = new Scanner(System.in);
            
            GeneratorStrategy sentGen = null;
            
            int opt = sc.nextInt();
            
            if(opt == 1) sentGen = new RSG();
            else if(opt == 2) sentGen = new IOSSG();
            else if(opt == 3) sentGen = new OSG();
            else flag = false;
            
            while(inFlag){
                System.out.println("Choose Action");
                System.out.println("1 to add a word");
                System.out.println("2 to generate a sentence");
                System.out.println("0 to quit");
                
                int optIn = sc.nextInt();
            
                if(optIn == 1){
                    System.out.println("Enter word;");
                    
                    String word = sc.next();
                    
                    sentGen.add(word);
                }
                else if(optIn == 2){
                    System.out.println("Enter length;");
                    
                    int length = sc.nextInt();
                    
                    System.out.println(sentGen.generate(length));
                }
                else inFlag = false;
            }
        }
    }
}

abstract class GeneratorStrategy
{
    ArrayList<String> vocabulary = new ArrayList<String>();    
    
    abstract void add(String word);
    abstract String generate(int length);
}

class RSG extends GeneratorStrategy
{
    public void add(String word){
        word = word.toUpperCase();
        vocabulary.add(word);
    }
    
    public String generate(int length){
        Random r = new Random();
        
        String S = new String();
                
        for(int i = 0; i < length; i++){
            int ind = r.nextInt(vocabulary.size());
            
            S = S + vocabulary.get(ind)+ " ";
        }   
        
        return S;
    }
}

class IOSSG extends GeneratorStrategy
{

    public void add(String word){
        word = word.toLowerCase();
        vocabulary.add(word);
    }

    public String generate(int length){
        Random r = new Random();
        
        ArrayList<String> S = new ArrayList<String>();
                
        for(int i = 0; i < length; i++){
            int ind = r.nextInt(vocabulary.size());
            
            S.add(vocabulary.get(ind) + " ");
        }   
        
        S.sort(Comparator.naturalOrder());
        
        return S.toString();
    }
}


class OSG extends GeneratorStrategy
{

    public void add(String word){
        word = new StringBuffer(word.toUpperCase()).reverse().toString();
        vocabulary.add(word);
    }

    public String generate(int length){
        Random r = new Random();
        
        String S = new String();
        
        int[] indices = new int[length];
                
        for(int i = 0; i < length; i++){
            indices[i] = r.nextInt(vocabulary.size());
        }   
        
        Arrays.sort(indices);
        Collections.reverse(Arrays.asList(indices));
        System.out.println("order " + indices.toString());
        
        for(int i = 0; i < length; i++){
            S = S + vocabulary.get(indices[i]) + " ";
        } 
        
        return S;
    }
}