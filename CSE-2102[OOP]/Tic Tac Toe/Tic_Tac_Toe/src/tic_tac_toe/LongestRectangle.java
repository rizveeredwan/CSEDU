package tic_tac_toe;
public class LongestRectangle {
  protected int simulationarr[][];
  protected int row,col,length,horizontalLength,verticalLength,diagonalLength;
  boolean diagonalPointIndicator;
  int diagonalGroup;
  public LongestRectangle(int arr[][],int i, int j)
  {
      simulationarr = arr;
      row = i;
      col = j;
      length = 0;
      horizontalLength = 0;
      verticalLength = 0;
      diagonalLength = 0;
      diagonalPointIndicator = false;
      diagonalGroup = 0;
      horizontalHighestLength();
      verticalHighestLength();
      diagonalHighestLength();
  }
  void horizontalHighestLength()
  {
      horizontalLength = 1;
      for(int i = col-1; i >= 0; i--) {
          if(simulationarr[row][i] == 1) {
              horizontalLength++;
          }
          else break;
      }
      for(int i = col + 1; i <= 7; i++) {
          if(simulationarr[row][i] == 1) {
              horizontalLength++;
          }
          else break;
      }
  }
  void verticalHighestLength()
  {
      verticalLength = 1;
      for(int i = row - 1; i >= 0; i--) {
          if(simulationarr[i][col] == 1) {
              verticalLength++;
          }
          else break;
      }
      for(int i = row + 1; i <= 7; i++) {
          if(simulationarr[i][col] == 1) {
              verticalLength++;
          }
          else break;
      }
  }
  void diagonalValidity()
  {
      if(row == 0) {
          if(col == 0 || col == 7) {
              diagonalPointIndicator = true;
              if(col == 0) diagonalGroup = 1;
              else diagonalGroup = 2;
          }
      }
      if(row == 1) {
          if(col == 1 || col == 6) {
              diagonalPointIndicator = true;
              if(col == 1) diagonalGroup = 1;
              else diagonalGroup = 2;
          }
      }
      if(row == 2) {
          if(col == 2 || col == 5) {
              diagonalPointIndicator = true;
              if(col == 2) diagonalGroup = 1;
              else diagonalGroup = 2;
          }
      }
      if(row == 3) {
          if(col == 3 || col == 4) {
              diagonalPointIndicator = true;
              if(col == 3) diagonalGroup = 1;
              else diagonalGroup = 2;
          }
      }
      if(row == 4) {
          if(col == 4 || col == 3) {
              diagonalPointIndicator = true;
              if(col == 4) diagonalGroup = 1;
              else diagonalGroup = 2;
          }
      }
      if(row == 5) {
          if(col == 5 || col == 2) {
              diagonalPointIndicator = true;
              if(col == 5) diagonalGroup = 1;
              else diagonalGroup = 2;
          }
      }
      if(row == 6) {
          if(col == 6 || col == 1) {
              diagonalPointIndicator = true;
              if(col == 6) diagonalGroup = 1;
              else diagonalGroup = 2;
          }
      }
      if(row == 7) {
          if(col == 7 || col == 0) {
              diagonalPointIndicator = true;
              if(col == 7) diagonalGroup = 1;
              else diagonalGroup = 2;
          }
      }
  }
  void diagonalHighestLength()
  {
      diagonalValidity();
      if(diagonalPointIndicator == true) {
          diagonalLength = 1;
          if(diagonalGroup == 1) {
              for(int i = row + 1; i <= 7; i++) {
                  if(simulationarr[i][i] == 1) {
                      diagonalLength++;
                  }
                  else break;
              }
              for(int i = row - 1; i >= 0; i--) {
                  if(simulationarr[i][i] == 1) {
                      diagonalLength++;
                  }
                  else break;
              }
          }
          else if(diagonalGroup == 2) {
             for(int i = row - 1, j = col + 1; i >= 0; i--,j++) {
                 if(simulationarr[i][j] == 1) {
                    diagonalLength++; 
                 }
                 else break;
             }
             for(int i = row + 1, j = col - 1; i <= 7; i++,j--) {
                 if(simulationarr[i][j] == 1) {
                    diagonalLength++; 
                 }
                 else break;
             }
          }
          
      }
      else {
          diagonalLength = 0;
      }
  }
  
}
