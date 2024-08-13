#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct queue{
    int front;
    int rear;
    int maxsize;
    ElemType *element;
}Queue;

// bool Empty(Queue *Q){
//     return 
// }

bool Create(Queue *Q,int msize){
    Q->maxsize=msize;
    Q->element=(ElemType *)malloc(sizeof(ElemType)*msize);
    Q->front=Q->rear=0;

}

bool Insert(Queue *Q,ElemType e){
    if((Q->rear+1)%Q->maxsize==Q->front){
        return false;
    }
    Q->rear=(Q->rear+1)%Q->maxsize;
    Q->element[Q->rear]=e;
    
    return true;
}

bool Push(Queue *Q,ElemType *e){
    if(Q->rear==Q->front){
        return false;
    }
    Q->front=(Q->front+1)%Q->maxsize;
    *e=Q->element[Q->front];
    
    printf("Push %d\n",*e);
    return true;
}

int main(){
    Queue test;
    int e;
    Create(&test,5);

    Insert(&test,1);
    Insert(&test,2);
    Insert(&test,3);
    Insert(&test,4);
    

    Push(&test,&e);
    Insert(&test,5);
    Push(&test,&e);
    Push(&test,&e);
    Push(&test,&e);
    Push(&test,&e);
}

