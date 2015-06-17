int bitwiseXOR(int register0,int data){
    
    int register0Binary[4]={0,0,0,0};
    int dataBinary[4]={0,0,0,0};
    int answerBinary[4]={0,0,0,0};
    int answer=0;
    int counter=0;
    
    for(counter=0;counter<4;counter++){
    
        register0Binary[counter] = register0%2;
        register0=register0/2;
        dataBinary[counter] = data%2;
        data=data/2;
        if(register0Binary[counter]==1 || dataBinary[counter]==1){
        
            answerBinary[counter]=1;
            
        }
        else{
        
            answerBinary[counter]=0;
            
        }
    }
    
    for(counter=0;counter<4;counter++){
        
        answer=answer+answerBinary[counter]*(pow(2,counter));
    }
    
    return answer;
    
} 
