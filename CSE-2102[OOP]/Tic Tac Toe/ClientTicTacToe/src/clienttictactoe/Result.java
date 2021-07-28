package clienttictactoe;
import javax.swing.*;
public class Result implements Runnable{
    Thread T;
    JFrame resultFrame;
    int simulationarr[][];
    public Result(int arr[][])
    {
       simulationarr = arr;
       T = new Thread(this,"result show");
       T.start();
    }
   public void run()
   {
       if(simulationarr[0][0] == 2 && simulationarr[1][1] == 2 && simulationarr[2][2] == 2) {
           System.out.println("found in One");
       }
       else if(simulationarr[0][2] == 2 && simulationarr[1][1] == 2 && simulationarr[2][0] == 2) {
           System.out.println("found in two");
       }
       else if(simulationarr[0][0] == 2 && simulationarr[1][0] == 2 && simulationarr[2][0] == 2) {
           System.out.println("found in 3");
       }
       else if(simulationarr[0][1] == 2 && simulationarr[1][1] == 2 && simulationarr[2][1] == 2) {
           System.out.println("found in 4");
       }
       else if(simulationarr[0][2] == 2 && simulationarr[1][2] == 2 && simulationarr[2][2] == 2) {
           System.out.println("found in 5");
       }
       else if(simulationarr[0][0] == 2 && simulationarr[0][1] == 2 && simulationarr[0][2] == 2) {
           System.out.println("found in 6");
       }
       else if(simulationarr[1][0] == 2 && simulationarr[1][1] == 2 && simulationarr[1][2] == 2) {
           System.out.println("found in 7");
       }
       else if(simulationarr[2][0] == 2 && simulationarr[2][1] == 2 && simulationarr[2][2] == 2) {
           System.out.println("found in 8");
       }
       else {
           System.out.println("kothao pai ni");
       }
       
   }
}
