#include <stdio.h>
#include <stdlib.h>
typedef struct no{
   int chave;
   struct no *esq, *dir;
} no;
no* maximo(no* r){
    if(r!= NULL){
    no* max = r;
    while(max->dir != NULL){
        max = max->dir;
    }
    return max;
    }
    else{
        return NULL;
    }
}