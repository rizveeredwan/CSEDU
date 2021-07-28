package vendingmachine09;

import java.util.Scanner;

abstract class State{
   public abstract int doOperation(Machine m, Person p);
   public abstract void printCondition();
}
class TakeOrder extends State{
    
    public int doOperation(Machine m, Person p){
        m.printState(this);
        if(p.order.equalsIgnoreCase("coffe")){
            if(m.coffe<=0) {
                State s = new EjectMoney();
                m.state=s;
                return s.doOperation(m, p);
            }
            else {
                State s = new InsertMoney();
                m.state=s;
                return s.doOperation(m, p); 
            }
        }
        if(p.order.equalsIgnoreCase("cappuccino")){
            if(m.cappuccino<=0) {
                State s = new EjectMoney();
                m.state=s;
                return s.doOperation(m, p);
            }
            else {
               State s = new InsertMoney();
               m.state=s;
               return s.doOperation(m, p);  
            }
        }
        return 0;
    }
    public void printCondition(){
     System.out.println("Machine in state - Taking order.\n");   
     return;
    }
}
class InsertMoney extends State{
    
    public int doOperation(Machine m, Person p){
        m.printState(this);
        System.out.println("Are you sure you want to perform transaction.\n");
        System.out.println("0 For yes. 1 For No\n");
        Scanner scan = new Scanner(System.in);
        int v = scan.nextInt();
        if(v == 0){
           State s = new OrderReturn();
           m.state = s;
           return s.doOperation(m, p);
        }
        else if(v == 1){
           State s = new EjectMoney();
           m.state=s;
           return s.doOperation(m, p);
        }
        return 0;
    }
    public void printCondition(){
        System.out.println("Machine in state - Inserting Money.\n"); 
    }
}

class EjectMoney extends State{
    
    public int doOperation(Machine m, Person p){
        m.printState(this);
        p.transaction = false;
        return p.moneyAmount;
    }
    public void printCondition(){
        System.out.println("Machine in state - Ejecting Money.\n"); 
    }
}

class OrderReturn extends State{
    
    public int doOperation(Machine m, Person p){
        m.printState(this);
        State s = new MoneyReturn();
        m.state = s;
        return s.doOperation(m, p);
        
    }
    public void printCondition(){
        System.out.println("Machine in state - giving order.\n"); 
    }
}

class MoneyReturn extends State{
    
    public int doOperation(Machine m, Person p){
        m.printState(this);
        if(p.order.equalsIgnoreCase("coffe")){
            m.coffe--;
            double val = p.moneyAmount - 1.20;
            if(val<0){
                p.transaction = false;
                State s = new EjectMoney();
                m.state = s;
                return s.doOperation(m, p);
            }
            else {
                int sum = 0;
                for(int i=10;;i++){
                    sum += i;
                    if(sum>val){
                        sum = sum - i;
                        return sum;
                    }
                }
            }
            
        }
        if(p.order.equalsIgnoreCase("cappuccino")){
            m.cappuccino--;
            double val = p.moneyAmount - 1.50;
            if(val<0){
                p.transaction = false;
                State s = new EjectMoney();
                m.state = s;
                return s.doOperation(m, p);
            }
            else {
                int sum = 0;
                for(int i=10;;i++){
                    sum += i;
                    if(sum>val){
                        sum = sum - i;
                        return sum;
                    }
                }
            }
        }
        return 0;
    }
    public void printCondition(){
        System.out.println("Machine in state - returnning money.\n"); 
    }
   
}

class Machine{
   int coffe;
   int cappuccino;
   State state;
   public Machine(){
       coffe = 5;
       cappuccino = 5; 
   }
   public int startTransaction(Machine m,Person p){
       return state.doOperation(m, p);
   }
   public void printState(State s){
       s.printCondition();
   }
}

class Person{
    
    String order;
    int moneyAmount;
    boolean transaction;
    public void giveOrder(Machine m){
        System.out.println("Give 1 for coffe, 2 for cappucino.\n");
        Scanner scan = new Scanner(System.in);
        transaction = false;
        int v= scan.nextInt();
        if(v == 1) {
            order = "coffe";
        }
        else if(v == 2){
            order = "cappuccino";
        }
        System.out.println("Please give money amount");
        moneyAmount = scan.nextInt();
        m.state = new TakeOrder();
        int return_amount = m.startTransaction(m, this);
        System.out.println(return_amount);   
    }
}


public class VendingMachine09 {

    
    public static void main(String[] args) {
        Person p = new Person();
        Machine machine  = new Machine();
        p.giveOrder(machine);
        
    }
    
}
