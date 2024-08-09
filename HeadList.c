#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType element;
    struct node *next;
}Node;
typedef struct headlist{
    Node *head;
    int length;
}HeadList;

bool Init(HeadList *L){
    L->head=(Node *)malloc(sizeof(Node));
    if(!L->head){
        return false;
    }
    L->head->next=NULL;
    L->length=0;
    return true;
}

bool Insert(HeadList *L,int i,ElemType e){
    Node *p,*q;
    if(i<-1||i>L->length-1){
        return false;
    }
    p=L->head;
    for(int j=0;j<=i;j++){
        p=p->next;
    }
    q=(Node *)malloc(sizeof(Node));
    q->element=e;
    q->next=p->next;
    p->next=q;
    L->length++;
    return true;
}

bool Delete(HeadList *L,int i){
    Node *p,*q;
    if(i<-1||i>L->length-1){
        return false;
    }
    if(!L->length){
        return false;
    }
    q=L->head;
    for(int j=0;j<i;j++){
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    free(p);
    L->length--;
    return true;
}

bool show(HeadList *L){
    Node *p;
    //printf("%d",L->length);
    if(L->length==0){
        return false;
    }
    p=L->head;
    // for(int i=0;i<L->length;i++){
    //     p=p->next;
    //     printf("%d\n",p->element);
    // }
    while(p->next){
                p=p->next;
        printf("%d\n",p->element);
    }
    return true;
    
}

int main(){
    HeadList test;
    Init(&test);
    Insert(&test,-1,0);
    Insert(&test,0,1);
    Insert(&test,0,2);
    Insert(&test,-1,3);

    show(&test);
    Delete(&test,0);
    

    show(&test);
}