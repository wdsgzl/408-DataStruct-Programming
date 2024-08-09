#include<stdio.h>
#include<stdbool.h>
#define Maxsize 20
typedef int ElemType;
typedef struct{
    ElemType data[Maxsize];
    int length;
}SSqList;

typedef struct{
    ElemType *data;
    int MaxSize,length;
}DSqList;

void InitList(SSqList *L){
    L->length=0;
}

bool listinsert(SSqList *L,int i,ElemType e){
    if(i<0||i>L->length)
    return false;
    if(L->length>=Maxsize)
    return false;
    for(int j=L->length;j>=i;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;
    return true;
}

bool FindL(SSqList *L,int i,ElemType *e){
    if(i<0||i>L->length)
        return false;
    if(!L->length)
        return false;
    *e=L->data[i];
    return true;
}

bool FindV(SSqList *L,int *v,ElemType e){
    if(L->length==0)
        return false;
    for (int i=0;i<L->length;i++){
        if(L->data[i]==e){
            *v=i;
            return true;
        }
        
    }
    return false;
}

bool Delete(SSqList *L, int i){
    if(i<0||i>L->length)
    return false;
    for(int j=i;j<L->length;j++){
        L->data[j]=L->data[j+1];
    }
    L->length--;
    return true;
}

int main(){
    int x,y;
	SSqList test;
    InitList(&test);
    listinsert(&test,0,10);
    listinsert(&test,1,50);
    listinsert(&test,0,1);
    for(int i=0;i<test.length;i++)
     printf("%d\n",test.data[i]);

    FindL(&test,2,&x);
    printf("findl %d\n",x);

    FindV(&test,&x,50);
    printf("findv %d\n",x);

    Delete(&test,1);
        for(int i=0;i<test.length;i++)
     printf("%d\n",test.data[i]);
    //printf("%d",test.length);
    return 0;
}
