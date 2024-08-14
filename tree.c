#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct node{
    ElemType element;
    struct node *lchild;
    struct node *rchild;
}Node;

typedef struct tree{
    struct node *root;
}Tree;

void Create(Tree *T){
    T->root=NULL;
}

bool Root(Tree *T, ElemType *e){
    if(T->root){
        e=&T->root->element;
        return true;
    }
    else{
        return false;
    }
}

Tree *New(ElemType x,Node *lc,Node *rc){
    Node *t=(Node *)malloc(sizeof(Node));
    t->element=x;
    t->lchild=lc;
    t->rchild=rc;
    return t;
}

bool Make(Tree *T,ElemType e,Tree *l,Tree *r){
    if(T->root||l==r){
        return false;
    }
    T->root=New(e,l->root,r->root);
    l->root=r->root=NULL;
    return true;
}

// bool Make(Tree *T,ElemType e,Node *l,Node *r){
//     if(T->root||l==r){
//         return false;
//     }
//     T->root=New(e,l,r);
    
//     return true;
// }



bool Pre(Node *N){
    if(!N){
        return false;
    }
    printf("%c",N->element);
    Pre(N->lchild);
    Pre(N->rchild);
    return true;
}

void PreT(Tree *T){
    Pre(T->root);
}

int main(){
    Tree a,b,c,d,e;
    Create(&a);
    Create(&b);
    Create(&c);
    Create(&d);
    Create(&e);

    Make(&c,'A',&a,&b);
    Make(&d,'B',&a,&b);
    Make(&e,'C',&c,&d);
    Make(&c,'D',&a,&b);
    Make(&d,'E',&c,&e);

    PreT(&d);
    return 0;
}




