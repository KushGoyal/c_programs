#include"randomNum.c"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<assert.h>

typedef struct node *tree;

typedef struct node{
    unsigned long long value;
    tree left;
    tree right;
    } node;
    
typedef tree memory;

#define TRUE 1
#define FALSE 0

int seenBefore(tree memory, unsigned long long key);

int main(int argc, char * argv[]){

    unsigned long long randomNum = 123456789llu;
    int counter=0;
    int loopDetected = FALSE;
    
    //create a node on stack
    node seedNode;
    
    //get the pointer to the created node
    //this is the pointer to the tree
    tree memory = &seedNode;
    
    //intialize the node
    memory->value = randomNum;
    memory->left = NULL;
    memory->right = NULL;
    
    
    while(loopDetected == FALSE){
    
        randomNum *= randomNum;
        //stip off the last 4 digits
        randomNum = randomNum  / 10000;
        //strip off the first 4 digits
        randomNum = randomNum % 10000000000;
        
        if(seenBefore(memory,randomNum)){
            
            loopDetected = TRUE;
            printf("Repeatation at counter no. : %d\n",counter);
            
        }
        
        //printf("%llu\n",randomNum);
        counter++;
        
    }
    
    
    
    return 0;

}

int seenBefore(tree memory,unsigned long long key){
    
    int seen = FALSE;
    assert(memory != NULL);
    
    if(key == memory->value){
        
        seen = TRUE;
        
    }
    
    else if(key < memory->value){
        
        if(memory->left == NULL){
        
            memory->left = malloc(sizeof(node));
            assert(memory->left!=NULL);
            memory->left->value = key;
            memory->left->left = NULL;
            memory->left->right = NULL;
            
        }
        
        else{
        
            seen = seenBefore(memory->left,key);
        }
    }
    
    else{
        
        if(memory->right == NULL){
        
            memory->right = malloc(sizeof(node));
            assert(memory->right!=NULL);
            memory->right->value = key;
            memory->right->left = NULL;
            memory->right->right = NULL;
            
        }
        
        else{
        
            seen = seenBefore(memory->right,key);
        }
        
    }
    
    
    return seen;   
}
