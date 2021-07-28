package tic_tac_toe;

public class WinnerDeterminator {
  boolean playerOne;
  boolean playerTwo;
  int simulationarr[][];
  public WinnerDeterminator(int arr[][])
  {
      playerOne = false;
      playerTwo = false;
      simulationarr = arr;
      movesOfPlayerOne();
      movesOfPlayerTwo();
  }
  public void movesOfPlayerOne()
  {
      if(simulationarr[0][0] == 1 && simulationarr[1][1] == 1 && simulationarr[2][2] == 1) {
          playerOne = true;
      }
      else if(simulationarr[0][2] == 1 && simulationarr[1][1] == 1 && simulationarr[2][0] == 1) {
          playerOne = true;
      }
      else if(simulationarr[0][0] == 1 && simulationarr[1][0] == 1 && simulationarr[2][0] == 1) {
          playerOne = true;
      }
      else if(simulationarr[0][1] == 1 && simulationarr[1][1] == 1 && simulationarr[2][1] == 1) {
          playerOne = true;
      }
      else if(simulationarr[0][2] == 1 && simulationarr[1][2] == 1 && simulationarr[2][2] == 1) {
          playerOne = true;
      }
      else if(simulationarr[0][0] == 1 && simulationarr[0][1] == 1 && simulationarr[0][2] == 1) {
          playerOne = true;
      }
      else if(simulationarr[1][0] == 1 && simulationarr[1][1] == 1 && simulationarr[1][2] == 1) {
          playerOne = true;
      }
      else if(simulationarr[2][0] == 1 && simulationarr[2][1] == 1 && simulationarr[2][2] == 1) {
          playerOne = true;
      }
      else {
          playerOne = false;
      }
      
  }
  public void movesOfPlayerTwo()
  {
      if(simulationarr[0][0] == 2 && simulationarr[1][1] == 2 && simulationarr[2][2] == 2) {
          playerTwo = true;
      }
      else if(simulationarr[0][2] == 2 && simulationarr[1][1] == 2 && simulationarr[2][0] == 2) {
          playerTwo = true;
      }
      else if(simulationarr[0][0] == 2 && simulationarr[1][0] == 2 && simulationarr[2][0] == 2) {
          playerTwo = true;
      }
      else if(simulationarr[0][1] == 2 && simulationarr[1][1] == 2 && simulationarr[2][1] == 2) {
          playerTwo = true;
      }
      else if(simulationarr[0][2] == 2 && simulationarr[1][2] == 2 && simulationarr[2][2] == 2) {
          playerTwo = true;
      }
      else if(simulationarr[0][0] == 2 && simulationarr[0][1] == 2 && simulationarr[0][2] == 2) {
          playerTwo = true;
      }
      else if(simulationarr[1][0] == 2 && simulationarr[1][1] == 2 && simulationarr[1][2] == 2) {
          playerTwo = true;
      }
      else if(simulationarr[2][0] == 2 && simulationarr[2][1] == 2 && simulationarr[2][2] == 2) {
          playerTwo = true;
      }
      else {
          playerTwo = false;
      }
      System.out.println("class e one = " + playerOne + " two = " + playerTwo);
  }
  
}
