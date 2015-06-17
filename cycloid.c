#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define pi 3.14

int main(int argc, char * argv[]){
    
    float radius = 0;
    int limitNum = 0;
    float pathLength = 0;
    float counter = 0;
    
    //x coordinate:
    float x1 = 0;
    float x2 = 0;
    
    //y coordinate:
    float y1 = 0;
    float y2 = 0;
    
    //angle:
    float theta = 0;
    
    printf("Enter the radius:");
    scanf("%f",&radius);
    
    printf("\nEnter the limit number:");
    scanf("%d",&limitNum);
    
    while(counter<limitNum){
    
        theta = 2 * pi / limitNum ;
    
        y1 = radius * (1 - cos(counter * theta));
        x1 = radius * (counter * theta - sin(counter * theta));
    
        y2 = radius * (1 - cos((counter+1)* theta));
        x2 = radius * ((counter+1)* theta - sin((counter+1)* theta));
    
        pathLength = pathLength + sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
    
        counter++;
    
    }
    
    printf("\nthe cycloid length is:%f\n",pathLength);
    
    return 0;
    
}
    
    
