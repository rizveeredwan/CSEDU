package tic_tac_toe;
import javax.swing.*;
public class Intelligence implements Runnable{
    int simulationarr[][];
    Thread T;
    JFrame nameChange;
    public Intelligence(int arr[][],JFrame givenFrame) throws Exception
    {
        nameChange = givenFrame;
        simulationarr = arr;
        T = new Thread(this);
        T.start();
    }
    
    public void run(){
        simpleMoveChecking();
        simpleMoveCheckingDistantVersion();
        simpleMoveCheckingWithMultipleWaysOfWin();
        adjecentVersionWithMultipleWaysOfWin();
        adjacentAndDistant();
     }
     void simpleMoveChecking()
     {
         int posx[] = {-1,1,0,0,-1,1,-1,1};
        int posy[] = {0,0, 1,-1,1,-1,-1,1};
        int easyFrontx[] = {-2,2,0,0,-2,2,-2,2};
        int easyFronty[] = {0,0,2,-2,2,-2,-2,2};
        int easyBackx[] = {1,-1,0,0,1,-1,1,-1};
        int easyBacky[] = {0,0,-1,1,-1,1,1,-1}; 
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int x = i;
                int y = j;
                int a = simulationarr[i][j];
                for(int k = 0; k <= 7; k++) {
                    int closex = i + posx[k];
                    int closey = j + posy[k];
                    if(closex >= 0 && closex <= 2 && closey >= 0 && closey <= 2) {
                          int b = simulationarr[closex][closey];
                          if(a == b && a != 0) {
                              int nextx = i + easyFrontx[k];
                              int nexty = j + easyFronty[k];
                              if(nextx >= 0 && nextx <= 2 && nexty >= 0 && nexty <= 2) {
                                  int c = simulationarr[nextx][nexty];
                                  if(c == 0) {
                                      if(a == 1) {
                                          nameChange.setTitle("Server has given a good move");
                                      }
                                      if(a == 2) {
                                          nameChange.setTitle("Client has given a good move");
                                      }
                                  }
                              }
                             int anothernextx = i + easyBackx[k];
                             int anothernexty = j + easyBacky[k];
                             if(anothernextx >= 0 && anothernextx <= 2 && anothernexty >= 0 && anothernexty <= 2) {
                                  int c = simulationarr[anothernextx][anothernexty];
                                  if(c == 0) {
                                      if(a == 1) {
                                          nameChange.setTitle("Server has given a good move");
                                      }
                                      if(a == 2) {
                                          nameChange.setTitle("Client has given a good move");
                                      }
                                  }
                              }
                          }
                    }
                }
            }
        }
     }
     void simpleMoveCheckingDistantVersion()
     {
         int newPosx[] = {0,0,-2,2,-2,2,-2,2};
        int newPosy[] =  {2,-2,0,0,2,2,-2,-2};
        int midNewPosx[] = {0,0,-1,1,-1,1,-1,1};
        int midNewPosy[] = {1,-1,0,0,1,1,-1,-1};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int x = i;
                int y = j;
                int a = simulationarr[i][j];
                for(int k = 0; k <= 7; k++) {
                   int durerx = i + newPosx[k];
                   int durery = j + newPosy[k];
                   if(durerx >= 0 && durerx <= 2 && durery >= 0 && durery <= 2) {
                      int b = simulationarr[durerx][durery];
                      if(a == b && a != 0) {
                          int midx = i + midNewPosx[k];
                          int midy = j + midNewPosy[k];
                          if(midx >= 0 && midx <= 2 && midy >= 0 && midy <= 2) {
                              int c = simulationarr[midx][midy];
                              if(c == 0) {
                                  if(a == 1) {
                                      nameChange.setTitle("Server has given a good move");
                                  }
                                  if(a == 2) {
                                      nameChange.setTitle("Client has given a good move");
                                  }
                              }
                          }
                      }
                   }
                }
            }
        }
     }
     void simpleMoveCheckingWithMultipleWaysOfWin()
     {
        int dxforSingle[] = {0,0,-2,2,-2,2,-2,2};
     int dyforSingle[] = {2,-2,0,0,2,2,-2,-2};
     int dxForMid[] = {0,0,-1,1,-1,1,-1,1};
     int dyForMid[] = {1,-1,0,0,1,1,-1,-1};
     for(int i = 0; i < 3; i++) {
         for(int j = 0; j < 3; j++) {
            for(int k = 0; k <= 7; k++) {
                 int firstPointx = i;
                 int firstPointy = j;
                 int lastPointx = i + dxforSingle[k];
                 int lastPointy = j + dyforSingle[k];
                 int midPointx = i + dxForMid[k];
                 int midPointy = j + dyForMid[k];
                 
                 if(lastPointx >= 0 && lastPointy >= 0 && lastPointx <= 2 && lastPointy <= 2) {
                     //System.out.println("ase re pagla + " + i + " " + j);
                     if(midPointx >= 0 && midPointy >= 0 && midPointx <= 2 && midPointy <= 2) {
                       //  System.out.println("ase re pagla 2+ " + i + " " + j);
                       for(int l = k + 1; l <= 7; l++) {
                           int templastPointx = i + dxforSingle[l];
                           int templastPointy = j + dyforSingle[l];
                           int tempmidPointx = i + dxForMid[l];
                           int tempmidPointy = j + dyForMid[l];
                           if(templastPointx >= 0 && templastPointy >= 0 && templastPointx <= 2 && templastPointy <= 2) {
                                  if(tempmidPointx >= 0 && tempmidPointy >= 0 && tempmidPointx <= 2 && tempmidPointy <= 2) {
                                 int a = simulationarr[firstPointx][firstPointy];
                                 int b = simulationarr[lastPointx][lastPointy];
                                 int c = simulationarr[templastPointx][templastPointy]; 
                                 int midOne = simulationarr[midPointx][midPointy];
                                 int midTwo = simulationarr[tempmidPointx][tempmidPointy];
                                 //System.out.println("ase re pagla 4+ " + i + " " + j);
                                 if(a == b && b == c && midOne == 0 && midTwo == 0) {
                                  // System.out.println("hoi re ");
                                     if(a == 1) {
                                         nameChange.setTitle("Server is winning");
                                     }
                                     if(a == 2) {
                                         nameChange.setTitle("Client is winning");
                                     }
                                 }
                             }
                       }
                       }  
                     }
                 }
                 } 
            
         }
     } 
     }
     void adjecentVersionWithMultipleWaysOfWin()
     {
     int movex[] = {-1, 1, 0, 0, -1, 1, -1, 1};
     int movey[] = {0, 0, 1, -1, 1, -1, -1, 1};
     int frontx[]= {-2, 2, 0, 0, -2, 2, -2, 2};
     int fronty[]= {0, 0, 2, -2, 2, -2, -2, 2};
     int backx[] = {1, -1, 0, 0, 1, -1, 1, -1};
     int backy[] = {0, 0, -1, 1, -1, 1, 1, -1};
     int playerOneWin = 0,playerTwoWin = 0;
     for(int i = 0; i < 3; i++) {
         for(int j = 0; j < 3; j++) {
             int x = i;
             int y = j;
             for(int k = 0; k <= 7; k++) {
                 int adjOnex = x + movex[k];
                 int adjOney = y + movey[k];
                 playerOneWin = 0;
                 playerTwoWin = 0;
                 for(int l = k + 1; l <= 7; l++) {
                     int adjTwox = x + movex[l];
                     int adjTwoy = y + movey[l];
                     int frontadjOnex = x + frontx[k];
                     int frontadjOney = y + fronty[k];
                     int backadjOnex = x + backx[k];
                     int backadjOney = y + backy[k];
                     int frontadjTwox = x + frontx[l];
                     int frontadjTwoy = y + fronty[l];
                     int backadjTwox = x + backx[l];
                     int backadjTwoy = y + backy[l];
                     int mainGhor = simulationarr[i][j];
                     int a,b;
                     playerOneWin = 0;
                     playerTwoWin = 0;
                     if(adjOnex >= 0 && adjOnex <= 2 && adjOney >= 0 && adjOney <= 2 ) {
                         a = simulationarr[adjOnex][adjOney];
                         if(adjTwox >= 0 && adjTwox <= 2 && adjTwoy >= 0 && adjTwoy <= 2) {
                            b =  simulationarr[adjTwox][adjTwoy];
                            if(a == b && a == mainGhor && a != 0) {
                                if(frontadjOnex >= 0 && frontadjOnex <= 2 && frontadjOney >= 0 && frontadjOney <= 2) {
                                    int c = simulationarr[frontadjOnex][frontadjOney];
                                    if(c == 0) {
                                        if(a == 1) {
                                            playerOneWin++;
                                        }
                                        if(a == 2) {
                                            playerTwoWin++;
                                        }
                                    }
                                }
                                if(backadjOnex >= 0 && backadjOnex <= 2 && backadjOney >= 0 && backadjOney <= 2) {
                                    int c = simulationarr[backadjOnex][backadjOney];
                                    if(c == 0) {
                                        if(a == 1) {
                                            playerOneWin++;
                                        }
                                        if(a == 2) {
                                            playerTwoWin++;
                                        }
                                    }
                                }
                                if(frontadjTwox >= 0 && frontadjTwox <= 2 && frontadjTwoy >= 0 && frontadjTwoy <= 2) {
                                    int c = simulationarr[frontadjTwox][frontadjTwoy];
                                    if(c == 0) {
                                        if(a == 1) {
                                            playerOneWin++;
                                        }
                                        if(a == 2) {
                                            playerTwoWin++;
                                        }
                                    }
                                }
                                if(backadjTwox >= 0 && backadjTwox <= 2 && backadjTwoy >= 0 && backadjTwoy <= 2) {
                                    int c = simulationarr[backadjTwox][backadjTwoy];
                                    if(c == 0) {
                                        if(a == 1) {
                                            playerOneWin++;
                                        }
                                        if(a == 2) {
                                            playerTwoWin++;
                                        }
                                    }
                                }
                                
                            }
                         }
                     }
                     if(playerOneWin > playerTwoWin && playerOneWin > 1) {
                      nameChange.setTitle("Server can win");
                     }
                     if(playerOneWin < playerTwoWin && playerTwoWin > 1) {
                      nameChange.setTitle("Client can win");
                     }
                 }
             }
         }
     }
     }
     void adjacentAndDistant()
     {
     int mx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
     int my[] = {0, 0, 1, -1, 1, -1, -1, 1};
     int fx[] = {-2, 2, 0, 0, -2, 2, -2, 2};
     int fy[] = {0, 0, 2, -2, 2, -2, -2, 2};
     int bx[] = {1, -1, 0, 0, 1, -1, 1, -1};
     int by[] = {0, 0, -1, 1, -1, 1, 1, -1};
     int durerx[] =  {0,0,-2,2,-2,2,-2,2};
     int durery[] =  {2,-2,0,0,2,-2,-2,2};
    int majkhanex[]= {0,0,-1,1,-1,1,-1,1};
    int majkhaney[] = {1,-1,0,0,1,-1,-1,1};
     for(int i = 0; i < 3; i++) {
         for(int j = 0; j < 3; j++) {
             int mainx = i;
             int mainy = j;
             int a = simulationarr[mainx][mainy];
             for(int k = 0; k <= 7; k++) {
                 int adjx = i + mx[k];
                 int adjy = j + my[k];
                 if(adjx >= 0 && adjx <= 2 && adjy >= 0 && adjy <= 2) {
                     int b = simulationarr[adjx][adjy];
                     if(a == b && a != 0) {
                         int samnerx = i + fx[k];
                         int samnery = j + fy[k];
                         int pichonerx = i + bx[k];
                         int pichonery = j + by[k];
                         if(samnerx >= 0 && samnerx <= 2 && samnery >= 0 && samnery <= 2) {
                             int c = simulationarr[samnerx][samnery];
                             if(c == 0) {
                                 for(int l = 0; l <= 7; l++) {
                                     int distx = i + durerx[l];
                                     int disty = j + durery[l];
                                     int moddhox = i + majkhanex[l];
                                     int moddhoy = j + majkhaney[l];
                                     if(distx >= 0 && distx <= 2 && disty >= 0 && disty <= 2 && moddhox >= 0 && moddhoy <= 2) {
                                         int d = simulationarr[distx][disty];
                                         int e = simulationarr[moddhox][moddhoy];
                                         if(a == d && a != 0 && e == 0) {
                                             if(a == 1) {
                                                 nameChange.setTitle("Server can win");
                                             }
                                             if(a == 2) {
                                                 nameChange.setTitle("Client can win");
                                             }
                                         }
                                     }
                                 }
                             }
                         }
                         if(pichonerx >= 0 && pichonerx <= 2 && pichonery >= 0 && pichonery <= 2) {
                             int c = simulationarr[pichonerx][pichonery];
                             if(c == 0) {
                                 for(int l = 0; l <= 7; l++) {
                                     int distx = i + durerx[l];
                                     int disty = j + durery[l];
                                     int moddhox = i + majkhanex[l];
                                     int moddhoy = j + majkhaney[l];
                                     if(distx >= 0 && distx <= 2 && disty >= 0 && disty <= 2 && moddhox >= 0 && moddhoy <= 2) {
                                         int d = simulationarr[distx][disty];
                                         int e = simulationarr[moddhox][moddhoy];
                                         if(a == d && a != 0 && e == 0) {
                                             if(a == 1) {
                                                 nameChange.setTitle("Server can win");
                                             }
                                             if(a == 2) {
                                                 nameChange.setTitle("Client can win");
                                             }
                                         }
                                     }
                                 }
                             }
                         }
                     }
                 }
             }
         }
     }
     }
     }
     
    
    
     
    
    
         

