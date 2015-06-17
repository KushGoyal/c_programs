//created bu Kush Goyal
//contains all the function definitions for
//solving the jousafus problem for given
//set of number pairs


#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

typedef struct node node;

typedef struct node *nodePtr;

typedef nodePtr ring;

struct node{
    int value;
    nodePtr next;
};


//places the pointer temp to the next node of the given node number   
nodePtr getNextNode(ring playRing, int nodeNumber){
    
    nodePtr temp = playRing->next;
    int counter=0;
        
    while(counter<nodeNumber){
            
        temp=temp->next;
        counter++;
    }
        
    return temp;
        
}

//inserts a node in the ring after the given node number
void insertNode(ring playRing,int value,int insertAfter){
    
    nodePtr temp = getNextNode(playRing,insertAfter+1);
    nodePtr nodeToInsert = malloc(sizeof(node));
    assert(nodeToInsert!=NULL);
    nodeToInsert->next = temp;
    nodeToInsert->value = value;
    temp = getNextNode(playRing,insertAfter);
    temp->next = nodeToInsert;
    
}


//Creates a ring of nodes   
ring makeRing(ring playRing, int ringSize){
    
    playRing->value = ringSize;
    playRing->next = playRing;
        
    int counter = 1;
        
    while(counter<ringSize){
        
        insertNode(playRing,(ringSize-counter),counter-1);
        counter++;
            
    }
    
    playRing = getNextNode(playRing, 0);
    return playRing;
}

//return the number of nodes in the ring
int getSize(ring playRing){
      
      int ringSize=1;
      nodePtr temp = playRing->next;
      
      while(temp != playRing){

        temp = temp->next;
        ringSize++;
        
      }
      
      return ringSize;

}


//places the pointer temp to the given node number
nodePtr getCurrentNode(ring playRing, int nodeNumber){
    
    nodePtr temp = playRing;
    int counter=0;
        
    while(counter<nodeNumber){
            
        temp=temp->next;
        counter++;
    }
        
    return temp;
        
}

//removes the given node number from the ring
ring removeNode(ring playRing, int nodeNumber){
    
    nodePtr nodeToDelete = getCurrentNode(playRing,nodeNumber);
   
    if(nodeNumber == 0){
    
        nodePtr temp = getCurrentNode(playRing,getSize(playRing)-1);
        temp->next = nodeToDelete->next;

    }
        
    else{
    
        nodePtr temp = getCurrentNode(playRing,nodeNumber-1);
        temp->next = nodeToDelete->next;
        
    }
    
    if(nodeToDelete == playRing){
    
        playRing = playRing->next;
        
    }
    
    
    free(nodeToDelete);
    return playRing;
}       

//returns the jousafus number for a given pair of numbers
ring jousafus(ring playRing,int jnum){

    int size = getSize(playRing);
    int nodeNumber = jnum-1;
    nodePtr temp;
    
        while(size!=1){
        
            temp = getCurrentNode(playRing,nodeNumber);
            playRing = removeNode(playRing,nodeNumber);
            playRing = temp->next;
            size = getSize(playRing);
            
        }
    
        return playRing;

} 


//prints the ring of nodes
void printRing(ring playRing){
    
    printf("\n");
    nodePtr temp = playRing->next;
    printf("%d\n",playRing->value);
    while(temp != playRing){
      
        printf("%d\n",temp->value);
        temp = temp->next;
        
    }
   
}






      
