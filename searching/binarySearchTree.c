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

tree makeTree(int list[],int size);

void listToTree(int value,tree aTree);

int searchTree(int value,tree aTree);

int main(int argc,char *argv[]){

    int list[SIZE];
    int current=0;
    
    printf("Enter array elements:\n");
    for(current=0;current<SIZE;current++){
    
        scanf("%d",&list[current]);
        
    }
    
    tree aTree = makeTree(list,SIZE);
    
    int found = searchTree(10,aTree);
    
    printf("found 10 = %d\n",found);
    
    return 0;
    
}

tree makeTree(int list[],int size){

    int current=0;
    tree aTree = malloc(sizeof(node));
    aTree->value=list[0];
    aTree->left=NULL;
    aTree->right=NULL;
    
    if(size>1){
    
        for(current=1;current<size;current++){
    
            listToTree(list[current],aTree);
            
        }
    }
    return aTree;
    
}

void listToTree(int value,tree aTree){   
    
    if(value<=aTree->value){
    
        if(aTree->left==NULL){
    
            aTree->left = malloc(sizeof(node));
            assert(aTree->left!=NULL);
            aTree->left->value = value;
            aTree->left->left=NULL;
            aTree->left->right=NULL;
        
        }
        
        else{
        
            listToTree(value,aTree->left);
            
        }
    
    }
    
    else{
    
        if(aTree->right==NULL){
    
            aTree->right = malloc(sizeof(node));
            assert(aTree->right!=NULL);
            aTree->right->value = value;
            aTree->right->left=NULL;
            aTree->right->right=NULL;
            
        }
        
        else{
        
            listToTree(value,aTree->right);
            
        }
    
    }  
}


int searchTree(int value,tree aTree){

    int found = FALSE;
    
    if(value==aTree->value){
        
        found = TRUE;
        
    }
    
    else if((value<aTree->value)&&(aTree->left!=NULL)){
            
        found = searchTree(value,aTree->left);
        
    }
    
    else if(aTree->right!=NULL){
    
        found=searchTree(value,aTree->right);
        
    }
    
    return found;
    
}
    
    
