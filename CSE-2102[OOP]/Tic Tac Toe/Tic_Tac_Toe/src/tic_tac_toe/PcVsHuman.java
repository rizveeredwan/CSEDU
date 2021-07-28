package tic_tac_toe;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class PcVsHuman {
   JFrame frame; 
   JButton grid[][];
   protected int simulationarr[][];
   protected int moveCounter;
   boolean playerHasGivenMove;
   protected int guno;
   public PcVsHuman()
   {
       moveCounter = 0;
       guno = 0;
       simulationarr = new int [15][15];
       creation();
   }
  /* public void gamePlay()
   {
       
   }*/
   public void creation()
   {
       frame = new JFrame("Tic Tac Toe - Special");
       frame.setSize(1200,1200);
       frame.setVisible(true);
       frame.setLayout(new GridLayout(8,8));
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       buttonCreation();
   }
   public void buttonCreation()
   {
       grid = new JButton[15][15];
       for(int i = 0; i < 8; i++) {
           for(int j = 0; j < 8; j++) {
               ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
               simulationarr[i][j] = 0;
               grid[i][j] = new JButton();
               grid[i][j].setIcon(image);
               frame.add(grid[i][j]);
           }
       }
       player();
   }
   public void changeImage(int row, int col,int choice)
   {
       if(choice == 1) {
       ImageIcon image = new ImageIcon(getClass().getResource("x for pc.png"));
       grid[row][col].setIcon(image);
       guno++;
       WinnerComputerVsPC w = new WinnerComputerVsPC(simulationarr);
       if(w.computer == true || w.player == true) {
           WinnerFrame(w);
       }
       player();
       }
       if(choice == 2) {
           ImageIcon image = new ImageIcon(getClass().getResource("circleimage1.png"));
           grid[row][col].setIcon(image);
           WinnerComputerVsPC w = new WinnerComputerVsPC(simulationarr);
           guno++;
           if(w.computer == true || w.player == true) {
           WinnerFrame(w);
           }
           pc();
       }
       
   }
   public void player()
   {
       while(moveCounter <= 64) {
           moveCounter++;
           playerHasGivenMove = false;
           System.out.println(moveCounter + " move");
           playerMove();
           /*if(playerHasGivenMove == true) {
           pc();
           }*/
           playerHasGivenMove = false;
       }
   }
   public void pc()
   {
       PcEightByEightAlgorithm computer = new PcEightByEightAlgorithm(simulationarr);
       int row = computer.selectedRow;
       int col = computer.selectedCol;
       System.out.println(row + " " + col);
       changeImage(row,col,1);
   }
   public void playerMove()
   {
       grid[0][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][0].isEnabled() && simulationarr[0][0] == 0) {
                  simulationarr[0][0] = 2;
                  playerHasGivenMove = true;
                  changeImage(0,0,2);
                 // pc();
              }
          } 
          
       });
       grid[0][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][1].isEnabled() && simulationarr[0][1] == 0) {
                  simulationarr[0][1] = 2;
                  playerHasGivenMove = true;
                  changeImage(0,1,2);
                 // pc();
              }
          } 
      });
       grid[0][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][2].isEnabled() && simulationarr[0][2] == 0) {
                  simulationarr[0][2] = 2;
                  playerHasGivenMove = true;
                  changeImage(0,2,2);
                 // pc();
              }
          } 
      });
       grid[0][3].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][3].isEnabled() && simulationarr[0][3] == 0) {
                  simulationarr[0][3] = 2;
                  playerHasGivenMove = true;
                  changeImage(0,3,2);
                 // pc();
              }
          } 
      });
       grid[0][4].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][4].isEnabled() && simulationarr[0][4] == 0) {
                  simulationarr[0][4] = 2;
                  playerHasGivenMove = true;
                  changeImage(0,4,2);
                //  pc();
              }
          } 
      });
       grid[0][5].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][5].isEnabled() && simulationarr[0][5] == 0) {
                  simulationarr[0][5] = 2;
                  playerHasGivenMove = true;
                  changeImage(0,5,2);
                 // pc();
              }
          } 
      });
       grid[0][6].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][6].isEnabled() && simulationarr[0][6] == 0) {
                  simulationarr[0][6] = 2;
                  playerHasGivenMove = true;
                  changeImage(0,6,2);
                 // pc();
              }
          } 
      });
       grid[0][7].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][7].isEnabled() && simulationarr[0][7] == 0) {
                  simulationarr[0][7] = 2;
                  System.out.println("hoi" + simulationarr[0][7]);
                  playerHasGivenMove = true;
                  changeImage(0,7,2);
                 // pc();
              }
          } 
      });
       grid[1][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][0].isEnabled() && simulationarr[1][0] == 0) {
                  simulationarr[1][0] = 2;
                  playerHasGivenMove = true;
                  changeImage(1,0,2);
                //  pc();
              }
          } 
      });
       grid[1][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][1].isEnabled() && simulationarr[1][1] == 0) {
                  simulationarr[1][1] = 2;
                  playerHasGivenMove = true;
                  changeImage(1,1,2);
                //  pc();
              }
          } 
      });
       grid[1][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][2].isEnabled() && simulationarr[1][2] == 0) {
                  simulationarr[1][2] = 2;
                  playerHasGivenMove = true;
                  changeImage(1,2,2);
                 // pc();
              }
          } 
      });
       grid[1][3].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][3].isEnabled() && simulationarr[1][3] == 0) {
                  simulationarr[1][3] = 2;
                  playerHasGivenMove = true;
                  changeImage(1,3,2);
                 // pc();
              }
          } 
      });
       grid[1][4].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][4].isEnabled() && simulationarr[1][4] == 0) {
                  simulationarr[1][4] = 2;
                  playerHasGivenMove = true;
                  changeImage(1,4,2);
                //  pc();
              }
          } 
      });
       grid[1][5].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][5].isEnabled() && simulationarr[1][5] == 0) {
                  simulationarr[1][5] = 2;
                  playerHasGivenMove = true;
                  changeImage(1,5,2);
                //  pc();
              }
          } 
      });
       grid[1][6].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][6].isEnabled() && simulationarr[1][6] == 0) {
                  simulationarr[1][6] = 2;
                  playerHasGivenMove = true;
                  changeImage(1,6,2);
                 // pc();
              }
          } 
      });
       grid[1][7].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][7].isEnabled() && simulationarr[1][7] == 0) {
                  simulationarr[1][7] = 2;
                  playerHasGivenMove = true;
                  changeImage(1,7,2);
                 // pc();
              }
          } 
      });
       grid[2][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][0].isEnabled() && simulationarr[2][0] == 0) {
                  simulationarr[2][0] = 2;
                  playerHasGivenMove = true;
                  changeImage(2,0,2);
                 // pc();
              }
          } 
      });
       grid[2][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][1].isEnabled() && simulationarr[2][1] == 0) {
                  simulationarr[2][1] = 2;
                  playerHasGivenMove = true;
                  changeImage(2,1,2);
                //  pc();
              }
          } 
      });
       grid[2][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][2].isEnabled() && simulationarr[2][2] == 0) {
                  simulationarr[2][2] = 2;
                  playerHasGivenMove = true;
                  changeImage(2,2,2);
                //  pc();
              }
          } 
      });
       grid[2][3].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][3].isEnabled() && simulationarr[2][3] == 0) {
                  simulationarr[2][3] = 2;
                  playerHasGivenMove = true;
                  changeImage(2,3,2);
                //  pc();
              }
          } 
      });
       grid[2][4].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][4].isEnabled() && simulationarr[2][4] == 0) {
                  simulationarr[2][4] = 2;
                  playerHasGivenMove = true;
                  changeImage(2,4,2);
                //  pc();
              }
          } 
      });
       grid[2][5].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][5].isEnabled() && simulationarr[2][5] == 0) {
                  simulationarr[2][5] = 2;
                  playerHasGivenMove = true;
                  changeImage(2,5,2);
                 // pc();
              }
          } 
      });
       grid[2][6].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][6].isEnabled() && simulationarr[2][6] == 0) {
                  simulationarr[2][6] = 2;
                  playerHasGivenMove = true;
                  changeImage(2,6,2);
                 // pc();
              }
          } 
      });
       grid[2][7].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][7].isEnabled() && simulationarr[2][7] == 0) {
                  simulationarr[2][7] = 2;
                  playerHasGivenMove = true;
                  changeImage(2,7,2);
                //  pc();
              }
          } 
      });
       grid[3][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[3][0].isEnabled() && simulationarr[3][0] == 0) {
                  simulationarr[3][0] = 2;
                  playerHasGivenMove = true;
                  changeImage(3,0,2);
                //  pc();
              }
          } 
      });
       grid[3][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[3][1].isEnabled() && simulationarr[3][1] == 0) {
                  simulationarr[3][1] = 2;
                  playerHasGivenMove = true;
                  changeImage(3,1,2);
                //  pc();
              }
          } 
      });
       grid[3][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[3][2].isEnabled() && simulationarr[3][2] == 0) {
                  simulationarr[3][2] = 2;
                  playerHasGivenMove = true;
                  changeImage(3,2,2);
                //  pc();
              }
          } 
      });
       grid[3][3].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[3][3].isEnabled() && simulationarr[3][3] == 0) {
                  simulationarr[3][3] = 2;
                  playerHasGivenMove = true;
                  changeImage(3,3,2);
                 // pc();
              }
          } 
      });
       grid[3][4].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[3][4].isEnabled() && simulationarr[3][4] == 0) {
                  simulationarr[3][4] = 2;
                  playerHasGivenMove = true;
                  changeImage(3,4,2);
                 // pc();
              }
          } 
      });
       grid[3][5].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[3][5].isEnabled() && simulationarr[3][5] == 0) {
                  simulationarr[3][5] = 2;
                  playerHasGivenMove = true;
                  changeImage(3,5,2);
                //  pc();
              }
          } 
      });
       grid[3][6].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[3][6].isEnabled() && simulationarr[3][6] == 0) {
                  simulationarr[3][6] = 2;
                  playerHasGivenMove = true;
                  changeImage(3,6,2);
                //  pc();
              }
          } 
      });
       grid[3][7].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[3][7].isEnabled() && simulationarr[3][7] == 0) {
                  simulationarr[3][7] = 2;
                  playerHasGivenMove = true;
                  changeImage(3,7,2);
                //  pc();
              }
          } 
      });
       grid[4][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[4][0].isEnabled() && simulationarr[4][0] == 0) {
                  simulationarr[4][0] = 2;
                  playerHasGivenMove = true;
                  changeImage(4,0,2);
                 // pc();
              }
          } 
      });
       grid[4][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[4][1].isEnabled() && simulationarr[4][1] == 0) {
                  simulationarr[4][1] = 2;
                  playerHasGivenMove = true;
                  changeImage(4,1,2);
                 // pc();
              }
          } 
      });
       grid[4][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[4][2].isEnabled() && simulationarr[4][2] == 0) {
                  simulationarr[4][2] = 2;
                  playerHasGivenMove = true;
                  changeImage(4,2,2);
                //  pc();
              }
          } 
      });
       grid[4][3].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[4][3].isEnabled() && simulationarr[4][3] == 0) {
                  simulationarr[4][3] = 2;
                  playerHasGivenMove = true;
                  changeImage(4,3,2);
                //  pc();
              }
          } 
      });
       grid[4][4].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[4][4].isEnabled() && simulationarr[4][4] == 0) {
                  simulationarr[4][4] = 2;
                  playerHasGivenMove = true;
                  changeImage(4,4,2);
                  //pc();
              }
          } 
      });
       grid[4][5].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[4][5].isEnabled() && simulationarr[4][5] == 0) {
                  simulationarr[4][5] = 2;
                  playerHasGivenMove = true;
                  changeImage(4,5,2);
                //  pc();
              }
          } 
      });
       grid[4][6].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[4][6].isEnabled() && simulationarr[4][6] == 0) {
                  simulationarr[4][6] = 2;
                  playerHasGivenMove = true;
                  changeImage(4,6,2);
                 // pc();
              }
          } 
      });
       grid[4][7].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[4][7].isEnabled() && simulationarr[4][7] == 0) {
                  simulationarr[4][7] = 2;
                  playerHasGivenMove = true;
                  changeImage(4,7,2);
                  //pc();
              }
          } 
      });
       grid[5][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[5][0].isEnabled() && simulationarr[5][0] == 0) {
                  simulationarr[5][0] = 2;
                  playerHasGivenMove = true;
                  changeImage(5,0,2);
                //  pc();
              }
          } 
      });
       grid[5][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[5][1].isEnabled() && simulationarr[5][1] == 0) {
                  simulationarr[5][1] = 2;
                  playerHasGivenMove = true;
                  changeImage(5,1,2);
                //  pc();
              }
          } 
      });
       grid[5][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[5][2].isEnabled() && simulationarr[5][2] == 0) {
                  simulationarr[5][2] = 2;
                  playerHasGivenMove = true;
                  changeImage(5,2,2);
                //  pc();
              }
          } 
      });
       grid[5][3].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[5][3].isEnabled() && simulationarr[5][3] == 0) {
                  simulationarr[5][3] = 2;
                  playerHasGivenMove = true;
                  changeImage(5,3,2);
                  //pc();
              }
          } 
      });
       grid[5][4].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[5][4].isEnabled() && simulationarr[5][4] == 0) {
                  simulationarr[5][4] = 2;
                  playerHasGivenMove = true;
                  changeImage(5,4,2);
                  //pc();
              }
          } 
      });
       grid[5][5].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[5][5].isEnabled() && simulationarr[5][5] == 0) {
                  simulationarr[5][5] = 2;
                  playerHasGivenMove = true;
                  changeImage(5,5,2);
                 // pc();
              }
          } 
      });
       grid[5][6].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[5][6].isEnabled() && simulationarr[5][6] == 0) {
                  simulationarr[5][6] = 2;
                  playerHasGivenMove = true;
                  changeImage(5,6,2);
                 // pc();
              }
          } 
      });
       grid[5][7].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[5][7].isEnabled() && simulationarr[5][7] == 0) {
                  simulationarr[5][7] = 2;
                  playerHasGivenMove = true;
                  changeImage(5,7,2);
                  //pc();
              }
          } 
      });
       grid[6][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[6][0].isEnabled() && simulationarr[6][0] == 0) {
                  simulationarr[6][0] = 2;
                  playerHasGivenMove = true;
                  changeImage(6,0,2);
                 // pc();
              }
          } 
      });
       grid[6][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[6][1].isEnabled() && simulationarr[6][1] == 0) {
                  simulationarr[6][1] = 2;
                  playerHasGivenMove = true;
                  changeImage(6,1,2);
                 // pc();
              }
          } 
      });
       grid[6][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[6][2].isEnabled() && simulationarr[6][2] == 0) {
                  simulationarr[6][2] = 2;
                  playerHasGivenMove = true;
                  changeImage(6,2,2);
                 // pc();
              }
          } 
      });
       grid[6][3].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[6][3].isEnabled() && simulationarr[6][3] == 0) {
                  simulationarr[6][3] = 2;
                  playerHasGivenMove = true;
                  changeImage(6,3,2);
                 // pc();
              }
          } 
      });
       grid[6][4].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[6][4].isEnabled() && simulationarr[6][4] == 0) {
                  simulationarr[6][4] = 2;
                  playerHasGivenMove = true;
                  changeImage(6,4,2);
                 // pc();
              }
          } 
      });
       grid[6][5].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[6][5].isEnabled() && simulationarr[6][5] == 0) {
                  simulationarr[6][5] = 2;
                  playerHasGivenMove = true;
                  changeImage(6,5,2);
                 // pc();
              }
          } 
      });
       grid[6][6].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[6][6].isEnabled() && simulationarr[6][6] == 0) {
                  simulationarr[6][6] = 2;
                  playerHasGivenMove = true;
                  changeImage(6,6,2);
                 // pc();
              }
          } 
      });
       grid[6][7].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[6][7].isEnabled() && simulationarr[6][7] == 0) {
                  simulationarr[6][7] = 2;
                  playerHasGivenMove = true;
                  changeImage(6,7,2);
                //  pc();
              }
          } 
      });
       grid[7][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[7][0].isEnabled() && simulationarr[7][0] == 0) {
                  simulationarr[7][0] = 2;
                  playerHasGivenMove = true;
                  changeImage(7,0,2);
                 // pc();
              }
          } 
      });
       grid[7][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[7][1].isEnabled() && simulationarr[7][1] == 0) {
                  simulationarr[7][1] = 2;
                  playerHasGivenMove = true;
                  changeImage(7,1,2);
                  //pc();
              }
          } 
      });
       grid[7][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[7][2].isEnabled() && simulationarr[7][2] == 0) {
                  simulationarr[7][2] = 2;
                  playerHasGivenMove = true;
                  changeImage(7,2,2);
                 // pc();
              }
          } 
      });
       grid[7][3].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[7][3].isEnabled() && simulationarr[7][3] == 0) {
                  simulationarr[7][3] = 2;
                  playerHasGivenMove = true;
                  changeImage(7,3,2);
                  //pc();
              }
          } 
      });
       grid[7][4].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[7][4].isEnabled() && simulationarr[7][4] == 0) {
                  simulationarr[7][4] = 2;
                  playerHasGivenMove = true;
                  changeImage(7,4,2);
                  //pc();
              }
          } 
      });
       grid[7][5].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[7][5].isEnabled() && simulationarr[7][5] == 0) {
                  simulationarr[7][5] = 2;
                  playerHasGivenMove = true;
                  changeImage(7,5,2);
                  //pc();
              }
          } 
      });
       grid[7][6].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[7][6].isEnabled() && simulationarr[7][6] == 0) {
                  simulationarr[7][6] = 2;
                  playerHasGivenMove = true;
                  changeImage(7,6,2);
                  //pc();
              }
          } 
      });
       grid[7][7].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[7][7].isEnabled() && simulationarr[7][7] == 0) {
                  simulationarr[7][7] = 2;
                  playerHasGivenMove = true;
                  changeImage(7,7,2);
                  //pc();
              }
          } 
      });
}
   public void WinnerFrame(WinnerComputerVsPC w)
   {
       JFrame finalFrame = new JFrame("Match Result: Computer Vs Player");
       JPanel finalPanel = new JPanel();
       JLabel text = new JLabel();
       finalFrame.setSize(300,200);
       finalFrame.setVisible(true);
       finalFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       String winner = "",process = "";
       if(w.computer == true) winner = "Computer";
       if(w.player == true) winner = "Player";
       if(w.computer == false && w.player == false && guno >= 64) {
          text.setText("Match is Drawn");
          JButton button = new JButton("Exit");
          button.addActionListener(new ActionListener(){
           public void actionPerformed(ActionEvent e) {
               if(button.isEnabled()) {
                   int v = 0;
                   System.exit(v);
               }
           }
          });
          finalPanel.add(text);
          finalFrame.add(finalPanel);
          finalPanel.add(button);
       }
       else {
           if(w.horizontal == true) text.setText(winner + " wins by horizontal move");
           if(w.vertical == true) text.setText(winner + " wins by vertical move");
           if(w.diagonalLeft == true) text.setText(winner + " wins by left Diagonal move");
           if(w.diagonalRight == true) text.setText(winner + " wins by right Diagonal move");
           if(w.fourByTwo == true) text.setText(winner + " wins by four by two move");
           if(w.twoByFour == true) text.setText(winner + " wins by two by four move");
           JButton button = new JButton("Exit");
          button.addActionListener(new ActionListener(){
           public void actionPerformed(ActionEvent e) {
               if(button.isEnabled()) {
                   int v = 0;
                   System.exit(v);
               }
           }
          });
          finalPanel.add(text);
          finalFrame.add(finalPanel);
          finalPanel.add(button);
       }
       
       
   }
}
