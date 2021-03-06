#include<stdio.h>
#include<stdlib.h>


void printList(int list[], int size){
    
    int current = 0;
    
    printf("List of numbers:\n");
    
    while(current < size){
    
        printf("%d ",list[current]);
        current++;
        
    }
    
    printf("\n");
    
}


void bubbleSort(int listOfNumbers[],int size){

    int sortCounter = 0;
    int temp =0;
    int current = 0;
    int comparisons = 0;
    
    for(sortCounter = size-1; sortCounter> 0; sortCounter--){
    
    
        for(current = 0; current< sortCounter; current++){
            
            if(listOfNumbers[current]>listOfNumbers[current+1]){
                    
                temp = listOfNumbers[current+1];
                listOfNumbers[current+1] = listOfNumbers[current];
                listOfNumbers[current] = temp;
                comparisons++;
                    
            }
        }
    }
    
    printf("\nNo. of compairions:%d\n",comparisons);
}
    

void selectionSort(int listOfNumbers[], int size){


    int current = 0;
    int member = 0;
    int temp = 0;
    int comparisons = 0;

    for(current = 0; current < size; current++){
       
        for(member = current; member < size; member++){
           
            if(listOfNumbers[current] > listOfNumbers[member]){
            
                temp = listOfNumbers[current];
                listOfNumbers[current] = listOfNumbers[member];
                listOfNumbers[member] = temp;
                comparisons++;
                
            }
        }
    }
    
    printf("\nNo. of compairions:%d\n",comparisons);
}


void insertionSort(int listOfNumbers[], int size){
    
    int current = 0;
    int member = 0;
    int temp = 0;
    //int comparisons = 0;
    
    for(member = 1; member<size; member++){
    
        for(current=member;current>0;current--){
            
            if(listOfNumbers[current]<listOfNumbers[current-1]){
                
                temp = listOfNumbers[current];
                listOfNumbers[current] = listOfNumbers[current-1];
                listOfNumbers[current-1] = temp;
                //comparisons++;
                  
            }
        }
    }
    
    //printf("\nNo. of compairions:%d\n",comparisons);
} 
    
void mergeList(int list[], int cart[], int shelf[],int size){
    
    
    int counter = 0;
    int numCart = 0;
    int numShelf = 0;
    int cartSize = size/2;
    int shelfSize = size/2 + size%2;
    //int comparisons = 0;
    
    while(counter<size){
    
        while(numCart<cartSize && numShelf<shelfSize){
        
            if(cart[numCart] <= shelf[numShelf]){
                
                list[counter] = cart[numCart];
                counter++;
                numCart++;
                
            }
            
            else{
            
                list[counter] = shelf[numShelf];
                counter++;
                numShelf++;
                
            }
            
        }
        
        if(numCart == cartSize){
        
            while(numShelf < shelfSize){
            
                list[counter] = shelf[numShelf];
                numShelf++;
                counter++;
                
            }
        }
            
        else if(numShelf == shelfSize){
            
            while(numCart < cartSize ){
    
                list[counter] = cart[numCart];
                numCart++;
                counter++;
                
            }
        }
    }
}

   
void mergeSort(int list[], int size){
    
    int counter=0;
    int cartSize = size/2;
    int shelfSize = (size/2) + (size%2);
    int cart[cartSize];
    int shelf[shelfSize];
    
    //dividing the array into two parts:
    while(counter<size/2){
        
        cart[counter] = list[counter];
        shelf[counter] = list[size/2+counter];  
        counter++;
            
    }
    
    //assigning the last element of list:
    if(size%2 !=0){
 
        shelf[shelfSize-1] = list [size-1];
           
    }
    
    if(shelfSize >=2 && cartSize > 1){
    
        mergeSort(cart,cartSize);
        mergeSort(shelf,shelfSize);
        mergeList(list,cart,shelf,size);
        
    }
    
    else if(shelfSize == 2 && cartSize == 1){
        
        //mergeSort only the shelf:
        mergeSort(shelf,shelfSize);
        mergeList(list,cart,shelf,size);
        
    }
    
    else if(shelfSize < 2){
        
        mergeList(list,cart,shelf,size);
     
    }
}    

void shellSort(int list[],int size,int gap){

    int temp = 0;
    int current = 0;
    
    for(current=0;current<size;current++){
        
        if(current+gap<size){
        
            if(list[current]>list[current+gap]){
        
                temp = list[current+gap];
                list[current+gap]=list[current];
                list[current]=temp;
            
            }
        }
    }
}   
               
        
void countingSort(int list[],int size){

    int current=0;
    int largest = list[0];
    int smallest = list[0];
    
    
    for(current=0;current<size;current++){
    
        if(list[current]>largest){
            
            largest = list[current];
        }
        else if(list[current]<smallest){
            
            smallest = list[current];
            
        }
        
    }
    
    current = 0;
    
    int range = largest-smallest+1;
    int countList[range];
    
    while(current<range){
    
        countList[current] = 0;
        current++;
        
    }
    
    current = 0;
    
    while(current<size){
    
        countList[list[current]-smallest]++;
        current++;
    
    }
    
    current=0;
    int sum = 0;
    int temp = 0;
    
    while(current<range){
        
        temp = countList[current];
        countList[current] = sum;
        sum = temp + sum;
        current++;
        
    }
    
    current=0;
        
    int tempList[size];
    
    while(current<size){
    
        tempList[current] = list[current];
        current++;
        
    }
    
    current = 0;
    
    while(current<size){
        
        list[countList[tempList[current]-smallest]] = tempList[current];
        countList[tempList[current]-smallest]++;
        current++;
    }   
}    
    
    
void smallLargeSort(int list[],int size){

    int current = 0;
    int temp = 0;
    int small = 0;
    int large = size-1;
    
    while(small < size/2){
    
    for(current=small;current<large;current++){
        
        if(list[current]<list[small]){
        
            temp = list[small];
            list[small] = list[current];
            list[current] = temp;
            
        }
        
        else if(list[current]>list[large]){
        
            temp = list[large];
            list[large] = list[current];
            list[current] = temp;
            
        }
    }
    
    small++;
    large--;
    
    } 
}
    

int numDigits(int number){
    
    int digits=0;    
    
    while(number!=0){
    
        number = number / 10;
        
        digits++;
        
    }
    
    return digits;
    
}


void bucketSort(int list[],int size){
  
    int current=0;    
    int counter1=0;
    int counter2=0;
    int counter3=0;
    int counter4=0;
    int counterRand=0;
    int bucket1Size=0;
    int bucket2Size=0;
    int bucket3Size=0;
    int bucket4Size=0;
    int bucketRandSize=0; 
    
    for(current=0;current<size;current++){
    
        if(numDigits(list[current])==1 || numDigits(list[current])==0){
        
            bucket1Size++;
            
        }
        else if(numDigits(list[current])==2){
        
            bucket2Size++;
            
        }
        else if(numDigits(list[current])==3){
        
            bucket3Size++;
            
        }
        else if(numDigits(list[current])==4){
        
            bucket4Size++;
            
        }
        else{
        
            bucketRandSize++;
        }
        
    }
    
    int bucket1[bucket1Size];
    int bucket2[bucket2Size];
    int bucket3[bucket3Size];
    int bucket4[bucket4Size];
    int bucketRand[bucketRandSize];
    
    for(current=0;current<size;current++){
    
        if(numDigits(list[current])==1 || numDigits(list[current])==0){
        
            bucket1[counter1] = list[current];
            counter1++;
            
        }
        else if(numDigits(list[current])==2){
        
            bucket2[counter2] = list[current];
            counter2++;
            
        }
        else if(numDigits(list[current])==3){
        
            bucket3[counter3] = list[current];
            counter3++;
            
        }
        else if(numDigits(list[current])==4){
        
            bucket4[counter4] = list[current];
            counter4++;
            
        }
        else{
        
            bucketRand[counterRand] = list[current];
            counterRand++;
        }
        
    }
    
    /*
    insertionSort(bucket1,bucket1Size);
    insertionSort(bucket2,bucket2Size);
    insertionSort(bucket3,bucket3Size);
    insertionSort(bucket4,bucket4Size);
    insertionSort(bucketRand,bucketRandSize);
    */
    counter1=0;
    counter2=0;
    counter3=0;
    counter4=0;
    counterRand=0;
    current=0;
    
    while(current<size){
    
        while(counter1<bucket1Size){
        
            list[current] = bucket1[counter1];
            counter1++;
            current++;
            
        }
    
        while(counter2<bucket2Size){
        
            list[current] = bucket2[counter2];
            counter2++;
            current++;
            
        }
        
        while(counter3<bucket3Size){
        
            list[current] = bucket3[counter3];
            counter3++;
            current++;
            
        }
    
        while(counter4<bucket4Size){
        
            list[current] = bucket4[counter4];
            counter4++;
            current++;    
        }
    
        while(counterRand<bucketRandSize){
        
            list[current] = bucketRand[counterRand];
            counterRand++;
            current++;    
        }
    }
    
    insertionSort(list,size);
}

        

        
        
void beadSort(int list[],int size){
    
    int current=0;
    int largest = list[0];
    int smallest = list[0];
    
    
    for(current=0;current<size;current++){
    
        if(list[current]>largest){
            
            largest = list[current];
        }
        else if(list[current]<smallest){
            
            smallest = list[current];
            
        }
        
    }
    
    int columnSize = largest;
    
    if(-smallest>largest){
    
        columnSize = -smallest;
        
    }
    
    int rowSize = size;
    int beadStand[rowSize][columnSize];
    
    int bead = 0;
    
    for(current=0;current<rowSize;current++){
    
        if(list[current]>0){
    
            for(bead=0;bead<list[current];bead++){
            
                beadStand[current][bead] = 1;
                
            }
            
            for(bead=list[current];bead<columnSize;bead++){
            
                beadStand[current][bead] = 0;
                
            }
        }
        
        else{
        
            for(bead=0;bead<-list[current];bead++){
            
                beadStand[current][bead] = -1;
                
            }
            
             for(bead=-list[current];bead<columnSize;bead++){
            
                beadStand[current][bead] = 0;
                
            }
        }
        
    }

    int row = 0;
    int column=0;
    int numberBeadsPlus[columnSize];
    int numberBeadsMinus[columnSize];
    
    for(column=0;column<columnSize;column++){
    
        numberBeadsPlus[column]=0;
        numberBeadsMinus[column]=0;
        
    }
    
    for(column=0;column<columnSize;column++){
    
        for(row=0;row<rowSize;row++){
        
            if(beadStand[row][column]==1){
                numberBeadsPlus[column]++;
            }
            else if(beadStand[row][column]==-1){
                numberBeadsMinus[column]++;
            }
        }
    }
    
    for(row=0;row<rowSize;row++){
    
        for(column=0;column<columnSize;column++){
        
            beadStand[row][column] = 0;
            
        }
    }
    
    for(column=0;column<columnSize;column++){
    
        for(row=rowSize-numberBeadsPlus[column];row<rowSize;row++){
        
            beadStand[row][column] = 1;

        }
    }
    
    for(column=0;column<columnSize;column++){
    
        for(row=0;row<numberBeadsMinus[column];row++){
        
            beadStand[row][column] = -1;

        }
    }
        
    for(row=0;row<rowSize;row++){
    
        list[row]=0;
        
    }
    
    for(row=0;row<rowSize;row++){
        
        for(column=0;column<columnSize;column++){
            
            list[row] = list[row] + beadStand[row][column];
            
        }
    }
}
