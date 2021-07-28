package tic_tac_toe;
public class PcEightByEightAlgorithm {
        protected int selectedRow;
        protected int selectedCol;
        protected boolean blockedPriority;
        protected int simulationarr[][];
        public PcEightByEightAlgorithm(int arr[][])
        {
            simulationarr = arr;
            blockedPriority = false;
            selectedRow = 6;
            selectedCol = 0;
            if(blockedPriority == false) {
                horizontalEightPlayerCheck();
            }
            if(blockedPriority == false) {
                verticalEightPlayerCheck();
            }
            if(blockedPriority == false) {
                diagonalLeftEightPlayerCheck();
            }
            if(blockedPriority == false) {
                diagonalRightEightPlayerCheck();
            }
            if(blockedPriority == false) {
                fourByTwoCheck();
            }
            if(blockedPriority == false) {
                twoByFourCheck();
            }
            if(blockedPriority == false) {
                highestRectangle();
            }
            
        }
        public void horizontalEightPlayerCheck()
        {
           // System.out.println("ase 1");
            for(int i = 0; i < 8; i++) {
                int playerMoveCounter = 0;
                int pcMove = 0;
                for(int j = 0; j < 8; j++) {
                 if(simulationarr[i][j] == 2) {
                     playerMoveCounter++;
                 }
                 if(simulationarr[i][j] == 1) {
                     pcMove++;
                 }
            }
            if(playerMoveCounter == 7 && pcMove == 0) {
                blockedPriority = true;
                selectionFromHorizontalRow(i);
            }
        }
        }
        public void selectionFromHorizontalRow(int row)
        {
            if(blockedPriority == true) {
                for(int i = 0; i < 8; i++) {
                    if(simulationarr[row][i] == 0) {
                        simulationarr[row][i] = 1;
                        selectedRow = row;
                        selectedCol = i;
                        break;
                    }
                }
            }
        }
        public void verticalEightPlayerCheck()
        {
            if(blockedPriority == false) {
               // System.out.println("ase 2");
                for(int i = 0; i < 8; i++) {
                int playerMoveCounter = 0;
                int pcMove = 0;
                for(int j = 0; j < 8; j++) {
                 if(simulationarr[j][i] == 2) {
                     playerMoveCounter++;
                 }
                 if(simulationarr[j][i] == 1) {
                     pcMove++;
                 }
            }
            if(playerMoveCounter == 7 && pcMove == 0) {
                blockedPriority = true;
                selectionFromVerticalCol(i);
            }
        }
            }
        }
        public void selectionFromVerticalCol(int col)
        {
            if(blockedPriority == true) {
            for(int i = 0; i < 8; i++) {
                if(simulationarr[i][col] == 0) {
                    selectedRow = i;
                    selectedCol = col;
                    simulationarr[i][col] = 1;
                    break;
                }
            }
            }
        }
        public void diagonalLeftEightPlayerCheck()
        {
                int playerMoveCounter = 0;
                int pcMove = 0;
                if(blockedPriority == false) {
                   // System.out.println("ase 3");
                    for(int i = 0; i < 8; i++) {
                     //   System.out.println( i + " " + simulationarr[i][i]);
                        if(simulationarr[i][i] == 2) {
                            playerMoveCounter++;
                        }
                        else if(simulationarr[i][i] == 1) {
                            pcMove++;
                        }
                    }
                   // System.out.println(pcMove + " " + playerMoveCounter);
                    if(playerMoveCounter == 7 && pcMove == 0) {
                        blockedPriority = true;
                        selectionLeftFromDiagonal();
                    }
                }
        }
        public void selectionLeftFromDiagonal()
        {
            for(int i = 0; i < 8; i++) {
                if(simulationarr[i][i] == 0) {
                    simulationarr[i][i] = 1;
                    selectedRow= i;
                    selectedCol = i;
                    break;
                }
            }
        }
        public void diagonalRightEightPlayerCheck()
        {
            if(blockedPriority == false)
            {
               // System.out.println("ase 4");
                int playerMoveCounter = 0;
                int pcMove = 0;
                for(int i = 0,j = 7; i <= 7; i++,j--) {
                    if(simulationarr[i][j] == 2) {
                            playerMoveCounter++;
                        }
                    if(simulationarr[i][j] == 1) {
                            pcMove++;
                        }
                }
               // System.out.println(playerMoveCounter + " " + pcMove + " iss");
                if(playerMoveCounter == 7 && pcMove == 0) {
                        blockedPriority = true;
                        selectionRightFromDiagonal();
                    }
            }
        }
        public void selectionRightFromDiagonal()
        {
            int j = 7;
            for(int i = 0; i <= 7; i++,j--) {
                if(simulationarr[i][j] == 0) {
                    simulationarr[i][j] = 1;
                    selectedRow= i;
                    selectedCol = j;
                    break;
                }
            }
        }
        public void fourByTwoCheck()
        {
            if(blockedPriority == false) {
            //System.out.println("ase 5");
            for(int i = 0; i <= 6;i++) {
                for(int j = 0; j <= 4;j++) {
                    int playerMoveCounter = 0;
                    int pcMove = 0;
                    int savex = 0,savey = 0;
                    for(int l = i; l <= i + 1; l++) {
                        for(int k = j; k <= j + 3; k++) {
                            if(simulationarr[l][k] == 2) {
                            playerMoveCounter++;
                        }
                            if(simulationarr[l][k] == 1) {
                            pcMove++;
                        }
                            if(simulationarr[l][k] == 0) {
                                savex = l;
                                savey = k;
                            }
                        }
                    }
                    if(playerMoveCounter == 7 && pcMove == 0) {
                        blockedPriority = true;
                        selectionForFourByTwo(savex,savey);
                    }
                }
            }
            }
        }
        public void selectionForFourByTwo(int savex,int savey)
        {
            simulationarr[savex][savey] = 1;
            selectedRow = savex;
            selectedCol = savey;
        }
        public void twoByFourCheck()
        {
            if(blockedPriority == false) {
               // System.out.println("ase 6");
                for(int i = 0; i <= 4; i++) {
                    for(int j = 0; j <= 6; j++) {
                        int playerMoveCounter = 0;
                        int pcMove = 0;
                        int savex = 0,savey = 0;
                        for(int l = i; l <= i + 3; l++) {
                            for(int k = j; k <= j+1;k++) {
                                if(simulationarr[l][k] == 2) {
                                    playerMoveCounter++;
                                }
                                if(simulationarr[l][k] == 1) {
                                    pcMove++;
                                }
                                if(simulationarr[l][k] == 0) {
                                    savex = l;
                                    savey = k;
                                }
                            }
                        }
                        if(playerMoveCounter == 7 && pcMove == 0) {
                            blockedPriority = true;
                            selectionForTwoByFour(savex,savey);
                        }
                    }
                }
            }
        }
        public void selectionForTwoByFour(int savex, int savey) {
          //  System.out.println("hoise = " + savex + " " + savey);
            simulationarr[savex][savey] = 1;
            selectedRow =savex;
            selectedCol = savey;
        }
        public void highestRectangle()
        {
             if(blockedPriority == false) {
                int maximum = 0,savex = 0,savey = 0,save;
                for(int i = 0; i < 8; i++) {
                    for(int j = 0; j < 8; j++) {
                        save = 0;
                        if(simulationarr[i][j] == 0) {
                            LongestRectangle rectangle = new LongestRectangle(simulationarr,i,j);
                            //System.out.println("i = " + i + " j = " + j + " " + rectangle.horizontalLength + " " + rectangle.verticalLength + " " +rectangle.diagonalLength );
                            int horizontalLength = rectangle.horizontalLength;
                            int verticalLength = rectangle.verticalLength;
                            int diagonalLength = rectangle.diagonalLength;
                            FourByTwo object = new FourByTwo(simulationarr,i,j);
                            int highestboxlength = object.maximum;
                            TwoByFour problem = new TwoByFour(simulationarr,i,j);
                            int twoBoxProblem = problem.maximum;
                            //System.out.println(twoBoxProblem + " shesh");
                            if(save <= horizontalLength) {
                                save = horizontalLength;
                            }
                            if(save <= verticalLength) {
                                save = verticalLength;
                            }
                            if(save <= diagonalLength) {
                                save = diagonalLength;
                            }
                            if(save <= highestboxlength) {
                                save = highestboxlength;
                            }
                            if(save <= twoBoxProblem) {
                               save = twoBoxProblem; 
                            }
                            if(maximum < save) {
                                maximum = save;
                                savex= i;
                                savey = j;
                                blockedPriority = true;
                            }
                            
                        }
                    }
                }
                selectedRow = savex;
                selectedCol = savey;
                simulationarr[savex][savey] = 1;
                
            } 
        }
       
                
        
}
