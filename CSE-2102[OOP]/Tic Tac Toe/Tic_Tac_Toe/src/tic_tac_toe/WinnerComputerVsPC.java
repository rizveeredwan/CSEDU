package tic_tac_toe;
public class WinnerComputerVsPC {
    boolean computer;
    boolean player;
    boolean horizontal,vertical,diagonalLeft,diagonalRight,fourByTwo,twoByFour;
    int simulationarr[][];
   public WinnerComputerVsPC(int arr[][])
   {
       computer = false;
       player = false;
       simulationarr = arr; 
       horizontal = false;
       vertical = false;
       diagonalLeft = false;
       diagonalRight = false;
       fourByTwo = false;
       twoByFour = false;
       if(computer == false && player == false) {
       horizontalWin();
       }
       if(computer == false && player == false) {
       verticalWin();
       }
       if(computer == false && player == false) {
       diagonalLeftWin();
       }
       if(computer == false && player == false) {
       diagonalRightWin();
       }
       if(computer == false && player == false) {
           fourByTwoWin();
       }
       if(computer == false && player == false) {
           twoByFourWin();
       }
       
   }
   public void horizontalWin()
   {
       for(int i = 0; i < 8; i++) {
           boolean going = false;
           int a = 0;
           for(int j = 0; j <= 6; j++) {
               if(simulationarr[i][j] == simulationarr[i][j+1] && simulationarr[i][j] != 0) {
                   going = true;
                   a = simulationarr[i][j];
               }
               else {
                   going = false;
                   break;
               }
           }
           if(going == true) {
               horizontal = true;
               if(a == 1) {
                   computer = true;
                   break;
               }
               else if(a == 2) {
                   player = true;
                   break;
               }
           }
       }
   }
   public void verticalWin()
   {
       for(int i = 0; i <= 7; i++) {
            boolean going = false;
            int a = 0;
           for(int j = 0; j <= 6; j++) {
               if(simulationarr[j][i] == simulationarr[j+1][i] && simulationarr[j][i] != 0) {
               going = true;
               a = simulationarr[j][i];
               }
               else {
                   going = false;
                   break;
               }
           }
           if(going == true) {
               vertical = true;
               if(a == 1) {
                   computer = true;
                   break;
               }
               else if(a == 2) {
                   player = true;
                   break;
               }
           }
           
       }
   }
   public void diagonalLeftWin()
   {
       boolean going = false;
       int a = 0;
       for(int i = 0; i <= 6; i++) {
           if(simulationarr[i][i] == simulationarr[i+1][i+1] && simulationarr[i][i] != 0) {
               going = true;
               a = simulationarr[i][i];
           }
           else {
               going = false;
               break;
           }
       }
       if(going == true) {
               diagonalLeft = true;
               if(a == 1) {
                   computer = true;
               }
               else if(a == 2) {
                   player = true;
               }
           }
   }
   public void diagonalRightWin()
   {
       boolean going = false;
       int a = 0;
       for(int i = 0,j = 7; i <= 6; i++,j--) {
           if(simulationarr[i][j] == simulationarr[i+1][j-1] && simulationarr[i][j] != 0) {
               going = true;
               a = simulationarr[i][j];
           }
           else {
               going = false;
               break;
           }
       }
       if(going == true) {
               diagonalRight = true;
               if(a == 1) {
                   computer = true;
               }
               else if(a == 2) {
                   player = true;
               }
           }
   }
   public void fourByTwoWin()
   {
       for(int i = 0; i <= 6; i++) {
           boolean going = false;
           for(int j = 0; j <= 4; j++) {
               going = false;
               int a = simulationarr[i][j];
               for(int l = i; l <= i+1; l++) {
                   for(int k = j; k <= j + 3; k++) {
                       if(a == simulationarr[l][k] && a != 0) {
                           going = true;
                       }
                       else {
                           going = false;
                           break;
                       }
                   }
                   if(going== false) break;
               }
               if(going == true && a != 0) {
                   fourByTwo = true;
                   if(a == 1) {
                   computer = true;
                   break;
               }
               else if(a == 2) {
                   player = true;
                   break;
               }
               }
           }
           if(going == true) break;
       }
   }
   public void twoByFourWin()
   {
       for(int i = 0; i <= 4; i++) {
           boolean going = false;
           int a = 0;
           for(int j = 0; j <= 6;j++) {
               going = false;
               a = simulationarr[i][j];
               for(int l = i; l <= i+3; l++) {
                   for(int k = j; k <= j + 1;k++) {
                       if(a == simulationarr[l][k] && a != 0) {
                           going = true;
                       }
                       else {
                           going = false;
                           break;
                       }
                   }
                   if(going== false) break;
               }
               if(going == true && a != 0) {
                   twoByFour = true;
                if(a == 1) {
                   computer = true;
                   break;
               }
               else if(a == 2) {
                   player = true;
                   break;
               }
           }
           }
           if(going == true) break;
       }
   }
}
