#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){

    int x[4] = {1,2,3,4};
    
    printf("%p\n",x);
    //printf("%d",&x);
    printf("%d\n",*x);
    printf("%p\n",&*x);
    printf("%d\n",*(x+1));
    return 0;
    
}
    
