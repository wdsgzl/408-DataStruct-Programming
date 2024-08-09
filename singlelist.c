#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node{
    ElemType element;
    struct node *next;
}Node;

typedef struct singlelist{
    Node *first;
    int length;
}Single;

bool Init(Single *L){
    L->first=NULL;
    L->length=0;
    return true;
}

bool Insert(Single *L,int i,ElemType e){
    Node *p,*q;
    if(i<-1||i>L->length-1)
        return false;
    p=L->first;
    for(int j=0;j<i;j++){
        p=p->next;
    }
    q=(Node*)malloc(sizeof(Node));
    q->element=e;
    if(i>-1){
        q->next=p->next;
        p->next=q;
    }
    if(i==-1){
        q->next=L->first;
        L->first=q;
    }
    printf("Insert OK\n");
    L->length++;
    
    return true;
}

bool Find(Single *L,int i,ElemType *e){
    Node *p;
    if(i<0||i>L->length-1)
    return false;
    p=L->first;
    for(int j=0;j<i;j++){
        p=p->next;
    *e=p->element;
    printf("find %d\n",*e);
    return true;
    }

}

bool Delete(Single *L,int i){
    
    Node *p,*q;
    if(i<0||i>L->length-1){
        return false;
    }
    if(L->length==0){
        return false;
    }
    q=L->first;
    p=L->first;
    for(int j=0;j<i-1;j++){
        q=q->next;
    }
    if(i==0){
        L->first=L->first->next;
    }
    else{
        p=q->next;
        q->next=p->next;
    }
    free(p);
    printf("Delete OK\n");
    L->length--;
    return true;
}

bool show(Single *L){
    Node *p;
    if(L->length==0)
        return false;
    p=L->first;
    while(p){
        printf("%d\n",p->element);
        p=p->next;
    }
    return true;
}

int main(){
    Single test;
    Node t;
    int x;
    Init(&test);

    Insert(&test,-1,0);
    Insert(&test,0,1);
    Insert(&test,0,2);
    Insert(&test,-1,3);
    show(&test);

    Delete(&test,1);

    show(&test);

    Find(&test,2,&x);
}
