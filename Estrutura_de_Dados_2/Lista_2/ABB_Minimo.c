#include <stdio.h>
#include <stdlib.h>
typedef struct no{
   int chave;
   struct no *esq, *dir;
} no;
no* minimo(no* r){
    if(r!= NULL){
    no* min = r;
    while(min->esq != NULL){
        min = min->esq;
    }
    return min;
    }
    else{
        return NULL;
    }
}