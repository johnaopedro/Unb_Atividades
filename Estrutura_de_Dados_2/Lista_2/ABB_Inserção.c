#include <stdio.h>
#include <stdlib.h>
typedef struct no{
   int chave;
   struct no *esq, *dir;
} no;
no* criar_no(int x){
    no* novo = (no*)malloc(sizeof(no));
    if (novo){
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}
no* inserir(no* r, int x){
    if(r!=NULL){
    if(x < r->chave){
        r->esq = inserir(r->esq, x);
    } else if(x > r->chave){
        r->dir = inserir(r->dir, x);
    }
    return r;
    }
    else{
        return criar_no(x);
    }
}