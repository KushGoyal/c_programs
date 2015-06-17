#include"sorting.h"

int main(int argc,char *argv[]){

    int listOfNumbers[SIZE];
    int current = 0;
    
    printf("Please enter array elements\n");
    
    while(current < SIZE){
    
        scanf("%d",&listOfNumbers[current]);
        current++;
        
    }
    
    //bubbleSort(listOfNumbers,SIZE);
    //selectionSort(listOfNumbers,SIZE);
    //insertionSort(listOfNumbers,SIZE);
    mergeSort(listOfNumbers,SIZE);
    
    /*shellSort(listOfNumbers,SIZE,3);
    shellSort(listOfNumbers,SIZE,4);
    shellSort(listOfNumbers,SIZE,7);
    insertionSort(listOfNumbers,SIZE);*/
    
    //countingSort(listOfNumbers,SIZE);
    //smallLargeSort(listOfNumbers,SIZE);
    //beadSort(listOfNumbers,SIZE);
    
    //bucketSort(listOfNumbers,SIZE);
    
    printList(listOfNumbers,SIZE);

    return 0;
    
}

        
            
                
    
    
    
    
    


    









    
