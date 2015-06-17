#include<stdio.h>
#include<stdlib.h>

#define MEM_SIZE 16

int modBy16(int number);

int power(int number, int pow);

void instGenerator(int numByte);

int main(int argc,char *argv[]){

    unsigned long long hexaNum=0x0;
    unsigned long long deciNum=0;
    int counter = 0;
    for(counter=0;counter<16;counter++){
        
        hexaNum++;
        deciNum++;
        printf("hexa: %llx deci: %lld\n",hexaNum,deciNum);
    }
    
    scanf("%llx",&hexaNum);
    
    printf("%llx\n",hexaNum);
    printf("%llu\n",hexaNum);
    int randNum1=modBy16(hexaNum);
    int randNum2=hexaNum%16;
    printf("num1: %x num2:%x \n",randNum1,randNum2);
    int hexDigits[16];
    counter=0;
    while(counter<16){
        hexDigits[counter]=0;
        counter++;
    }   
    counter=0;
    while(hexaNum!=0 && counter<16){
        
        hexDigits[counter]=hexaNum%16;
        hexaNum=hexaNum/16;
        counter++;
    }

    /*
    int temp=0;
    counter=0;
    while(counter<8){
        temp=hexDigits[15-counter];
        hexDigits[15-counter]=hexDigits[counter];
        hexDigits[counter]=temp;
        counter++;
    }
    */
    counter=0;
    while(counter<16){
        printf("%x\n",hexDigits[counter]);
        counter++;
    }
    
    unsigned long long num1 = power(0x10,4);
    unsigned long long num2 = (0x8 * power(0x10,3));
    
    printf("%llx\n",num1-num2);
    //printf("the list:\n");
    //instGenerator(2);
    //printf("the list:\n");
    //instGenerator(1);   
    return 0;
}

//mods the number by 16 and returns the least sig digit:
int modBy16(int number){

    if(number>15){
    
        number = number+1;
        number = number - (16 * (number/16));
        if(number==0){
            number=15;   
        }
        else{
            number = number-1;
        }
    }
    return number;
}

//generates all possible n-byte set of instruction values:
void instGenerator(int numByte){

    unsigned long long counter = 0;
    unsigned long long instList[power(0x10,numByte)-power(0x10,numByte-1)];
    
    for(counter=power(0x10,numByte-1);counter<power(0x10,numByte);counter++){
        instList[counter-power(0x10,numByte-1)] = counter;
    }
    for(counter=0;counter<power(0x10,numByte)-power(0x10,numByte-1);counter++){
        printf("%llx ",instList[counter]);
    }
}
       
int power(int number, int pow){
    
    int counter=0;
    int answer=1;
    if(pow==0){
        answer=0;
    }
    else{
        for(counter=0;counter<pow;counter++){
        
            answer = answer*number;
        }
    }
    return answer;
} 








