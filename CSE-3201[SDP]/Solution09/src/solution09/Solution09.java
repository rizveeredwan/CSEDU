package solution09;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;


interface ConfigManager{
    public void readComponents(String fileName);
}
class ReadComponents implements ConfigManager{
    
    String fileName;
    List<String>componentName = new ArrayList<String>(); //component names
    List<String>componentValue = new ArrayList<String>(); //component values
    List<Integer>x = new ArrayList<Integer>(); //component x co ordinate
    List<Integer>y = new ArrayList<Integer>(); //component y co ordinate 
    
    AdapterForXML adapterForXML = new AdapterForXML(); //for adapter 
    
    public void readComponents(String fileName){ //interface implement 
        this.fileName = fileName;
        String rem="";
        boolean poro=false;
        for(int i=0;i<fileName.length();i++){
            if(fileName.charAt(i) == '.'){
               poro=true;
               continue;
            }
            if(poro){
               rem = rem + fileName.charAt(i); 
            }
        }
        if(rem.equalsIgnoreCase("XML")){
            System.out.println("yes");
            adapterForXML.readComponents(fileName);
            for(int i=0;i<adapterForXML.componentName.size();i++){
               componentName.add(adapterForXML.componentName.get(i));
               componentValue.add(adapterForXML.componentValue.get(i));
               x.add(adapterForXML.x.get(i));
               y.add(adapterForXML.y.get(i));
            }
        }
        else if(rem.equalsIgnoreCase("config")){
            System.out.println("ok");
            try{
                FileReader fr = new FileReader(fileName);
                BufferedReader br = new BufferedReader(fr);
                String s=""; 
                //adding components 
                while((s=br.readLine()) != null){
                    boolean first=true;
                     String prop="";
                     String item="";
                    for(int i=0;i<s.length();i++){
                        if(s.charAt(i) == '='){
                            first =false;
                            continue;
                        }
                        if(first){
                           item=item+s.charAt(i);   
                        }
                        else{
                          prop=prop+s.charAt(i);
                        }
                    }
                    if(item.equals("name")){
                        componentName.add(prop);  //name added 
                    }
                    if(item.equals("value")){
                        componentValue.add(prop);  //value added 
                    }
                    if(item.equals("x")){
                        int value = Integer.parseInt(prop);
                        x.add(value);  //name added 
                    }
                    if(item.equals("y")){
                        int value = Integer.parseInt(prop);
                        y.add(value);  //name added  
                    }
                    System.out.println(prop);
               } 
            } catch (FileNotFoundException ex) {
                Logger.getLogger(ReadComponents.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(ReadComponents.class.getName()).log(Level.SEVERE, null, ex);
            }
            
        } 
     }
}
class AdapterForXML implements ConfigManager{
    
    String fileName;
    
    List<String>componentName = new ArrayList<String>(); //component names
    List<String>componentValue = new ArrayList<String>(); //component values
    List<Integer>x = new ArrayList<Integer>(); //component x co ordinate
    List<Integer>y = new ArrayList<Integer>(); //component y co ordinate 
    
    public void readComponents(String fileName){ //interface implement 
        this.fileName = fileName; 
        
        File file = new File(fileName);
        try {
            DocumentBuilder dBuilder = DocumentBuilderFactory.newInstance()
                    .newDocumentBuilder();
            
            Document document = dBuilder.parse(file);
            
            NodeList nodeList = (NodeList) (Node) document.getChildNodes(); //taking all the child nodes 
            for(int i=0;i<nodeList.getLength();i++){
                 Node temp = nodeList.item(i); //getting body
                 System.out.println("item = " + temp.getNodeName());
                 NodeList child = temp.getChildNodes(); //taking body's all child nodes 
                 System.out.println(child.getLength()); //printing the counter 
                 for(int j=0;j<child.getLength();j++){ //moving through each child 
                     if(j%2 == 0) continue; //deleting the garbages 
                     temp = child.item(j); //taking this child and making it the current node 
                     NamedNodeMap baccha = temp.getAttributes(); //taking all it's attributes  
                     System.out.println(temp.getNodeName() + " " + baccha.getLength()); 
                     componentName.add(temp.getNodeName());
                     for(int k=0;k<baccha.getLength();k++){
                         Node node = baccha.item(k);
                         if(node.getNodeName().equals("value")) {
                             componentValue.add(node.getNodeValue());
                         }
                         if(node.getNodeName().equals("X")) {
                             int value = Integer.parseInt(node.getNodeValue());
                             x.add(value);
                         }
                         if(node.getNodeName().equals("Y")) {
                             int value = Integer.parseInt(node.getNodeValue());
                             y.add(value);
                         }
                         
                     }
                     
                 }
            }
        } catch (ParserConfigurationException ex) {
            Logger.getLogger(AdapterForXML.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SAXException ex) {
            Logger.getLogger(AdapterForXML.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(AdapterForXML.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

/*********************************/

class ButtonFactory extends AbstractFactory{
     Button button;
     public Button factoryButton(String type,String s1,String s2,int x, int y, int width){
       if(type.equals("high detailed design style")) {
           button = new HighDesignButton(s1,s2,x,y);
       }
       if(type.equals("simplistic design style")) {
           button = new SimpleDesignButton(s1,s2,x,y);
       }
       if(type.equals("futuristic design style")) {
           button = new FutureDesignButton(s1,s2,x,y);
       }
       return button;
     }
    public EditBox factoryEditBox(String type, String s1, String s2, int x, int y, int width) {
        System.out.println("wrong reference");
        return null;
    }
    public TextBox factoryTextBox(String type, String s1, String s2, int x, int y, int width) {
        System.out.println("wrong reference");
        return null; 
    }
   public Frame factoryFrame(String type, String s1, String s2, int x, int y, int width){
       System.out.println("wrong reference");
       return null; 
    }
}

abstract class Button{
    public String value;
    public String type;
    public int x;
    public int y;
    public JButton jButton;
    public int width;
    public int height;
    public String color;
    abstract public void create();
}

class HighDesignButton extends Button{
    
    HighDesignButton(String s1,String s2,int x,int y){
        value = s1;
        type = "high";
        this.x = x;
        this.y = y;   
        this.width = 100;
        this.height = 100;
        this.color = "red";
    }
    public void create(){
      jButton = new JButton(value);
      jButton.setBackground(Color.red);
      jButton.setBounds(x, y, height, width);
    }
}

class SimpleDesignButton extends Button{
    
    SimpleDesignButton(String s1,String s2,int x,int y){
        value = s1;
        type = "simple";
        this.x = x;
        this.y = y;   
        this.width = 200;
        this.height=100;
        this.color = "green";
    }
    public void create(){
      jButton = new JButton(value);
      jButton.setBackground(Color.GREEN);
      jButton.setBounds(x, y, height, width);
    }
}
class FutureDesignButton extends Button{
    
    FutureDesignButton(String s1,String s2,int x,int y){
        value = s1;
        type = "future";
        this.x = x;
        this.y = y;   
        this.width = 90;
        this.height = 90;
        this.color = "blue";
    }
    public void create(){
      jButton = new JButton(value);
      jButton.setBackground(Color.blue);
      jButton.setBounds(x, y, height, width);
    }
}

/*****************************/
class TextBoxFactory extends AbstractFactory{
     TextBox textBox;
     public TextBox factoryTextBox(String type,String s1,String s2,int x, int y, int width){
       if(type.equals("high detailed design style")) {
           textBox = new HighDesignTextBox(s1,s2,x,y);
       }
       if(type.equals("simplistic design style")) {
           textBox = new SimpleDesignTextBox(s1,s2,x,y);
       }
       if(type.equals("futuristic design style")) {
           textBox = new FutureDesignTextBox(s1,s2,x,y);
       }
       return textBox;
     }
    public EditBox factoryEditBox(String type, String s1, String s2, int x, int y, int width) {
         System.out.println("wrong reference");
         return null;
    }
    public Button factoryButton(String type, String s1, String s2, int x, int y, int width) {
         System.out.println("wrong reference");
         return null;
    }
    public Frame factoryFrame(String type, String s1, String s2, int x, int y, int width){
       System.out.println("wrong reference");
       return null; 
    }
}

abstract class TextBox{
    public String value;
    public String type;
    public int x;
    public int y;
    public JLabel jTextBox;
    public int width;
    public int height;
    abstract public void create();
}

class HighDesignTextBox extends TextBox{
    
    HighDesignTextBox(String s1,String s2,int x,int y){
        value = s1;
        type = "high";
        this.x = x;
        this.y = y;   
        this.width = 100;
        this.height=100;
    }
    public void create(){
      jTextBox = new JLabel(value);
      jTextBox.setBackground(Color.GREEN);
      jTextBox.setBounds(x, y, width, height);
      Font font = new Font("Serif",Font.PLAIN, 20);
      jTextBox.setFont(font);
      
    }
}

class SimpleDesignTextBox extends TextBox{
    
    SimpleDesignTextBox(String s1,String s2,int x,int y){
        value = s1;
        type = "simple";
        this.x = x;
        this.y = y;   
        this.width = 200;
        this.height = 200;
    }
    public void create(){
      jTextBox = new JLabel(value);
      jTextBox.setBackground(Color.red);
      jTextBox.setBounds(x, y, width, height);
      Font font = new Font("Serif",Font.PLAIN, 15);
      jTextBox.setFont(font);
      
    }
}

class FutureDesignTextBox extends TextBox{
    
    FutureDesignTextBox(String s1,String s2,int x,int y){
        value = s1;
        type = "future";
        this.x = x;
        this.y = y;   
        this.width = 400;
        this.height = 400;
    }
    public void create(){
      jTextBox = new JLabel(value);
      jTextBox.setBackground(Color.red);
      jTextBox.setBounds(x, y, width, height);
      Font font = new Font("Serif",Font.PLAIN, 30);
      jTextBox.setFont(font);
      
    }
}

/******************************/
class EditBoxFactory extends AbstractFactory{
  
   EditBox editBox;
   public EditBox factoryEditBox(String type,String s1,String s2,int x, int y, int width){
        
       if(type.equals("high detailed design style")) {
           editBox = new HighDesignEditBox(s1,s2,x,y);
       }
       if(type.equals("simplistic design style")) {
           editBox = new SimpleDesignEditBox(s1,s2,x,y);
       }
       if(type.equals("futuristic design style")) {
           editBox = new FutureDesignEditBox(s1,s2,x,y);
       }
       return editBox;
    }
    public TextBox factoryTextBox(String type, String s1, String s2, int x, int y, int width) {
        System.out.println("wrong reference");
        return null;
    }
    public Button factoryButton(String type, String s1, String s2, int x, int y, int width) {
         System.out.println("wrong reference");
         return null;
    }
    public Frame factoryFrame(String type, String s1, String s2, int x, int y, int width){
       System.out.println("wrong reference");
       return null; 
    }
}

abstract class EditBox{
    public String value;
    public String type;
    public int x;
    public int y;
    public JTextArea jEditBox;
    public int width;
    public int height;
    abstract public void create();
}

class HighDesignEditBox extends EditBox{
    
    HighDesignEditBox(String s1,String s2,int x,int y){
        value = s1;
        type = "high";
        this.x = x;
        this.y = y;   
        this.width = 400;
        this.height = 400;
        //remaining JSwing part 
    }
    public void create(){
      jEditBox = new JTextArea();
      jEditBox.setBackground(Color.BLUE);
      jEditBox.setBounds(x, y, width, height);
      Font font = new Font("Serif",Font.ITALIC, 10);
      jEditBox.setFont(font);
      jEditBox.setText(value);
    }
}
class SimpleDesignEditBox extends EditBox{
    
    SimpleDesignEditBox(String s1,String s2,int x,int y){
        value = s1;
        type = "simple";
        this.x = x;
        this.y = y;   
        this.width = 200;
        this.height = 200;
    }
    public void create(){
      jEditBox = new JTextArea(width,height);
      jEditBox.setBackground(Color.GREEN);
      jEditBox.setBounds(x, y, width, height);
      Font font = new Font("Serif",Font.BOLD, 9);
      jEditBox.setFont(font);
      jEditBox.setText(value);
    }
}
class FutureDesignEditBox extends EditBox{
    
    FutureDesignEditBox(String s1,String s2,int x,int y){
        value = s1;
        type = "future";
        this.x = x;
        this.y = y;   
        this.width = 400;
        this.height=400;
    }
    public void create(){
      jEditBox = new JTextArea(width,height);
      jEditBox.setBackground(Color.red);
      jEditBox.setBounds(x, y, width, height);
      Font font = new Font("Serif",Font.PLAIN, 8);
      jEditBox.setFont(font);
      jEditBox.setText(value);
    }
}

/*****************************************/

class FrameFactory extends AbstractFactory{
    Frame frame;
    public Frame factoryFrame(String type,String s1,String s2,int x, int y, int width){
        if(type.equals("high detailed design style")) {
           frame = new HighDesignFrame(s1,s2,x,y);
       }
       if(type.equals("simplistic design style")) {
           frame = new SimpleDesignFrame(s1,s2,x,y);
       }
       if(type.equals("futuristic design style")) {
           frame  = new FutureDesignFrame(s1,s2,x,y);
       }
       return frame;
    }
    public EditBox factoryEditBox(String type,String s1,String s2,int x, int y, int width){
        System.out.println("wrong reference");
        return null;
    }
    public TextBox factoryTextBox(String type, String s1, String s2, int x, int y, int width) {
        System.out.println("wrong reference");
        return null;
    }
    public Button factoryButton(String type, String s1, String s2, int x, int y, int width) {
        System.out.println("wrong reference");
        return null;
    }
}

abstract class Frame{
    public String value;
    public String type;
    public int x;
    public int y;
    public int width;
    public JFrame jframe;
    abstract public void create();        
}

class HighDesignFrame extends Frame{
    
    HighDesignFrame(String s1,String s2,int x,int y){
        value = s1;
        type = "high";
        this.x = 700; //interpreted as height
        this.y = 700; //interpreted as width
        this.width = 500;
        //remaining JSwing part 
    }
    public void create(){
     jframe = new JFrame(value);
     jframe.setSize(x,y);
     jframe.setVisible(true);
     jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
    }
}
class SimpleDesignFrame extends Frame{
    
    SimpleDesignFrame(String s1,String s2,int x,int y){
        value = s1;
        type = "simple";
        this.x = 500;//interpreted as height
        this.y = 500; //interpreted as width  
        this.width = 200; 
    }
    public void create(){
     jframe = new JFrame(value);
     jframe.setSize(x,y);
     jframe.setVisible(true);
     jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
class FutureDesignFrame extends Frame{
    
    FutureDesignFrame(String s1,String s2,int x,int y){
        value = s1;
        type = "future";
        this.x = 800;
        this.y = 800;   
        this.width = 400;
    }
    public void create(){
     jframe = new JFrame(value);
     jframe.setSize(x,y);
     jframe.setVisible(true);
     jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}


/**********************/
//abstract factory parent class to catch child factories
abstract class AbstractFactory{
    
    public abstract EditBox factoryEditBox(String type,String s1,String s2,int x, int y, int width);
    public abstract TextBox factoryTextBox(String type,String s1,String s2,int x, int y, int width);
    public abstract Button  factoryButton(String type,String s1,String s2,int x, int y, int width);
    public abstract Frame   factoryFrame(String type, String s1, String s2, int x, int y, int width);
}

/****************************************/
//class main factory to create object 
class MainFactory{
    AbstractFactory editBoxFactory;
    AbstractFactory textBoxFactory;
    AbstractFactory buttonFactory;
    AbstractFactory frameFactory;
    
    public Button makeButton(ButtonFactory bf,String type,String s1,String s2, int x, int y,int width){
          buttonFactory = bf;
          return buttonFactory.factoryButton(type, s1, s2, x, y, width);
    }
    public TextBox makeTextBox(TextBoxFactory tf,String type,String s1,String s2, int x, int y,int width){
         textBoxFactory = tf;
         return textBoxFactory.factoryTextBox(type, s1, s2, x, y, width);
    }
    public EditBox makeEditBox(EditBoxFactory ef,String type,String s1,String s2, int x, int y,int width){
         editBoxFactory = ef;
         return editBoxFactory.factoryEditBox(type, s1, s2, x, y, width);
    }
    public Frame makeFrame(FrameFactory ff,String type,String s1,String s2, int x, int y,int width){
        frameFactory = ff;
        return ff.factoryFrame(type, s1, s2, x, y, width);
    }
    
}

class WindowManager{
    //first JFrame 
    private static WindowManager windowManager = new WindowManager();
    private WindowManager(){}
    public void loadUI(ReadComponents rm,String designStyle){
         //make main factory
         MainFactory mf = new MainFactory();
         
         //make sub factories through factory
         FrameFactory ff = new FrameFactory();
         ButtonFactory bf = new ButtonFactory();
         EditBoxFactory ef = new EditBoxFactory();
         TextBoxFactory tf = new TextBoxFactory();
         
         //making frame through factories 
         Frame objectFrame = mf.makeFrame(ff,designStyle,designStyle,"Making frame",0,0,0); 
         if(objectFrame != null){
             objectFrame.create(); //frame been created 
         }
         //special thing
         JPanel panel = new JPanel();
         panel.setLayout(null);/*****************/
         objectFrame.jframe.add(panel);
   
         //looping and add elements 
         for(int i=0;i<rm.componentName.size();i++){
             String s = rm.componentName.get(i);
             if(s.equalsIgnoreCase("button")){
                 //button will be added 
                 Button objectButton = mf.makeButton(bf,designStyle,rm.componentValue.get(i), "making button", rm.x.get(i), rm.y.get(i), 0);
                 objectButton.create();
                 panel.add(objectButton.jButton);
             }
             if(s.equalsIgnoreCase("editbox")){
                //editBox will be added
                EditBox objectEditBox = mf.makeEditBox(ef, designStyle, rm.componentValue.get(i), "making EditBox", rm.x.get(i), rm.y.get(i), 0);
                objectEditBox.create();
                panel.add(objectEditBox.jEditBox);
             }
             if(s.equalsIgnoreCase("textbox")){
                TextBox objectTextBox = mf.makeTextBox(tf,designStyle, rm.componentValue.get(i), "making Text Box", rm.x.get(i), rm.y.get(i), 0);
                objectTextBox.create();
                panel.add(objectTextBox.jTextBox);
             }
             
         }        
    }
    public static WindowManager getInstance(){
        return windowManager;
    }
}


public class Solution09 {
    
    public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
       
       while(true) {
       ReadComponents readComponents = new ReadComponents();
       //readComponents.readComponents("UI.config");
       Scanner scan = new Scanner(System.in);
       System.out.println("Give file name:");
       String s = scan.nextLine();
       /*readComponents.readComponents("UI.xml");*/
       readComponents.readComponents(s);
       //design style 
       System.out.println("Give design number:");
       System.out.println("1 for high detailed design style");
       System.out.println("2 for simplistic design style");
       System.out.println("3 for futuristic design style");
       int v = scan.nextInt();
       String designStyle="";
       if(v == 1){
          UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
          designStyle =  "high detailed design style";
       }
       else if(v == 2) {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.motif.MotifLookAndFeel");
            designStyle =  "simplistic design style";
       }
       else if(v == 3){
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.gtk.GTKLookAndFeel");
            designStyle =  "futuristic design style";
       }
       /*String designStyle="high detailed design style";*/
       //for singleton object 
       WindowManager windowManager = WindowManager.getInstance();
       windowManager.loadUI(readComponents, designStyle);
    }
    }
}
