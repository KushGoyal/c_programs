/**

    1-byte Instructions

    0 =  HALT
    1 = Add (R0 = R0 + R1  =
    2 = Subtract (R0 = R0 - R1)
    3 = Increment R0 (R0 = R0 + 1)
    4 = Increment R1 (R1 = R1 + 1)
    5 = Decrement R0 (R0 = R0 - 1)
    6 = Decrement R1 (R1 = R1 - 1)
    7 = Swap Registers (R0 <=> R1) and ring bell!||
    
    2-byte Instructions
    value of the second byte is called <data>


    8 = R0=(R0 bitwise-xor <data>) and
      print <data> (The numerical value of <data> is printed)
    9 =  Load value at address <data> into R0
    A =  Load value at address <data> into R1
    B =  Store R0 into address <data>
    C =  Store R1 into address <data>
    D =  Jump to address <data>
    E =  Jump to address <data> if R0 == 0
    F =  Jump to address <data> if R0 != 0

**/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define MEM_SIZE 16
#define MAX_CYCLES 2000
#define TRUE 1
#define FALSE 0
#define TEN_HEX 16
#define DEFAULT_INST 0xfedcba9876543210
#define ONE_BYTE_END 0x8

//stores the hexadecimal number into an 
//array starting from least sig digit at position 0:
void getHexDigits(int hexDigits[],unsigned long long int number){
    
    int counter=0;
    while(counter<TEN_HEX){
        hexDigits[counter]=0;
        counter++;
    }
    counter=0;
    while(number!=0 && counter<MEM_SIZE){
        
        hexDigits[counter]=number%TEN_HEX;
        number=number/TEN_HEX;
        counter++;
    }
    /*
    counter=0;
    while(counter<16){
        printf("%x ",hexDigits[counter]);
        counter++;
    }
    printf("\n");
    */  
}

//mods the number by 16 and then wraps the number around 16:
int modBy16(int number){

    if(number>0){
        number=number%TEN_HEX;
    }
    else{
        number = number%TEN_HEX;
        number = TEN_HEX+number;
    }
    return number;
}

//runs the 4442 chip emulator and 
//returns the number of cycles for a given memory instruction set: 
int emulator(unsigned long long int memoryInst, int instructions[]){

    int register0 = 0;
    int register1 = 0;
    int address = 0;
    int temp = 0;
    int cycleCounter=1;
    int memory[MEM_SIZE];

    
    //insert the input values into the chip memory:
    getHexDigits(memory,memoryInst);

    //conditions based on default instructions:
    while(memory[address]!=instructions[0] 
            && address<MEM_SIZE 
            && cycleCounter<MAX_CYCLES){
    
        if(memory[address]==instructions[1]){
    
            register0=register0+register1;
            if(register0 >TEN_HEX-1 || register0 < 0){
                register0=modBy16(register0);
            }
            address++;
        
        }
        else if(memory[address]==instructions[2]){
    
            register0=register0-register1;
            if(register0 >TEN_HEX-1 || register0 < 0){
                register0=modBy16(register0);
            }            
            address++;
        }
        else if(memory[address]==instructions[3]){
        
            register0=register0+1;
            if(register0>TEN_HEX-1 || register0 < 0){
                register0=modBy16(register0);
            }
            address++;
        }
        else if(memory[address]==instructions[4]){
    
            register1=register1+1;
            if(register1>TEN_HEX-1 || register1 <0){
                register1=modBy16(register1);
            }
            address++;
        }
        else if(memory[address]==instructions[5]){
        
            register0=register0-1;
            if(register0>TEN_HEX-1 || register0 <0){
                register0=modBy16(register0);
            }
            address++;
        }
        else if(memory[address]==instructions[6]){
    
            register1=register1-1;
            if(register1>TEN_HEX-1 || register1 <0){
                register1=modBy16(register1);
            }
            address++;
        }
        else if(memory[address]==instructions[7]){
    
            temp = register0;
            register0=register1;
            register1=temp;
            //printf("Beep Beep\n");
            address++;
        }
        else if(memory[address]==instructions[8]){
        
            register0=register0^memory[address+1];
            if(register0>TEN_HEX-1 || register0<0){
                register0=modBy16(register0);
            }           
            //printf("Data = %x\n",memory[address+1]);
            address = address+2;
        
        }
        else if(memory[address]==instructions[9]){
    
            register0=memory[memory[address+1]];
            if(register0>TEN_HEX-1 || register0<0){
                register0=modBy16(register0);
            }
            address=address+2;
        
        }
        else if(memory[address]==instructions[10]){
        
            register1=memory[memory[address+1]];
            if(register1>TEN_HEX-1 || register1 <0){
                register1=modBy16(register1);
            }
            address=address+2;
        
        }
        else if(memory[address]==instructions[11]){
        
            memory[memory[address+1]]=register0;
            address=address+2;
        }
        else if(memory[address]==instructions[12]){
        
            memory[memory[address+1]]=register1;
            address=address+2;
        }
        else if(memory[address]==instructions[13]){
        
            address = memory[address+1];
        
        }
        else if(memory[address]==instructions[14]){
        
            if(register0==0){
            
                address = memory[address+1];
            
            }
            else{
            
                address = address+2;
            }
        }
        else if(memory[address]==instructions[15]){
        
            if(register0!=0){
            
                address = memory[address+1];
            
            }
            else{
            
                address = address+2;
            }
        }
        
        cycleCounter++;
    }
    
    /*
    
    //prints the memory:
    printf("\n");
    for(address=0;address<MEM_SIZE;address++){
    
        if((address+1)%4==0){
            printf("%x ",memory[address]);
            printf("\n");   
        }
        else{
            printf("%x ",memory[address]);
        }
        
    }
    
    //prints registers:
    printf("\nregister 0: %hhx\n",register0);
    printf("register 1: %hhx\n",register1);
    
    
    */
    
    return cycleCounter;
    
}   

//returns 0 in case power is -ve else returns the correct answer:
unsigned long long int power(int number, int pow){
    
    int counter=0;
    unsigned long long int answer=1;
    if(pow<0){
        answer=0;
    }
    else{
        for(counter=0;counter<pow;counter++){
        
            answer = answer*number;
        }
    }
    return answer;
}    
    
//checks if the given byte is a two byte instruction:
int checkTwoByte(int byte,int instructions[]){

    int twoByte = TRUE;
    
    if( byte!=instructions[15] && byte!=instructions[11] &&
        byte!=instructions[14] && byte!=instructions[10] &&
        byte!=instructions[13] && byte!=instructions[9]  &&
        byte!=instructions[12] && byte!=instructions[8]  ){
        
            twoByte = FALSE;
            
    }
    
    return twoByte;
    
}

int checkLoop(int byte,int instructions[]){

    int loop = FALSE;
    
    if( byte!=instructions[14] && byte!=instructions[15] ){
        
            loop = TRUE;
            
    }
    
    return loop;
    
}

//checks if the given input for the chip is
//worth emulating for max cycles or not:  
int isWorth(unsigned long long int memoryInst,int instructions[],int numByte,
            unsigned long long end){
    
    int worth = FALSE;
    int byte = 0;
    unsigned long long int number = memoryInst;
    int numOneByte = 0;
    int numLoop = 0;  
        
        while(number!=0&&numOneByte!=numByte){
            
            byte = number%TEN_HEX;
            //if(checkTwoByte(byte,instructions)){
                //number=0;
                //numOneByte=0;
            //}
            //else{
            if(!checkTwoByte(byte,instructions)){
                numOneByte++;
                if(byte==instructions[0]){
                    numOneByte=numByte;
                }
            }
            if(checkLoop(byte,instructions)){
                numLoop++;
            }
            number=number/TEN_HEX;
        }
        if(numOneByte!=numByte&&numLoop!=numByte){
            worth=TRUE;
        }
    
    return worth;
    
}


//prints out the winning input set:          
void printMaxInst(unsigned long long maxInst,int permutation[],
                    int instructions[],int numByte){
    
    unsigned long long int number = maxInst;
    int counter= 0;
    int byte = 0;
    int answer[numByte];
    int digit = 0;
    
    for(counter=0;counter<numByte;counter++){
        
        answer[counter]=0;
        
    }
    
    counter=0;
    
    while(number!=0){
        
        byte = number%TEN_HEX;
        
        for(counter=0;counter<MEM_SIZE;counter++){
            
            if(byte==instructions[counter]){
                
                answer[digit] = permutation[counter];
                digit++;
                
            }
        }
        
        number = number/TEN_HEX;
        
    }
    
    for(counter=0;counter<numByte;counter++){
    
        printf("%x ",answer[counter]);
        
    }
    
    printf("\n");
    
}


//returns the maximum cycle count for a given permuted instruction set
//and given number of bytes for the memory input:               
int getCycleCount(int numByte,unsigned long long int permutedInst){
    
    unsigned long long counter = 0;
    int cycles = 0;
    int maxCycles = 0;
    unsigned long long maxInst = 0;
    int instructions[MEM_SIZE];
    int permutation[MEM_SIZE];
    int infLoops = 0;
    
    //unsigned long long int start = ONE_BYTE_END * power(TEN_HEX,numByte-2);
    unsigned long long int start = power(TEN_HEX,numByte-1);
    
    //unsigned long long end = ONE_BYTE_END * power(TEN_HEX,numByte-1);
    unsigned long long end = power(TEN_HEX,numByte);
    
    getHexDigits(instructions,DEFAULT_INST);
    getHexDigits(permutation,permutedInst);
    
    //if number of bytes is 1:
    if(numByte==1){
        maxCycles=1;
        maxInst=instructions[1];
    }
    
    else{
    
        //generate all the possible n-byte instruction sets:
        for(counter=start;counter<end;counter++){
    
        //checks if it is required to emulate the number or not:
            if(isWorth(counter,instructions,numByte,end)){
                cycles = emulator(counter,instructions);

                //if it is an infinite loop:
                if(cycles>=MAX_CYCLES){
                    cycles = 0;
                    infLoops++;
                }
                else if(cycles>maxCycles){
                    maxCycles = cycles;
                    maxInst = counter;
                }
            }
        }
    }
    
    printf("Number of infinite loops: %d\n",infLoops);
    printf("The winning instruction set: ");
    printMaxInst(maxInst,permutation,instructions,numByte);
    
    return maxCycles;
    
}              
                   
                
    
    
    
    
 
