#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"emulator.h"

#define MEM_SIZE 16
#define MAX_CYCLES 2000
#define TRUE 1
#define FALSE 0
#define TEN_HEX 16
#define DEFAULT_INST 0xfedcba9876543210
#define ONE_BYTE_END 0x8

void testGetHexDigits(void);

void testPower(void);

void testCheckTwoByte(void);

void testIsWorth(void);

void testModBy16(void);

void testEmulator(void);
                    
void testAll(void){
    
    testGetHexDigits();
    testModBy16();
    testEmulator();         
    testPower();
    testCheckTwoByte();  
    testIsWorth();
    
    printf("\nAll Passed!!\n");
    
}

void testGetHexDigits(void){
    
    int hexDigits[MEM_SIZE];
    unsigned long long int number = 0xf1a0edcb0;
    
    getHexDigits(hexDigits,number);
    
    assert(hexDigits[0] == 0x0);
    assert(hexDigits[1] == 0xb);
    assert(hexDigits[2] == 0xc);
    assert(hexDigits[3] == 0xd);
    assert(hexDigits[4] == 0xe);
    assert(hexDigits[5] == 0x0);
    assert(hexDigits[6] == 0xa);
    assert(hexDigits[7] == 0x1);
    assert(hexDigits[8] == 0xf);
    assert(hexDigits[9] == 0);
    assert(hexDigits[10] == 0);
    assert(hexDigits[11] == 0);
    assert(hexDigits[16] != 0xa);
    
    printf("getHexDigits passed!\n");
    
}

void testModBy16(void){

    int number = -0x1feba;
    
    int test = modBy16(number);
    assert(test == TEN_HEX - 0xa);
    
    number = 0xfedba7;
    test = modBy16(number);
    assert(test == 0x7);
    
    number = 0x10;
    test = modBy16(number);
    assert(test == 0x0);
    
    printf("modBy16 passed! \n");
    
}

void testEmulator(void){

    int instructions[MEM_SIZE] = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,
                                  0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf};
    
    unsigned long long int memoryInst = 0xa04f657aa29;
    int test = emulator(memoryInst,instructions);
    assert(test==43);
    
    memoryInst = 0x4404f657aab9;
    test = emulator(memoryInst,instructions);
    assert(test==19);
    
    printf("emulator passed\n");    
 
}

void testPower(void){
    
    int number = TEN_HEX;
    int pow = 4;
    
    unsigned long long test = power(number,pow);
    
    assert(test == TEN_HEX*TEN_HEX*TEN_HEX*TEN_HEX);
    
    test = power(TEN_HEX,0);
    
    assert(test == 1);
    
    printf("power passed! \n");
    
}

void testCheckTwoByte(void){

    int byte = 0xe;
    int instructions[MEM_SIZE] = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,
                                  0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf};
    
    int test = checkTwoByte(byte,instructions);
    assert(test ==1);
    
    byte = 0x7;
    test = checkTwoByte(byte,instructions);
    assert(test == 0);

    printf("checkTwoByte passed! \n");    
    
}

    
void testIsWorth(void){

    unsigned long long int memoryInst = 0xfedbca0;
    
    int instructions[MEM_SIZE] = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,
                                  0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf};
    
    int numByte = 7;
    
    unsigned long long end = power(0x10,7);
    
    int test = isWorth(memoryInst,instructions,numByte,end);
    assert(test == 0);
    
    memoryInst = 0x7654321;
    test = isWorth(memoryInst,instructions,numByte,end);
    assert(test == 0);
    
    printf("isWorth passed!\n");
    
} 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
