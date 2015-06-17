#include"jousafus.h"

int main (int argv,char* argc[]){
    
    ring playRing = malloc(sizeof(node));
    assert(playRing != NULL);
    
    int ringSize=0;
    printf("\nEnter the ring size:");
    scanf("%d",&ringSize);
    
    int jNum=0;
    printf("\nEnter the Jousafus number:");
    scanf("%d",&jNum);

    playRing = makeRing(playRing,ringSize);
    playRing = jousafus(playRing,jNum);
    printf("\nThe resulting number:");
    printRing(playRing);
    return 0;
    
}
