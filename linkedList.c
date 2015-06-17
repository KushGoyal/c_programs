#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node *nodePtr;

typedef struct node{ int value; nodePtr next;} node;

nodePtr makeList(nodePtr listPointer);

int size(nodePtr listPointer);

void removeNode(nodePtr listPointer);

int main (int argv,char* argc[]){

    nodePtr list = malloc(sizeof(node));
    assert(list != NULL);
    list = makeList(list);
    int listSize = size(list);
    printf("\n\n%d\n",listSize);
    removeNode(list);
    removeNode(list);
    listSize = size(list);
    printf("\n\n%d\n",listSize);
    return 0;
    
}


nodePtr makeList(nodePtr listPointer){
    
    int counter = 1;
    listPointer->value=0;
    listPointer->next=NULL;
    
    while(counter<10){
    
        nodePtr temp = malloc(sizeof(node));
        assert(temp!=NULL);
        temp->value= counter;
        temp->next = listPointer;
        listPointer = temp;
        counter++;
    }
        
    return listPointer;
    
}
    
    
int size(nodePtr listPointer){
    
    int listSize = 0;
    nodePtr temp = listPointer;
    
    while(temp){
    
    printf("\n%d",temp->value);
    temp=temp->next;
    listSize++;
    
    }
    
    return listSize;
     
}

void removeNode(nodePtr listPointer){

    int nodeNumber=0;
    printf("\nPlease enter node number to remove: ");
    scanf("%d",&nodeNumber);
    int counter=0;
    nodePtr temp = listPointer;
    nodePtr temp2;

    while(counter<nodeNumber-1 && temp){
        
        temp = temp->next;
        temp2 = temp->next;
        counter++;
        
    }
    
    free(temp);
    
    temp = listPointer;
    counter = 0;
    
    while(counter<nodeNumber-2){
    
        temp=temp->next;
        counter++;
    }
    
    temp->next = temp2;
    
}
