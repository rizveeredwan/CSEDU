package tic_tac_toe;
public class TwoByFour {
   protected int simulationarr[][];
   protected int row,col,maximum;
   public TwoByFour(int arr[][],int i, int j)
   {
       simulationarr = arr;
       row = i;
       col = j;
       maximum = 0;
       choice();
   }
   boolean validity(int r)
   {
       if(r >= 0 && r <= 7) return true;
       else return false;
   }
   void choice()
   {
      boolean go = validity(col+1);
      if(go == true) {
          upZeroDownThree();
          upOneDownTwo();
          upTwoDownOne();
          upThreeDownZero();
      }
      boolean run = validity(col-1);
      if(run == true) {
          leftUpThreeDownZero();
          leftUpTwoDownOne();
          leftUpOneDownTwo();
          leftUpZeroDownThree();
          
      }
   }
   void upZeroDownThree()
   {
       int sum = 1;
       int up = 0;
       int down = 3;
       if(simulationarr[row][col+1] == 1) {
           sum++;
           for(int i = row - 1, counter = 1; i >= 0 && counter <= up; counter++,i--) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col+1] == 1) {
                   sum = sum + 2;
               }
               else break;
               
           }
           for(int i = row+1,counter = 1; i <= 7 && counter <= down; counter++,i++) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col+1] == 1) {
                   sum = sum + 2;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
   }
   void upOneDownTwo()
   {
       int sum = 1;
       int up = 1;
       int down = 2;
       if(simulationarr[row][col+1] == 1) {
           sum++;
           for(int i = row - 1, counter = 1; i >= 0 && counter <= up; counter++,i--) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col+1] == 1) {
                   sum = sum + 2;
               }
               else break;
               
           }
           for(int i = row+1,counter = 1; i <= 7 && counter <= down; counter++,i++) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col+1] == 1) {
                   sum = sum + 2;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
   }
   void upTwoDownOne()
   {
       int sum = 1;
       int up = 2;
       int down = 1;
       if(simulationarr[row][col+1] == 1) {
           sum++;
           for(int i = row - 1, counter = 1; i >= 0 && counter <= up; counter++,i--) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col+1] == 1) {
                   sum = sum + 2;
               }
               else break;
               
           }
           for(int i = row+1,counter = 1; i <= 7 && counter <= down; counter++,i++) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col+1] == 1) {
                   sum = sum + 2;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
   }
   void upThreeDownZero()
   {
       int sum = 1;
       int up = 3;
       int down = 0;
       if(simulationarr[row][col+1] == 1) {
           sum++;
           for(int i = row - 1, counter = 1; i >= 0 && counter <= up; counter++,i--) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col+1] == 1) {
                   sum = sum + 2;
               }
               else break;
               
           }
           for(int i = row+1,counter = 1; i <= 7 && counter <= down; counter++,i++) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col+1] == 1) {
                   sum = sum + 2;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
       
   }
   void leftUpZeroDownThree()
   {
       int sum = 1;
       int up = 0;
       int down = 3;
       if(simulationarr[row][col-1] == 1) {
           sum++;
           for(int i = row - 1, counter = 1; i >= 0 && counter <= up; counter++,i--) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col-1] == 1) {
                   sum = sum + 2;
               }
               else break;
               
           }
           for(int i = row+1,counter = 1; i <= 7 && counter <= down; counter++,i++) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col-1] == 1) {
                   sum = sum + 2;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
   }
   void leftUpOneDownTwo()
   {
       int sum = 1;
       int up = 1;
       int down = 2;
       if(simulationarr[row][col-1] == 1) {
           sum++;
           for(int i = row - 1, counter = 1; i >= 0 && counter <= up; counter++,i--) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col-1] == 1) {
                   sum = sum + 2;
               }
               else break;
               
           }
           for(int i = row+1,counter = 1; i <= 7 && counter <= down; counter++,i++) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col-1] == 1) {
                   sum = sum + 2;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
   }
   void leftUpTwoDownOne()
   {
       int sum = 1;
       int up = 2;
       int down = 1;
       if(simulationarr[row][col-1] == 1) {
           sum++;
           for(int i = row - 1, counter = 1; i >= 0 && counter <= up; counter++,i--) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col-1] == 1) {
                   sum = sum + 2;
               }
               else break;
               
           }
           for(int i = row+1,counter = 1; i <= 7 && counter <= down; counter++,i++) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col-1] == 1) {
                   sum = sum + 2;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
   }
   void leftUpThreeDownZero()
   {
       int sum = 1;
       int up = 3;
       int down = 0;
       if(simulationarr[row][col-1] == 1) {
           sum++;
           for(int i = row - 1, counter = 1; i >= 0 && counter <= up; counter++,i--) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col-1] == 1) {
                   sum = sum + 2;
               }
               else break;
               
           }
           for(int i = row+1,counter = 1; i <= 7 && counter <= down; counter++,i++) {
               if(simulationarr[i][col] == 1 && simulationarr[i][col-1] == 1) {
                   sum = sum + 2;
               }
               else break;
           }
       }
       if(sum > maximum) {
           maximum = sum;
       }
   }
   
}
