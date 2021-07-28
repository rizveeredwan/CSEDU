package clienttictactoe;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.*;
import java.io.*;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
public class ClientTicTacToe {
    JFrame clientFrame;
    JButton grid[][];
    String bitString;
    int counter;
    int simulationarr[][];
    boolean playerOneWin = false;
    boolean playerTwoWin = false;
    protected String Sender = "localhost";
    protected int portNumber = 786;
    public static void main(String[] args) throws Exception{
        
        ClientTicTacToe clienttictactoe = new ClientTicTacToe();
        clienttictactoe.takeInput(clienttictactoe);
        clienttictactoe.creation(clienttictactoe);
                
        
        
    }
    public void creation(ClientTicTacToe clienttictactoe) throws Exception
    {
        
        simulationarr = new int[10][10];
        clientFrame = new JFrame("Client Window");
        clientFrame.setSize(700,700);
        clientFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        clientFrame.setLayout(new GridLayout(3,3));
        clientFrame.setBackground(Color.yellow);
        grid = new JButton[10][10];
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
                grid[i][j] = new JButton(image);
                clientFrame.add(grid[i][j]);
            }
        }
        
       clienttictactoe.run();
    }
    void perfectingTheScenario()
    {
        int row = 0,col = 0;
        
        for(int i = 1; i < bitString.length(); i++) {
            if(i <= 3) {
             row = 0;   
            }
            else if(i <= 6) {
                row = 1;
            }
            else if(i <= 9) {
                row = 2;
            }
            int d = i - 1;
            simulationarr[row][d%3] = bitString.charAt(i) - '0';
            //System.out.println(simulationarr[row][d%3] + " " + row + " " + d%3);
        }
       for(int i = 0; i < 3; i++) {
           for(int j = 0; j < 3; j++) {
               if(simulationarr[i][j] == 0) {
                   ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
                   grid[i][j].setIcon(image);
               }
               if(simulationarr[i][j] == 1) {
                   ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                   grid[i][j].setIcon(image);
               }
               if(simulationarr[i][j] == 2) {
                 ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                 grid[i][j] = new JButton(image);
              }
           }
       }
      // System.out.println("bitString = " + bitString);
    }
    void bitStringChange()
    {
        counter = counter + 1;
        char a = (char) (counter + '0');
        bitString = "";
        bitString = bitString + a;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                a = (char) (simulationarr[i][j] + '0');
                bitString = bitString + a;
            }
        }
        
    }
    public void run() throws Exception {
        Socket socket;
        socket = new Socket(Sender,portNumber);
        boolean program = true;
        counter = 0;
           while(program) {
            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            bitString = "";
            bitString = in.readUTF();
            counter  = bitString.charAt(0) - '0';
            perfectingTheScenario();
            WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                 playerOneWin = w.playerOne;
                 playerTwoWin = w.playerTwo;
                 Intelligence intelligent = new Intelligence(simulationarr,clientFrame);
                 if(playerOneWin == true) {
                     out.writeUTF(bitString);
                     showForWinnerOne();
                 }
                 else if(playerTwoWin == true) {
                     out.writeUTF(bitString);
                     showForWinnerTwo();
                 }
            if(counter == 9) {
               // System.out.println("dh");
                 out.writeUTF(bitString);
                 WinnerDeterminator m = new WinnerDeterminator(simulationarr);
                 playerOneWin = m.playerOne;
                 playerTwoWin = m.playerTwo;
                 Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                 if(playerOneWin == true) {
                     showForWinnerOne();
                 }
                 if(playerTwoWin == true) {
                     showForWinnerTwo();
                 }
                 else {
                     if(playerOneWin == false && playerTwoWin == false) {
                     clientFrame.setTitle("Draw !!!");
                     }
                 }
                 
            }
            clientFrame.setVisible(true);
            if(counter < 9) clientFrame.setTitle("Client");
            grid[0][0].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[0][0].isEnabled() && simulationarr[0][0] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[0][0].setIcon(image);
                    simulationarr[0][0] = 2;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo; 
                      
                      try {
                          bitStringChange();
                         // System.out.println(bitString + "    1");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
           
            grid[0][1].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[0][1].isEnabled() && simulationarr[0][1] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[0][1].setIcon(image);
                    simulationarr[0][1] = 2;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                      
                  //  System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                      try {
                          bitStringChange();
                          //System.out.println(bitString + "    2");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
            
            grid[0][2].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[0][2].isEnabled() && simulationarr[0][2] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[0][2].setIcon(image);
                    simulationarr[0][2] = 2;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    
                   // System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                      try {
                          bitStringChange();
                          System.out.println(bitString + "    2");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
           
            grid[1][0].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[1][0].isEnabled() && simulationarr[1][0] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[1][0].setIcon(image);
                    simulationarr[1][0] = 2;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    
                      try {
                          bitStringChange();
                         // System.out.println(bitString + "    4");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
            
            grid[1][1].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[1][1].isEnabled() && simulationarr[1][1] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[1][1].setIcon(image);
                    simulationarr[1][1] = 2;
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                   // System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                   
                      try {
                          bitStringChange();
                         // System.out.println(bitString+ "    5");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
          
            grid[1][2].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[1][2].isEnabled() && simulationarr[1][2] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[1][2].setIcon(image);
                    simulationarr[1][2] = 2;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    
                   // System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                      try {
                          bitStringChange();
                         // System.out.println(bitString+ "    6");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
            
            
            grid[2][0].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[2][0].isEnabled() && simulationarr[2][0] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[2][0].setIcon(image);
                    simulationarr[2][0] = 2;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                   // System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                   
                      try {
                          bitStringChange();
                         // System.out.println(bitString+ "    7");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
            grid[2][1].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[2][1].isEnabled() && simulationarr[2][1] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[2][1].setIcon(image);
                    simulationarr[2][1] = 2;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    
                    //System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                      try {
                          bitStringChange();
                         // System.out.println(bitString+ "    8");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
            grid[2][2].addActionListener(new ActionListener(){
              public void actionPerformed(ActionEvent e) {
                  if(grid[2][2].isEnabled() && simulationarr[2][2] == 0) {
                    ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                    grid[2][2].setIcon(image);
                    simulationarr[2][2] = 2;
                    try {
                          Intelligence intelligence = new Intelligence(simulationarr,clientFrame);
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                    WinnerDeterminator w = new WinnerDeterminator(simulationarr);
                    playerOneWin = w.playerOne;
                    playerTwoWin = w.playerTwo;
                    
                    //System.out.println("one = " + w.playerOne + " " + w.playerTwo);
                      try {
                          bitStringChange();
                         // System.out.println(bitString + "    9");
                          out.writeUTF(bitString);
                          if(playerOneWin == true) showForWinnerOne();
                          if(playerTwoWin == true) showForWinnerTwo();
                      } catch (Exception ex) {
                          Logger.getLogger(ClientTicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                      }
                      
                    
                  }
              }
            });
            
           }
        
    }
    void showForWinnerOne()
    {
        JFrame finalFrame = new JFrame("Winner : Server");
        finalFrame.setSize(700,700);
        finalFrame.setLayout(new GridLayout(3,3));
        finalFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JButton group[][];
        int changeDitector[][];
        changeDitector = simulationarr;
        group = new JButton[10][10];
        if(simulationarr[0][0] == 1 && simulationarr[1][1] == 1 && simulationarr[2][2] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][2] = -1;
         
      }
      else if(simulationarr[0][2] == 1 && simulationarr[1][1] == 1 && simulationarr[2][0] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][2] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][0] = new JButton(image);
         changeDitector[0][2] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][0] = -1;
         
         
      }
      else if(simulationarr[0][0] == 1 && simulationarr[1][0] == 1 && simulationarr[2][0] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[1][0] = new JButton(image);
         group[2][0] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[1][0] = -1;
         changeDitector[2][0] = -1;
              }
      else if(simulationarr[0][1] == 1 && simulationarr[1][1] == 1 && simulationarr[2][1] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][1] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][1] = new JButton(image);
         changeDitector[0][1] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][1] = -1;
         
      }
      else if(simulationarr[0][2] == 1 && simulationarr[1][2] == 1 && simulationarr[2][2] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][2] = new JButton(image);
         group[1][2] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[0][2] = -1;
         changeDitector[1][2] = -1;
         changeDitector[2][2] = -1;
         
      }
      else if(simulationarr[0][0] == 1 && simulationarr[0][1] == 1 && simulationarr[0][2] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[0][1] = new JButton(image);
         group[0][2] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[0][1] = -1;
         changeDitector[0][2] = -1;
        }
      else if(simulationarr[1][0] == 1 && simulationarr[1][1] == 1 && simulationarr[1][2] == 1) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[1][0] = new JButton(image);
         group[1][1] = new JButton(image);
         group[1][2] = new JButton(image);
         changeDitector[1][0] = -1;
         changeDitector[1][1] = -1;
         changeDitector[1][2] = -1;
        
      }
      else if(simulationarr[2][0] == 1 && simulationarr[2][1] == 1 && simulationarr[2][2] == 1) {
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
                  
                   finalFrame.add(group[i][j]);
                   continue;
               }
              else if(simulationarr[i][j] == 0 && changeDitector[i][j] != -1) {
                  
                   ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
              else if(simulationarr[i][j] == 1  && changeDitector[i][j] != -1) {
                   
                   ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
              else if(simulationarr[i][j] == 2 && changeDitector[i][j] != -1) {
                   
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
        changeDitector = simulationarr;
        group = new JButton[10][10];
        if(simulationarr[0][0] == 2 && simulationarr[1][1] == 2 && simulationarr[2][2] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][2] = -1;
         
      }
      else if(simulationarr[0][2] == 2 && simulationarr[1][1] == 2 && simulationarr[2][0] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][2] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][0] = new JButton(image);
         changeDitector[0][2] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][0] = -1;
         
         
      }
      else if(simulationarr[0][0] == 2 && simulationarr[1][0] == 2 && simulationarr[2][0] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[1][0] = new JButton(image);
         group[2][0] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[1][0] = -1;
         changeDitector[2][0] = -1;
              }
      else if(simulationarr[0][1] == 2 && simulationarr[1][1] == 2 && simulationarr[2][1] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][1] = new JButton(image);
         group[1][1] = new JButton(image);
         group[2][1] = new JButton(image);
         changeDitector[0][1] = -1;
         changeDitector[1][1] = -1;
         changeDitector[2][1] = -1;
         
      }
      else if(simulationarr[0][2] == 2 && simulationarr[1][2] == 2 && simulationarr[2][2] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][2] = new JButton(image);
         group[1][2] = new JButton(image);
         group[2][2] = new JButton(image);
         changeDitector[0][2] = -1;
         changeDitector[1][2] = -1;
         changeDitector[2][2] = -1;
         
      }
      else if(simulationarr[0][0] == 2 && simulationarr[0][1] == 2 && simulationarr[0][2] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[0][0] = new JButton(image);
         group[0][1] = new JButton(image);
         group[0][2] = new JButton(image);
         changeDitector[0][0] = -1;
         changeDitector[0][1] = -1;
         changeDitector[0][2] = -1;
        }
      else if(simulationarr[1][0] == 2 && simulationarr[1][1] == 2 && simulationarr[1][2] == 2) {
         ImageIcon image = new  ImageIcon(getClass().getResource("finalimage.png"));
         group[1][0] = new JButton(image);
         group[1][1] = new JButton(image);
         group[1][2] = new JButton(image);
         changeDitector[1][0] = -1;
         changeDitector[1][1] = -1;
         changeDitector[1][2] = -1;
        
      }
      else if(simulationarr[2][0] == 2 && simulationarr[2][1] == 2 && simulationarr[2][2] == 2) {
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
              else if(simulationarr[i][j] == 0 && changeDitector[i][j] != -1) {
                  //System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("firstlook.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
              else if(simulationarr[i][j] == 1  && changeDitector[i][j] != -1) {
                  // System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("atlast.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
              else if(simulationarr[i][j] == 2 && changeDitector[i][j] != -1) {
                //  System.out.println("hai = " + i + " " + j);
                   ImageIcon image = new ImageIcon(getClass().getResource("circleimage.jpg"));
                   group[i][j] = new JButton(image);
                   finalFrame.add(group[i][j]);
               }
           }
       }
        
        finalFrame.setVisible(true);    
    }
    void takeInput(ClientTicTacToe clienttictactoe)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Give the name of local host");
        Sender = scan.next();
        
    }
    
            
    
}

