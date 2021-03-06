#include"anagrams.h"

int main(int argc,char *argv[]){

    int alphabet = 0;
    char wordList[MAX_LIST_SIZE];
    int current = 0;
    int counter = 0;
    char word[MAX_WORD_SIZE] = "abcdefghijklmnoprstu";
    
    //declaring a node on stack frame:
    node seedNode;
    
    //initializing the seedNode as a tree:
    tree memory = &seedNode;
    memory->wordPtr = word;
    memory->left = NULL;
    memory->right = NULL;
    
    //input file:
    FILE *words;
    words = fopen("words.txt", "r");
    assert(words != NULL);
    
    //output file:
    FILE *anagramList;
    anagramList = fopen("anagrams.txt", "w");
    assert(anagramList != NULL);
    
    while (alphabet != EOF && current < MAX_LIST_SIZE){
        
        alphabet = getc(words);
        wordList[current] = alphabet;
        current++;
            
    }
    
    fclose(words);   
    int listSize = current-1;
    int keyWordSize = 0;
    char keyWord[MAX_WORD_SIZE];
    current = 0;
    int anagramNum = 0;
    for(counter=0;counter<MAX_WORD_SIZE;counter++){
        
        keyWord[counter] = '0';
            
    }
    
    while(current<listSize){
        
        counter = 0;
        
        while(wordList[current] != NEW_LINE && wordList[current]!=EOF){
        
            keyWord[counter] = wordList[current];
            counter++;
            current++;
            
        }
        
        keyWordSize = counter;
        
        if(isAnagram(memory,keyWord,anagramList,keyWordSize)){
        
            anagramNum++;
        }
        
        for(counter=0;counter<MAX_WORD_SIZE;counter++){
        
            keyWord[counter] = '0';
            
        }
        
        current++;
    }
    
    printf("Anagrams found:%d\n",anagramNum);

    return 0;
    
}
