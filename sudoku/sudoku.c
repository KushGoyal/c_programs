#include <stdio.h>
#include <stdlib.h>
#include "sudokuFun.h"




int main (int argv,char* argc[]){
    char grid[81]="0";
    
    //asks user to enter the sudoku grid
    makeGame(grid);
   
    if(hasSolution(grid)){
        showGame(grid);
    }
    else{
        printf("no solution\n");
    }
    return 0;
    }
    
    
    
    
    
    
    
    
