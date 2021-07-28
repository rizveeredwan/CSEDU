package tic_tac_toe;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Level;
import java.util.logging.Logger;
public class Beginning {
    protected String selection;
    protected boolean show;
    int flag = 0;
    void createThePicture() throws Exception
    {
        show = false;
        JFrame picFrame = new JFrame("Tic Tac Toe");
        JPanel picPanel = new JPanel(new GridBagLayout());
        GridBagConstraints c1 = new GridBagConstraints();
        GridBagConstraints c2 = new GridBagConstraints();
        ButtonGroup group = new ButtonGroup();
        ImageIcon image = new ImageIcon(getClass().getResource("Tic_tac_toe.png"));
        JLabel label = new JLabel(image);
        JRadioButton rbuttonOne,rbuttonTwo;
        JButton buttonOne,buttonTwo;
        picFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        picFrame.setLayout(new FlowLayout());
        picFrame.setSize(800,500);
        buttonOne = new JButton("Play Game");
        buttonTwo = new JButton("Quit Game");
        rbuttonOne = new JRadioButton();
        rbuttonTwo = new JRadioButton();
        group.add(rbuttonOne);
        group.add(rbuttonTwo);
        picPanel.add(label);
        c1.insets = new Insets(10,10,10,10);
        c1.gridx = 0;
        c1.gridy = 1;
        picPanel.add(rbuttonOne,c1);
        c1.gridx = 1;
        c1.gridy = 1;
        picPanel.add(buttonOne,c1);
        c2.gridx = 0;
        c2.gridy = 2;
        picPanel.add(rbuttonTwo,c2);
        c2.gridx = 1;
        c2.gridy = 2;
        picPanel.add(buttonTwo,c2);
        picFrame.add(picPanel);
        picFrame.setVisible(true);
        selection = null;
        buttonOne.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                if(rbuttonOne.isSelected() == true) {
                    selection = "new game";
                    try {
                        picFrame.setVisible(false);
                        new MenuClass();
                    } catch (Exception ex) {
                        Logger.getLogger(Beginning.class.getName()).log(Level.SEVERE, null, ex);
                    }
             }
            }
        });        
        buttonTwo.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                if(rbuttonTwo.isSelected() == true) {
                    selection = "Quit Game";
                    picFrame.setVisible(false);
                    show = true;
                    int value = 0;
                    System.exit(value);
                }
           
             
        }
        });
        
    }
    
}
