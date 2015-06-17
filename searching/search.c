#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"search.h"

#define SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct node *tree;

typedef struct node{
    
    int value;
    tree right;
    tree left;
    
}node;

typedef struct queNode *que;

typedef struct queNode{

    tree  treePtr;
    que next;
    
}queNode;

tree makeTree(void);

void fillTreeRight(int value,tree aTree);

void fillTreeLeft(int value,tree aTree);

int searchTreeDF(int value,tree aTree);

void printQue(que treeQue);

que removeQueMember (que treeQue);

void addToQue(tree aTree,que treeQue);

que makeQue(tree aTree);

int searchTreeBF(int value,tree aTree);

que trackingQue(int value,que treeQue);

int main(int argc,char *argv[]){

    tree aTree = makeTree();
    int value=0;
    
    printf("Enter search value:\n");
    scanf("%d",&value);
    
    int found = searchTreeDF(value,aTree);
    printf("found %d = %d\n",value,found);
    
    found = searchTreeBF(value,aTree);
    printf("found %d = %d\n",value,found);
    
    return 0;
    
}

tree makeTree(void){

    int size=0;
    int value=0;
    int current=0;
    
    printf("Enter tree size:");
    scanf("%d",&size);
    printf("\nEnter tree elements:\n");
    tree aTree = malloc(sizeof(node));
    scanf("%d",&value);
    aTree->value=value;
    aTree->left=NULL;
    aTree->right=NULL;
    
    if(size>1){
    
        for(current=1;current<size;current++){
    
            scanf("%d",&value);
            if(current%2==0){
            
                fillTreeRight(value,aTree);
                
            }
            
            else{
            
                fillTreeLeft(value,aTree);
                
            }
            
        }
    }
    
    return aTree;
    
}

void fillTreeRight(int value,tree aTree){   
    
    if(aTree->left==NULL){
    
        aTree->left = malloc(sizeof(node));
        assert(aTree->left!=NULL);
        aTree->left->value = value;
        aTree->left->left=NULL;
        aTree->left->right=NULL;
        
    }
    
    else if(aTree->right==NULL){
    
        aTree->right = malloc(sizeof(node));
        assert(aTree->right!=NULL);
        aTree->right->value = value;
        aTree->right->left=NULL;
        aTree->right->right=NULL;
            
    }
        
    else{
        
        fillTreeRight(value,aTree->right);
            
    }  
}

void fillTreeLeft(int value,tree aTree){   
    
    if(aTree->left==NULL){
    
        aTree->left = malloc(sizeof(node));
        assert(aTree->left!=NULL);
        aTree->left->value = value;
        aTree->left->left=NULL;
        aTree->left->right=NULL;
        
    }
    
    else if(aTree->right==NULL){
    
        aTree->right = malloc(sizeof(node));
        assert(aTree->right!=NULL);
        aTree->right->value = value;
        aTree->right->left=NULL;
        aTree->right->right=NULL;
            
    }
        
    else{
        
        fillTreeLeft(value,aTree->left);
            
    }  
}

//depth first searching:
int searchTreeDF(int value,tree aTree){

    int found = FALSE;
    
    if(value==aTree->value){
        
        found = TRUE;
        
    }
    
    else if(aTree->left!=NULL){
    
        found = searchTreeDF(value,aTree->left);
        
    }
            
    if ((found==FALSE)&&(aTree->right!=NULL)){
        
        found=searchTreeDF(value,aTree->right);
            
    }

    return found;
    
}

//breadth first searching:
int searchTreeBF(int value,tree aTree){

    que treeQue = makeQue(aTree);
    int found = FALSE;
    
    if (trackingQue(value,treeQue)==NULL){
    
        found = FALSE;
        
    }
    
    else if(value == trackingQue(value,treeQue)->treePtr->value){
    
        found = TRUE;
        
    }
    
    return found;    
}

//tracking que for breadth first search:
que trackingQue(int value,que treeQue){

    que temp;
    
    if(value==treeQue->treePtr->value){
        
        temp = treeQue;
    }
    
    
    else{
    
        if(treeQue->treePtr->left!=NULL){
        
            addToQue(treeQue->treePtr->left,treeQue);

        }
        
        if(treeQue->treePtr->right!=NULL){
        
            addToQue(treeQue->treePtr->right,treeQue);
        
        }
        
        treeQue = removeQueMember(treeQue);
        removeQueMember(treeQue);
        printf("\nloop enter\n");
        printQue(treeQue);
        
        if(treeQue!=NULL){
            
            temp = trackingQue(value,treeQue);
        
        }

    }
    
    printf("\nvalue found\n");
    printQue(temp);
    return temp;
    
}


que makeQue(tree aTree){

    que treeQue = malloc(sizeof(queNode));
    assert(treeQue!=NULL);
    treeQue->next = NULL;
    treeQue->treePtr = aTree;
    
    return treeQue;
    
}

void addToQue(tree aTree,que treeQue){

    que newQueMember = malloc(sizeof(queNode));
    assert(newQueMember!=NULL);
    
    newQueMember->treePtr = aTree;
    newQueMember->next = NULL;
    
    que temp = treeQue;
    
    while(temp->next!=NULL){
    
        temp=temp->next;
        
    }
    
    temp->next = newQueMember;
    
}
    
que removeQueMember (que treeQue){
    
    //que temp = treeQue;
    treeQue = treeQue->next;
    //free(temp);
    
    //que temp = treeQue->next;
    
    //treeQue->next = temp->next;
    //treeQue->treePtr = temp->treePtr;
    
    //que temp = treeQue->next;
    //free(temp);

    return treeQue;
    
}

void printQue(que treeQue){

    que temp = treeQue;
    int current = 1;
    
    while(temp!=NULL){
    
        printf("Node no. %d: %d\n",current,temp->treePtr->value);
        temp=temp->next;
        current++;
        
    }
    
}
    
    
    
