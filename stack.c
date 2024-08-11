#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct stack{
    int top;
    int maxsize;
    ElemType *element;
}Stack;

void Create(Stack *S,int msize){
   S->maxsize=msize;
   S->element=(ElemType *)malloc(sizeof(ElemType)*msize);
   S->top=-1; 
}

void Destory(Stack *S){
    S->maxsize=0;
    free(S->element);
    S->top=-1;
}

bool Empty(Stack *S){
    return S->top==-1;
}

bool Full(Stack *S){
    return S->top==S->maxsize-1;
}

bool Top(Stack *S){
    if(Empty(S)){
        return false;
    }
    printf("%d\n",S->element[S->top]);
    return true;
}

bool Push(Stack *S, ElemType e){
    if(Full(S)){
        return false;
    }
    S->top++;
    S->element[S->top]=e;
    return true;
}

bool Pop(Stack *S){
    if(Empty(S)){
        return false;
    }
    S->top--;
    return true;
}

bool show(Stack *S){
    if(Empty(S)){
        return false;
    }
    for(int i=S->top;i>-1;i--){
        printf("%d\n",S->element[i]);
    }
    return true;
}

int main(){
    Stack test;
    Create(&test,5);
    Push(&test,1);
    Push(&test,2);
    Push(&test,3);
    show(&test);
    Top(&test);
    Pop(&test);
    Top(&test);
    
    Top(&test);
}