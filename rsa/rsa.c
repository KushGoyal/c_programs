#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef unsigned long long int bigNumber;

bigNumber power(bigNumber message,bigNumber exp);

int main(int argc,char* argv[]){
    
    bigNumber newMessage = power(254,25);
    printf("the new message is:%llu\n",newMessage);
    return 0;
    
}

bigNumber power(bigNumber message,bigNumber exp){
    
    int counter=0;
    bigNumber copyExp = exp;
    bigNumber answer=message;
    while(copyExp!=0){
        copyExp=copyExp/2;
        counter++;
    }
    int expCount = counter;
    bigNumber expList[expCount];
    counter=0;
    while(exp!=0){
        if(counter==0){
            answer=answer;
        }
        else{
            answer = answer*answer;
        }
        if(exp%2==1){
            expList[counter] = answer;
        }
        else{
            expList[counter]=1;
        }
        exp=exp/2;
        counter++;
    }
    counter=0;
    answer=1;
    while(counter<expCount){
        answer=expList[counter]*answer;
        counter++;
    }
    
    return answer; 
}
    
