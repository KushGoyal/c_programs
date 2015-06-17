//sudokuFun.h file created for sudoku.c
//Created by Kush Goyal


int isLegal(int trialValue, int cell, char grid[]);
void makeGame(char grid[]);
void showGame(char grid[]);
int giveEmptyCell(char grid[]);
void putValue(int trialValue,int cell,char grid[]);
void clearCell(int cell, char grid[]);
int hasSolution(char grid[]);



//asks user to enter alleast 81 values to
//generate a sudoku game. In case of error
//asks to enter all the values again.
void makeGame(char grid[]){
    int value=0;
    int loopCounter=0;
    int k=0;
    int invalidValueCounter=1;
    int illegalValueCounter=1;
    while(value !=EOF){
        if(loopCounter<81){
            value=getchar();
            grid[loopCounter] = value;
            loopCounter++;
            }
        else{
            value=getchar();
            }
        }
    if(loopCounter<81){
        printf("\nless than 81 values entered.");
        printf("\nPlease enter again.\n");
        makeGame(grid);
        }
    else{
        while(k<81){
            if(grid[k] != '1' && grid[k] != '2' && grid[k] != '3' && grid[k] != '4' 
                && grid[k] != '5' && grid[k] != '6' && grid[k] != '7' 
                && grid[k] != '8' && grid[k] != '9' && grid[k] != '.'){
                invalidValueCounter=0;
            }
            k++;
        }
        if(invalidValueCounter==0){
            printf("\nInvalid values.\nPlease enter again.\n");
            makeGame(grid);
            }
        else{
            k=0;
            int temp=0;
            while(k<81){
                if(grid[k] != '.' ){
                    temp = grid[k];
                    grid[k] = '.';
                    if(!isLegal(temp,k,grid)){
                        illegalValueCounter=0;
                    }
                    grid[k] = temp;
                }
                k++;
            }
            if(illegalValueCounter == 0){      
                printf("\nIllegal values.\nPlease enter again.\n");
                makeGame(grid);
            }    
        }
    }
}


//prints the generated sudoku game       
void showGame(char grid[]){
    int i=0;
    printf("\n");
    while(i<81){
        if((i+1)%9==0){
            printf("%c\n",grid[i]);
        }
        else{
            printf("%c ",grid[i]);
        }
        i++;
    }
    printf("\n");
}


//finds the empty cell value.
//in case non empty value is -1    
int giveEmptyCell(char grid[]){
    int i=0;
    int emptyCellNumber=-1;
    while(i<81){
        if(grid[i] == '.'){
            emptyCellNumber = i;
        }
        i++;
    }
    return emptyCellNumber;    
}
    
void putValue(int trialValue,int cell,char grid[]){
    grid[cell] = trialValue;
    }
    
void clearCell(int cell, char grid[]){
    grid[cell] = '.';
    }


//decides if the move is legal or not    
int isLegal(int trialValue, int cell, char grid[]){
    int legalVertical = 1;
    int legalHorizontal = 1;
    int legalCells = 0;
    int legal = 0;
    
    int i = -(cell/9);
    while(i<=(8-(cell/9))){
        if(trialValue == grid[cell+(i*9)]){
            legalVertical=0;
            }
        i++;
    }
    if(legalVertical){
        i = -(cell%9);
        while(i<=(8-(cell%9))){
            if(trialValue == grid[cell+i]){
                legalHorizontal=0;
            }
        i++;
        }
        if(legalHorizontal){
            int cellVals[] = {0,3,6,27,30,33,54,57,60};
            i = 0;
            while(i<9){
                if(cellVals[i] == cell){
                    if( grid[cell+10] != trialValue && grid[cell+20] != trialValue
                        && grid[cell+11] != trialValue
                        && grid[cell+19] != trialValue ){
                        legalCells = 1;
                    }
                }
                else if((cellVals[i]+20) == cell){
                    if( grid[cell-10] != trialValue && grid[cell-20] != trialValue
                        && grid[cell-11] != trialValue
                        && grid[cell-19] != trialValue ){
                        legalCells = 1;
                    }
                }    
                else if((cellVals[i]+1) == cell){
                    if(grid[cell+8] != trialValue && grid[cell+10] != trialValue
                        && grid[cell+17] != trialValue 
                        && grid[cell+19] != trialValue){
                        legalCells = 1;
                    }
                }
                else if((cellVals[i]+19) == cell){
                    if(grid[cell-8] != trialValue && grid[cell-10] != trialValue
                        && grid[cell-17] != trialValue 
                        && grid[cell-19] != trialValue){
                        legalCells = 1;
                    }
                }
                else if((cellVals[i]+2) == cell){
                    if(grid[cell + 8] != trialValue && grid[cell + 16] != trialValue
                        && grid[cell + 7] != trialValue 
                        && grid[cell + 17] != trialValue){
                        legalCells = 1;
                    }
                }
                else if(cellVals[i]+18 == cell){
                    if(grid[cell-8] != trialValue && grid[cell - 16] != trialValue
                        && grid[cell - 7] != trialValue 
                        && grid[cell - 17] != trialValue){
                        legalCells = 1;
                    }
                }
                else if(cellVals[i]+9 == cell){
                    if(grid[cell - 8] != trialValue && grid[cell - 7] != trialValue
                        && grid[cell + 10] != trialValue 
                        && grid[cell + 11] != trialValue){
                        legalCells = 1;
                    }
                }
                else if((cellVals[i]+11) == cell){
                    if(grid[cell + 8] != trialValue && grid[cell + 7] != trialValue
                        && grid[cell-10] != trialValue 
                        && grid[cell-11] != trialValue){
                        legalCells = 1;
                    }
                }
                else if((cellVals[i]+10) == cell){
                    if(grid[cell - 10] != trialValue && grid[cell - 8] != trialValue
                        && grid[cell+8] != trialValue 
                        && grid[cell+10] != trialValue){
                        legalCells = 1;
                    }
                }
                i++;
            }
        }
    }
    if(legalVertical && legalCells && legalHorizontal){
        legal = 1;
    }
    else{
        legal = 0;
    }
    return legal;
}
    

//has solution decides if the sudoku grid
//can be solved or not.Also finds the solution.   
int hasSolution(char grid[]){
    int solved;
    int trialValue;
    int candidateCell;
    if(giveEmptyCell(grid) == -1){
        solved = 1;
    }
    else{
        candidateCell = giveEmptyCell(grid);
        trialValue = '1';
        solved = 0;
        while(!solved && (trialValue <='9')){
            if(isLegal(trialValue,candidateCell,grid)){
            
                putValue(trialValue,candidateCell,grid);
                
                if(hasSolution(grid)){
                    solved = 1;
                }
                else{
                    clearCell(candidateCell,grid);
                }
            }
            trialValue++;
        }
    }
    return solved;
}
        
        
        
        
        
        
        
        
        
        
        
