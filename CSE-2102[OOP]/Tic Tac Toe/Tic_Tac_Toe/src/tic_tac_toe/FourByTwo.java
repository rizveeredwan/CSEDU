package tic_tac_toe;
public class FourByTwo {
   protected int simulationarr[][];
   protected int row,col;
   protected int maximum;
   public FourByTwo(int arr[][],int i,int j)
   {
     simulationarr = arr;  
     row = i;
     col = j;
     maximum = 0;
     downMove();
   }
   boolean validity(int r)
   {
       if(r >= 0 && r <= 7) return true;
       else return false;
   }
   void downMove()
   {
       boolean go = validity(row+1);
      // System.out.println(go);
       if(go == true) {
           downMoveOne();
           downMoveTwo();
           downMoveThree();
           downMoveFour();
       }
       boolean run = validity(row-1);
       if(run == true) {
           upMoveOne();
           upMoveTwo();
           upMoveThree();
           upMoveFour();
       }
   }
   void downMoveOne()
   {
       //System.out.println("ase one");
       int sum = 1;
       if(simulationarr[row+1][col] == 1) {
           sum++;
           for(int i = col+1; i <= col+3; i++) {
               boolean one = validity(i);
               if(one == true) {
                   if(simulationarr[row][i] == 1 && simulationarr[row+1][i] == 1) {
                       sum = sum+2;
                   }
                   else break;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
      // System.out.println(sum);
   }
   void downMoveTwo()
   {
      // System.out.println("ase Two");
       int sum = 1;
       int left = 1;
       int right = 2;
       if(simulationarr[row+1][col] == 1) {
           sum++;
           for(int i = col-1,counter = 1; i >= 0 && counter <= left;i--,counter++) {
               if(simulationarr[row][i] == 1 && simulationarr[row+1][i] == 1) {
                   sum = sum+2;
               }
               else break;
           }
           for(int i = col + 1,counter = 1; i <= 7 && counter <= right; i++,counter++) {
              if(simulationarr[row][i] == 1 && simulationarr[row+1][i] == 1) {
                   sum = sum+2;
               }
               else break; 
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
      // System.out.println(sum);
   }
   void downMoveThree()
   {
      // System.out.println("ase Three");
       int sum = 1;
       int left = 2;
       int right = 1;
       if(simulationarr[row+1][col] == 1) {
           sum++;
           for(int i = col-1,counter = 1; i >= 0 && counter <= left;i--,counter++) {
               if(simulationarr[row][i] == 1 && simulationarr[row+1][i] == 1) {
                   sum = sum+2;
               }
               else break;
           }
           for(int i = col + 1,counter = 1; i <= 7 && counter <= right; i++,counter++) {
              if(simulationarr[row][i] == 1 && simulationarr[row+1][i] == 1) {
                   sum = sum+2;
               }
               else break; 
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
     //  System.out.println(sum);
   }
   void downMoveFour()
   {
       //System.out.println("ase Four");
       int sum = 1;
       int left = 3;
       int right = 0;
       if(simulationarr[row+1][col] == 1) {
           sum++;
           for(int i = col-1,counter = 1; i >= 0 && counter <= left;i--,counter++) {
               if(simulationarr[row][i] == 1 && simulationarr[row+1][i] == 1) {
                   sum = sum+2;
               }
               else break;
           }
           for(int i = col + 1,counter = 1; i <= 7 && counter <= right; i++,counter++) {
              if(simulationarr[row][i] == 1 && simulationarr[row+1][i] == 1) {
                   sum = sum+2;
               }
               else break; 
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
      // System.out.println(sum);
   }
   void upMoveOne()
   {
      // System.out.println("ase 5");
       int sum = 1;
       int left = 0;
       int right = 3;
       if(simulationarr[row-1][col] == 1) {
           sum++;
           for(int i = col-1,counter = 1; i >= 0 && counter <= left;i--,counter++) {
               if(simulationarr[row][i] == 1 && simulationarr[row-1][i] == 1) {
                   sum = sum+2;
               }
               else break;
           }
           for(int i = col + 1,counter = 1; i <= 7 && counter <= right; i++,counter++) {
              if(simulationarr[row][i] == 1 && simulationarr[row-1][i] == 1) {
                   sum = sum+2;
               }
               else break; 
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
     //  System.out.println(sum);
   }
   void upMoveTwo()
   {
      // System.out.println("ase 6");
       int sum = 1;
       int left = 1;
       int right = 2;
       if(simulationarr[row-1][col] == 1) {
           sum++;
           for(int i = col-1,counter = 1; i >= 0 && counter <= left;i--,counter++) {
               if(simulationarr[row][i] == 1 && simulationarr[row-1][i] == 1) {
                   sum = sum+2;
               }
               else break;
           }
           for(int i = col + 1,counter = 1; i <= 7 && counter <= right; i++,counter++) {
              if(simulationarr[row][i] == 1 && simulationarr[row-1][i] == 1) {
                   sum = sum+2;
               }
               else break; 
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
     //  System.out.println(sum);
   }
   void upMoveThree()
   {
       //System.out.println("ase 7");
       int sum = 1;
       int left = 2;
       int right = 1;
       if(simulationarr[row-1][col] == 1) {
           sum++;
           for(int i = col-1,counter = 1; i >= 0 && counter <= left;i--,counter++) {
               if(simulationarr[row][i] == 1 && simulationarr[row-1][i] == 1) {
                   sum = sum+2;
               }
               else break;
           }
           for(int i = col + 1,counter = 1; i <= 7 && counter <= right; i++,counter++) {
              if(simulationarr[row][i] == 1 && simulationarr[row-1][i] == 1) {
                   sum = sum+2;
               }
               else break; 
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
      // System.out.println(sum);
   }
   void upMoveFour()
   {
      // System.out.println("ase 8");
       int sum = 1;
       int left = 3;
       int right = 0;
       if(simulationarr[row-1][col] == 1) {
           sum++;
           for(int i = col-1,counter = 1; i >= 0 && counter <= left;i--,counter++) {
               if(simulationarr[row][i] == 1 && simulationarr[row-1][i] == 1) {
                   sum = sum+2;
               }
               else break;
           }
           for(int i = col + 1,counter = 1; i <= 7 && counter <= right; i++,counter++) {
              if(simulationarr[row][i] == 1 && simulationarr[row-1][i] == 1) {
                   sum = sum+2;
               }
               else break; 
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
     //  System.out.println(sum);
   }
   
}
