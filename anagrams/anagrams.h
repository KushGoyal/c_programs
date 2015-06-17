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
    
int sumWord(char word[]);

void insertionSort(char word[], int size);

int wordsMatch(char key[], char word[]);

int isAnagram(tree memory,char word[],FILE *anagramList,int keyWordSize);
