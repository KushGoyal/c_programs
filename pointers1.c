#include <stdio.h>

void swap (int *a, int *b);
void sum(int *a, int *b, int *z);
int main (int arc, char *argv[]){
    int x=2;
    int y=3;
    int z=0;
    printf ("z = %d\n",z);
    swap(&x,&y);
    printf("x = %d and y = %d \n" ,x,y);
    sum (&x,&y,&z);
    printf ("sum = %d\n",z);
    printf ("%d %p %p\n",*&x,&y,&z);
    return 0;
}

void swap (int *a, int *b){
     int temp;
     temp = *a;
     *a = *b;
     *b = temp;
     }

void sum(int *a, int *b, int *z){
     *z = *a + *b;
     }
