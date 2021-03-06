#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct vertex *vertexPtr;

typedef struct vertex{
    char name;
    int edgeWgt;
    vertexPtr next;
}vertex;


void makeGraph(vertexPtr graph[],int numVertex);

void printGraph(vertexPtr graph[],int numVertex);

void makeConnections(vertexPtr aVertex, vertexPtr graph[]);

int checkConnection(int counter,vertexPtr aVertex, vertexPtr graph[]);

int main (int argc,char *argv[]){

    int numVertex = 0;
    int counter=0;
    printf("Enter number of vertices:");
    scanf("%d",&numVertex);
    
    vertexPtr graph[numVertex];
    makeGraph(graph,numVertex);
    printGraph(graph,numVertex);
    
    for(counter=0;counter<numVertex;counter++){
        printf("enter connections for %c\n",graph[counter]->name);
        makeConnections(graph[counter], graph);
    }
    printGraph(graph,numVertex);
    return 0;
    
}

void makeGraph(vertexPtr graph[],int numVertex){
    
    int counter=0;
    
    for(counter=0;counter<numVertex;counter++){
        
        graph[counter] = malloc(sizeof(vertex));
        assert(graph[counter]!=NULL);
        graph[counter]->name = 'a'+counter;
        graph[counter]->edgeWgt = 0;
        graph[counter]->next = NULL;
        
    }
    
}

void printGraph(vertexPtr graph[],int numVertex){
    
    int counter=0;
    vertexPtr temp = NULL;
    for(counter=0;counter<numVertex;counter++){
        
        temp = graph[counter];
        printf("vertex %d :",counter);
        printf("%c %d",temp->name,temp->edgeWgt);
        while(temp->next!=NULL){
            
            temp = temp->next;
            printf("->");
            printf("%c %d",temp->name,temp->edgeWgt);
            
        }
        
        printf("\n");
    }
    
}

void makeConnections(vertexPtr aVertex, vertexPtr graph[]){

    vertexPtr temp = aVertex;
    int numConn = 0;
    int counter = 0;
    int wgt = 0;
    int checkConn = 0;
    printf("Number of connections:");
    scanf("%d",&numConn);
    
    while(numConn!=0){
    
        vertexPtr connection = malloc(sizeof(vertex));
        assert(connection!=NULL);
        printf("enter vertex counter:");
        scanf("%d",&counter);
        checkConn = checkConnection(counter,aVertex,graph);
        if(checkConn==-1){
            printf("enter edge weight:");
            scanf("%d",&wgt);
        }
        else{
            wgt = checkConn;
        }
        connection->name = graph[counter]->name;
        //temp->edgeWgt = (connection->name+temp->name)/(counter+1);
        temp->edgeWgt = wgt;
        temp->next = connection;
        temp = connection;
    
        numConn--;
    }
    
}
    
int checkConnection(int counter,vertexPtr aVertex, vertexPtr graph[]){
    
    vertexPtr temp;
    temp = graph[counter];
    int wgt=-1;
    while(temp!=NULL){
        
        if(temp->name==aVertex->name){
            wgt = temp->edgeWgt;
        }
        temp = temp->next;
    }
    return wgt;
}
           
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        
