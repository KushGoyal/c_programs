#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_LIST_SIZE 1000000
#define MAX_WORD_SIZE 40
#define NEW_LINE 10
#define TRUE 1
#define FALSE 0

typedef struct node *tree;

typedef struct node{
    char *wordPtr;
    tree left;
    tree right;
    } node;

int sumWord(char word[]){

    int current = 0;
    int sum = 0;
    
    for(current=0;current<MAX_WORD_SIZE;current++){
        
        sum = sum + word[current];
        
    }
    
    return sum;
    
}

int wordsMatch(char key[], char word[]){
    
    int current = 0;
    int matchCount = 0;
    int matching = FALSE;
    
    for(current = 0;current<MAX_WORD_SIZE;current++){
    
        if(key[current]==word[current]){
        
            matchCount++;
            
        }
        
    }
    
    if(matchCount == MAX_WORD_SIZE){
    
        matching = TRUE;
        
    }
    
    return matching;
    
}

void insertionSort(char word[], int size){
    
    int current = 0;
    int member = 0;
    int temp = 0;
    
    for(member = 1; member<size; member++){
    
        for(current=member;current>0;current--){
            
            if(word[current]>word[current-1]){
                
                temp = word[current];
                word[current] = word[current-1];
                word[current-1] = temp;
                  
            }
        }
    }
} 

int isAnagram(tree memory,char key[],FILE *anagramList,int keyWordSize){

    int anagram = FALSE;
    int counter=0;
    char keyCopy[MAX_WORD_SIZE];
    char wordCopy[MAX_WORD_SIZE];
    
    for(counter=0;counter<MAX_WORD_SIZE;counter++){
    
        keyCopy[counter] = key[counter];
        
    }
    
    for(counter=0;counter<MAX_WORD_SIZE;counter++){
    
        wordCopy[counter] = memory->wordPtr[counter];
        
    }
    
    insertionSort(keyCopy,MAX_WORD_SIZE);
    insertionSort(wordCopy,MAX_WORD_SIZE);
    
    if(wordsMatch(keyCopy,wordCopy)){
    
        anagram = TRUE;
        
        for(counter=0;counter<keyWordSize;counter++){
        
            putc(memory->wordPtr[counter],anagramList);
            
        }
        
        putc(NEW_LINE,anagramList);
        
        for(counter=0;counter<keyWordSize;counter++){
        
            putc(key[counter],anagramList);
            
        }
        
        putc(NEW_LINE,anagramList);
        
    }
    
    else if(sumWord(key)<sumWord(memory->wordPtr)){
    
        if(memory->left == NULL){
        
            memory->left = malloc(sizeof(node));
            assert(memory->left!=NULL);
            
            memory->left->wordPtr = malloc(sizeof(char)*MAX_WORD_SIZE);
            assert(memory->left->wordPtr!=NULL);
            
            for(counter=0;counter<MAX_WORD_SIZE;counter++){
            
                memory->left->wordPtr[counter] = key[counter];
                
            }
            memory->left->left = NULL;
            memory->left->right = NULL;
            
        }
        
        else{
        
            anagram = isAnagram(memory->left,key,anagramList,keyWordSize);
        }
    }
    
    else {
    
        if(memory->right == NULL){
        
            memory->right = malloc(sizeof(node));
            assert(memory->right!=NULL);
            
            memory->right->wordPtr = malloc(sizeof(char)*MAX_WORD_SIZE);
            assert(memory->right->wordPtr!=NULL);
            
            for(counter=0;counter<MAX_WORD_SIZE;counter++){
            
                memory->right->wordPtr[counter] = key[counter];
                
            }
            memory->right->left = NULL;
            memory->right->right = NULL;
            
        }
        
        else{
        
            anagram = isAnagram(memory->right,key,anagramList,keyWordSize);
        }
    }
    
    return anagram;
    
}
