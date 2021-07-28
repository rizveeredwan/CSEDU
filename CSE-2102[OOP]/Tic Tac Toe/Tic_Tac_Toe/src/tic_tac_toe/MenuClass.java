package tic_tac_toe;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
public class MenuClass {
   JFrame menuFrame;
   JButton grid[][];
   public MenuClass()
   {
         menuFrame = new JFrame("Select");
         menuFrame.setSize(540,500);
         menuFrame.setLayout(new GridLayout(6,1));
         menuFrame.setVisible(true);
         menuFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
         grid = new JButton[8][3];
         for(int i = 0; i < 6; i++) {
             for(int j = 0; j < 1; j++) {
                 grid[i][j] = new JButton();
                 menuFrame.add(grid[i][j]);
             }
         }
         ImageIcon image = new ImageIcon(getClass().getResource("menuimage1.png"));
         grid[0][0].setIcon(image);
         image = new ImageIcon(getClass().getResource("menuimage2.png"));
         grid[1][0].setIcon(image);
         image = new ImageIcon(getClass().getResource("menuimage4.png"));
         grid[2][0].setIcon(image);
         image = new ImageIcon(getClass().getResource("menuimage5.png"));
         grid[3][0].setIcon(image);
         image = new ImageIcon(getClass().getResource("menuimage6.png"));
         grid[4][0].setIcon(image);
         image = new ImageIcon(getClass().getResource("menuimage7.png"));
         grid[5][0].setIcon(image);
         selection();
         
   }
   void selection()
   {
       grid[0][0].addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
         if(grid[0][0].isEnabled()) {
             try {
                 menuFrame.setVisible(false);
                 new StartGame(1);
             } catch (Exception ex) {
                 Logger.getLogger(MenuClass.class.getName()).log(Level.SEVERE, null, ex);
             }
         }   
        }
       });
       grid[1][0].addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
         if(grid[1][0].isEnabled()) {
             try {
                 menuFrame.setVisible(false);
                 new StartGame(2);
             } catch (Exception ex) {
                 Logger.getLogger(MenuClass.class.getName()).log(Level.SEVERE, null, ex);
             }
         }   
        }
       });
       grid[2][0].addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
         if(grid[2][0].isEnabled()) {
             try {
                 menuFrame.setVisible(false);
                 new StartGame(3);
             } catch (Exception ex) {
                 Logger.getLogger(MenuClass.class.getName()).log(Level.SEVERE, null, ex);
             }
         }   
        }
       });
       grid[3][0].addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
         if(grid[3][0].isEnabled()) {
             try {
                 menuFrame.setVisible(false);
                 Instruction();
             } catch (Exception ex) {
                 Logger.getLogger(MenuClass.class.getName()).log(Level.SEVERE, null, ex);
             }
         }   
        }
       });
       grid[4][0].addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
         if(grid[4][0].isEnabled()) {
             try {
                 menuFrame.setVisible(false);
                 instructionTwo();
             } catch (Exception ex) {
                 Logger.getLogger(MenuClass.class.getName()).log(Level.SEVERE, null, ex);
             }
         }   
        }
       });
       grid[5][0].addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
         if(grid[5][0].isEnabled()) {
             try {
                 menuFrame.setVisible(false);
                 instructionTwo();
             } catch (Exception ex) {
                 Logger.getLogger(MenuClass.class.getName()).log(Level.SEVERE, null, ex);
             }
         }   
        }
       });

   }
   void Instruction()
   {
       JFrame f = new JFrame("3 by 3 Rules");
       f.setSize(450,450);
       f.setVisible(true);
       f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       JPanel p = new JPanel();
       JLabel lineOne = new JLabel("Any Horizontal or Vertical or diagonal matched will define the winner.");
       JLabel lineTwo = new JLabel("To play , first open the main tic_tac_toe file");
       JLabel lineThree = new JLabel("Then open the client");
       JLabel lineFour = new JLabel("To play server as first player open ClientTicTacToe file");
       JLabel lineFive = new JLabel("To play client as first player open ClientTicTacToeFirst");
       p.add(lineOne);
       p.add(lineTwo);
       p.add(lineThree);
       p.add(lineFour);
       p.add(lineFive);
       JButton b = new JButton("Back");
       p.add(b);
       f.add(p);
       b.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            if(b.isEnabled()== true) {
               // menuFrame.setVisible(false);
                f.setVisible(false);
                new MenuClass();
            }
        }
       });
   }
   void instructionTwo()
   {
       JFrame f = new JFrame("8 X 8");
       f.setVisible(true);
       f.setSize(400,400);
       f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       JPanel p = new JPanel();
       JLabel lineOne = new JLabel("Any Consecutive eight square will give you the winning");
       JLabel lineOnePrime = new JLabel("Horizontal,vertical,diagonal,two row four col or four row two col");
       JLabel lineTwo = new JLabel("Player will give the first move");
       JLabel lineThree = new JLabel("Don't give more than one move in a turn.It is unethical");
       JButton b = new JButton("Back");
       p.add(lineOne);
       p.add(lineOnePrime);
       p.add(lineTwo);
       p.add(lineThree);
       p.add(b);
       f.add(p);
       b.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            if(b.isEnabled()== true) {
               // menuFrame.setVisible(false);
                f.setVisible(false);
                new MenuClass();
            }
        }
       });
   }
   void lastInstruction()
   {
       JFrame f = new JFrame("Socket connection");
       f.setVisible(true);
       f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       JPanel p = new JPanel();
       JLabel l = new JLabel("The 3 by 3 is a online game.And so it can take local hosts.To play first always run the tic_tac_toe file");
       JLabel l2 = new JLabel("To play server as first player open ClientTicTacToe file");
       JLabel l3 =new JLabel("To play client as the first player oen clientTicTacToe File");
       JButton b = new JButton("Back");
       b.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
            if(b.isEnabled()== true) {
               // menuFrame.setVisible(false);
                f.setVisible(false);
                new MenuClass();
            }
        }
       });
       p.add(l);
       p.add(l2);
       p.add(l3);
       p.add(b);
       f.add(p);
   }
}
