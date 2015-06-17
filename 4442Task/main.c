#include"emulator.h"

int main(int argc,char *argv[]){
    
    testAll();
    
    //input the number bytes to get answer for:
    int numByte=0;
    printf("Enter the number of bytes:");
    scanf("%d",&numByte);    
    assert(numByte<17&&numByte>0);
    
    //input the permuted instructions:
    unsigned long long int permutedInst= DEFAULT_INST;
    //printf("Enter the permuted instrutcion set:");
    //scanf("%llx",&permutedInst);
    
    int maxCycles = getCycleCount(numByte,permutedInst);
    
    printf("Max number of cycles:%d\n",maxCycles);
    
    return 0;
    
}
