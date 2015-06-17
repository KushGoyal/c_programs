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

unsigned long long int power(int number, int pow);

void getHexDigits(int hexDigits[],unsigned long long int number);

int checkTwoByte(int byte,int instructions[]);

int checkLoop(int byte,int instructions[]);

int isWorth(unsigned long long int memoryInst,int instructions[],int numByte,unsigned long long end);

int modBy16(int number);

int emulator(unsigned long long int memoryInst, int instructions[]);

void printMaxInst(unsigned long long maxInst,int permutation[],
                    int instructions[],int numByte);
                    
int getCycleCount(int numByte,unsigned long long int permutedInst);

void testAll(void);
