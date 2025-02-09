#include <stdio.h>
#include <stdlib.h>
typedef struct no{
   int chave;
   struct no *esq, *dir;
} no;
int altura (no *r){
    if (r!=NULL){
        int hd = altura(r->esq);
        int he = altura(r->dir);
        if (he > hd) return he + 1;
        else return hd + 1; 
    }
    else{ 
        return 0;
    }
}