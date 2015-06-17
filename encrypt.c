#include <stdio.h>
#include <ctype.h>

int main (int argc, char* argv[]){
    char cypher[] = "bcdefghijklmnopqrstuvwxyza";
    int plainChar = getchar();
    while (plainChar != EOF){
          
        if(islower(plainChar)){
          
            putchar(cypher[plainChar-'a']);
        }
        else{
            
            putchar(plainChar);
        }
                                   
        plainChar=getchar();
    }
                                   
    return 0;
}
    
