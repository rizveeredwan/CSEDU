package tic_tac_toe;
public class StartGame {
  protected int counter;
  protected FirstPlayerServer firstplayerserver;
  protected SecondPlayerServer secondplayerserver;
  protected PcVsHuman pc;
  int choose;
  StartGame(int choose) throws Exception 
  {
      counter = 0;
       if(choose == 1) serverOn();
       if(choose == 2)secondServer();
       if(choose == 3)eightbyeight();
  }
  void serverOn() throws Exception {
      firstplayerserver = new FirstPlayerServer();
      
  }
  void secondServer() throws Exception
  {
      secondplayerserver = new SecondPlayerServer();
  }
  void eightbyeight() {
      pc = new PcVsHuman();
  }
    
}
