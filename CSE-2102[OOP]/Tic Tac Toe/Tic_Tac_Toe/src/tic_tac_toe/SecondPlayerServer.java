package tic_tac_toe;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;

public class SecondPlayerServer {
  protected String bitString;
  ServerSocket serversocket;
  Socket socket;
  DataInputStream in;
  DataOutputStream out;
  protected int counter;
  JFrame serverFrame;
  JButton grid[][];
  JPanel panel;
  protected int situationarr[][];
  boolean playerOneWin;
  boolean playerTwoWin;
  public SecondPlayerServer() throws Exception
  {
      counter = 0;
      playerOneWin = false;
      playerTwoWin = false;
      situationarr = new int [10][10];
      char a = (char)(counter + '0');
      bitString = "";
      bitString = bitString + a;
      bitString = bitString + "000000000";
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
              situationarr[i][j] = 0;
          }
      }
        ServerSocket serversocket  = new ServerSocket(786);
        Socket socket = serversocket.accept();
        in = new DataInputStream(socket.getInputStream());
        out = new DataOutputStream(socket.getOutputStream());
        this.run();
  }
  public void situationCheck()
  {
      int row = 0,col = 0;
      
      for(int i = 1; i <bitString.length(); i++) {
          char a = bitString.charAt(i);
          //System.out.println("char = " + a);
          int b = a - '0';
          if(i <= 3) row = 0;
          else if(i <= 6) row = 1;
          else if(i <= 9) row = 2;
          situationarr[row][col] = b;
          
          col++;
          if(col > 2) col = 0;
        
      }
  }
  public void riImageLoading()
  {
      //System.out.println("check kori = " + bitString);
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
              int b = situationarr[i][j];
              //System.out.println("b  = " + b);
            int row = i,col = j;
              switch (b) {
                  case 0:
                      {
                          ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
                          grid[i][j].setIcon(image);
                          break;
                      }
                  case 1:
                      {
                          ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                          grid[i][j].setIcon(image);
                          break;
                      }
                  case 2: 
                      {
                          ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                          grid[row][col].setIcon(image);
                          break;
                      }
                  default:
                      break;
              }
          }
      }
  }
  public void constructionOfServerWindow()
  {
      situationCheck();
      serverFrame = new JFrame("Server window");
      serverFrame.setSize(700,700);
      serverFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      serverFrame.setLayout(new GridLayout(3,3));
      serverFrame.setBackground(Color.YELLOW);
      grid = new JButton[10][10];
      for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
               if(situationarr[i][j] == 0) {
                ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
                grid[i][j] = new JButton(image);
              }
              if(situationarr[i][j] == 1) {
                 ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                 grid[i][j] = new JButton(image);
              }
             if(situationarr[i][j] == 2) {
                 ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                 grid[i][j] = new JButton(image);
              }
             serverFrame.add(grid[i][j]);
          }
      }
     // serverFrame.setVisible(true);
      try {
       //   work();
      } catch (Exception ex) {
          Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
      }
      
  
  }
  void run() throws Exception
  {
      
      if(counter == 0) {
          constructionOfServerWindow();
          out.writeUTF(bitString);
          bitString = in.readUTF();
          System.out.println("ase " + bitString);
          work();
      }
      
  }
  public void work() throws Exception
  {
      
          situationCheck();
          riImageLoading();
          serverFrame.setVisible(true);
          Intelligence m = new Intelligence(situationarr,serverFrame);
          WinnerDeterminator p = new WinnerDeterminator(situationarr);
          playerOneWin = p.playerOne;
          playerTwoWin = p.playerTwo;
          if(playerOneWin == true) {
              showForWinnerOne();
          }
          if(playerTwoWin == true) {
              showForWinnerTwo();
          }
          int flag = 0;
          if(counter > 9) {
              if(playerOneWin == false  && playerTwoWin == false)serverFrame.setTitle("Draw !!!");
              flag = 1;
          }
          
         serverFrame.setTitle("Server");
          
          serverFrame.setVisible(true);
          grid[0][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][0].isEnabled() && situationarr[0][0] == 0) {
                   System.out.println("Workdone in 1");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                    grid[0][0].setIcon(image);
                    situationarr[0][0] = 1;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                    WinnerDeterminator w = new WinnerDeterminator(situationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                     
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          
          });
          grid[0][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][1].isEnabled() && situationarr[0][1] == 0) {
                  System.out.println("Workdone");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                  grid[0][1].setIcon(image);
                  situationarr[0][1] = 1;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                    WinnerDeterminator w = new WinnerDeterminator(situationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                     
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          
          });
          grid[0][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[0][2].isEnabled() && situationarr[0][2] == 0) {
                  System.out.println("Workdone 3");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                  grid[0][2].setIcon(image);
                  situationarr[0][2] = 1;
                  WinnerDeterminator w = new WinnerDeterminator(situationarr);
                  playerOneWin = w.playerOne;
                  playerTwoWin = w.playerTwo;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                  System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                     
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          
          });
          grid[1][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][0].isEnabled() && situationarr[1][0] == 0) {
                  System.out.println("Workdone");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                  grid[1][0].setIcon(image);
                  situationarr[1][0] = 1;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                  WinnerDeterminator w = new WinnerDeterminator(situationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                      
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          
          });
          grid[1][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][1].isEnabled() && situationarr[1][1] == 0) {
                  System.out.println("Workdone");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                  grid[1][1].setIcon(image);
                  situationarr[1][1] = 1;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                  WinnerDeterminator w = new WinnerDeterminator(situationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                     
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          });
          grid[1][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[1][2].isEnabled() && situationarr[1][2] == 0) {
                  System.out.println("Workdone");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                  grid[1][2].setIcon(image);
                  situationarr[1][2] = 1;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                  WinnerDeterminator w = new WinnerDeterminator(situationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                      
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          });
          grid[2][0].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][0].isEnabled() && situationarr[2][0] == 0) {
                  System.out.println("Workdone");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                  grid[2][0].setIcon(image);
                  situationarr[2][0] = 1;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                  WinnerDeterminator w = new WinnerDeterminator(situationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                      
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          });
          grid[2][1].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][1].isEnabled() && situationarr[2][1] == 0) {
                  System.out.println("Workdone");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                  grid[2][1].setIcon(image);
                  situationarr[2][1] = 1;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                 WinnerDeterminator w = new WinnerDeterminator(situationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                      
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          
          });
        grid[2][2].addActionListener(new ActionListener(){
          public void actionPerformed(ActionEvent e) {
              if(grid[2][2].isEnabled() && situationarr[2][2] == 0) {
                  System.out.println("Workdone");
                  ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                  grid[2][2].setIcon(image);
                  situationarr[2][2] = 1;
                  try {
                      Intelligence clever = new Intelligence(situationarr,serverFrame);
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
                  WinnerDeterminator w = new WinnerDeterminator(situationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                  try {
                      bitStringFormatAndSend();
                      
                  } catch (Exception ex) {
                      Logger.getLogger(FirstPlayerServer.class.getName()).log(Level.SEVERE, null, ex);
                  }
              }
          }
          
          });
       
  }
  void showForWinnerOne()
    {
        JFrame finalFrame = new JFrame("Winner : Server");
        finalFrame.setSize(700,700);
        finalFrame.setLayout(new GridLayout(3,3));
        finalFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JButton group[][];
        int changeDitector[][];
        changeDitector = situationarr;
        group = new JButton[10][10];
        if(situationarr[0][0] == 1 && situationarr[1][1] == 1 && situationarr[2][2] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][2] = -1;
         
      }
      else if(situationarr[0][2] == 1 && situationarr[1][1] == 1 && situationarr[2][0] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][2] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][0] = new JButton(image);
         changeDitector[0][2] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][0] = -1;
         
         
      }
      else if(situationarr[0][0] == 1 && situationarr[1][0] == 1 && situationarr[2][0] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[1][0] = new JButton(image);
         group[2][0] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[1][0] = -1;
         changeDitector[2][0] = -1;
              }
      else if(situationarr[0][1] == 1 && situationarr[1][1] == 1 && situationarr[2][1] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][1] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][1] = new JButton(image);
         changeDitector[0][1] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][1] = -1;
         
      }
      else if(situationarr[0][2] == 1 && situationarr[1][2] == 1 && situationarr[2][2] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][2] = new JButton(image);
         group[1][2] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[0][2] = -1;
         changeDitector[1][2] = -1;
         changeDitector[2][2] = -1;
         
      }
      else if(situationarr[0][0] == 1 && situationarr[0][1] == 1 && situationarr[0][2] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[0][1] = new JButton(image);
         group[0][2] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[0][1] = -1;
         changeDitector[0][2] = -1;
        }
      else if(situationarr[1][0] == 1 && situationarr[1][1] == 1 && situationarr[1][2] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[1][0] = new JButton(image);
         group[1][1] = new JButton(image);
         group[1][2] = new JButton(image);
         changeDitector[1][0] = -1;
         changeDitector[1][1] = -1;
         changeDitector[1][2] = -1;
        
      }
      else if(situationarr[2][0] == 1 && situationarr[2][1] == 1 && situationarr[2][2] == 1) {
          ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[2][0] = new JButton(image);
         group[2][1] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[2][0] = -1;
         changeDitector[2][1] = -1;
         changeDitector[2][2] = -1;
         
      }
       for(int i = 0; i < 3; i++) {
           for(int j = 0; j < 3; j++) {
               if(changeDitector[i][j] == -1){
                   System.out.println(" lol  " + i + " " + j);
                   finalFrame.add(group[i][j]);
                   continue;
               }
              else if(situationarr[i][j] == 0 && changeDitector[i][j] != -1) {
                  System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
              else if(situationarr[i][j] == 1  && changeDitector[i][j] != -1) {
                   System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
              else if(situationarr[i][j] == 2 && changeDitector[i][j] != -1) {
                  System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
           }
       }
        
        finalFrame.setVisible(true);
    }
    void showForWinnerTwo()
    {
        JFrame finalFrame = new JFrame("Winner : Client");
        finalFrame.setSize(700,700);
        finalFrame.setLayout(new GridLayout(3,3));
        finalFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JButton group[][];
        int changeDitector[][];
        changeDitector = situationarr;
        group = new JButton[10][10];
        if(situationarr[0][0] == 2 && situationarr[1][1] == 2 && situationarr[2][2] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][2] = -1;
         
      }
      else if(situationarr[0][2] == 2 && situationarr[1][1] == 2 && situationarr[2][0] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][2] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][0] = new JButton(image);
         changeDitector[0][2] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][0] = -1;
         
         
      }
      else if(situationarr[0][0] == 2 && situationarr[1][0] == 2 && situationarr[2][0] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[1][0] = new JButton(image);
         group[2][0] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[1][0] = -1;
         changeDitector[2][0] = -1;
              }
      else if(situationarr[0][1] == 2 && situationarr[1][1] == 2 && situationarr[2][1] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][1] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][1] = new JButton(image);
         changeDitector[0][1] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][1] = -1;
         
      }
      else if(situationarr[0][2] == 2 && situationarr[1][2] == 2 && situationarr[2][2] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][2] = new JButton(image);
         group[1][2] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[0][2] = -1;
         changeDitector[1][2] = -1;
         changeDitector[2][2] = -1;
         
      }
      else if(situationarr[0][0] == 2 && situationarr[0][1] == 2 && situationarr[0][2] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[0][1] = new JButton(image);
         group[0][2] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[0][1] = -1;
         changeDitector[0][2] = -1;
        }
      else if(situationarr[1][0] == 2 && situationarr[1][1] == 2 && situationarr[1][2] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[1][0] = new JButton(image);
         group[1][1] = new JButton(image);
         group[1][2] = new JButton(image);
         changeDitector[1][0] = -1;
         changeDitector[1][1] = -1;
         changeDitector[1][2] = -1;
        
      }
      else if(situationarr[2][0] == 2 && situationarr[2][1] == 2 && situationarr[2][2] == 2) {
          ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[2][0] = new JButton(image);
         group[2][1] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[2][0] = -1;
         changeDitector[2][1] = -1;
         changeDitector[2][2] = -1;
         
      }
       for(int i = 0; i < 3; i++) {
           for(int j = 0; j < 3; j++) {
               if(changeDitector[i][j] == -1){
                   //System.out.println(" lol  " + i + " " + j);
                   finalFrame.add(group[i][j]);
                   continue;
               }
              else if(situationarr[i][j] == 0 && changeDitector[i][j] != -1) {
                  //System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
              else if(situationarr[i][j] == 1  && changeDitector[i][j] != -1) {
                  // System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
              else if(situationarr[i][j] == 2 && changeDitector[i][j] != -1) {
                //  System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
           }
       }
        
        finalFrame.setVisible(true);    
    }
    void bitStringFormatAndSend() throws Exception
    {
        System.out.println("chole = " + bitString);
        char a = bitString.charAt(0);
        bitString = "";
        counter = a - '0';
        counter = counter + 1;
        a = (char) (counter + '0');
        bitString = bitString + a;
        for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
            a = (char) (situationarr[i][j] + '0');
            bitString = bitString + a;
         }
        }
        System.out.println(" pathabo = " + bitString);
       out.writeUTF(bitString);
       bitString = in.readUTF();
       int v = bitString.charAt(0) - '0';
        if(playerOneWin == true) {
                showForWinnerOne();
            }
            if(playerTwoWin == true) {
                showForWinnerTwo();
       }
       if(v <= 8) {
       work();
       }
       if(v == 9) {
          situationCheck();
          riImageLoading();
          WinnerDeterminator w = new WinnerDeterminator(situationarr);
          playerOneWin = w.playerOne;
          playerTwoWin = w.playerTwo;
          if(playerOneWin == true) {
              showForWinnerOne();
          }
          if(playerTwoWin == true) {
              showForWinnerTwo();
          }
          if(playerOneWin == false && playerTwoWin == false) {
              serverFrame.setTitle("Draw !!!");
              out.writeUTF(bitString);
          }
       }
       
      
    }
}
