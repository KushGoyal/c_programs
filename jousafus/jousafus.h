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
    
nodePtr getNextNode(ring PlayRing, int nodeNumber);

nodePtr getCurrentNode(ring playRing, int nodeNumber);

void insertNode(ring playRing,int value,int insertAfter);

ring makeRing(ring playRing, int ringSize);

int getSize(ring playRing);

ring removeNode(ring playRing, int nodeNumber);

ring jousafus(ring playRing,int jnum);

void printRing(ring playRing);
