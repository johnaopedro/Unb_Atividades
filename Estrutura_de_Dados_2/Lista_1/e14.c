#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
   int dado;
   struct celula *prox;
} celula;
void mescla_listas(celula *l1, celula *l2, celula *l3){
l1=l1->prox; l2=l2->prox;
celula *p = l3;
if(l1 == NULL){
    p->prox = l2;
}
if(l2 == NULL){
    p->prox = l1;
}
while(l1 != NULL && l2 != NULL){ // possivel usar for(; l1 != NULL && l2 != NULL; p = p->prox)
    if(l1->dado <= l2->dado){
        p->prox = l1;
        l1 = l1->prox;
    }
    else{
        p->prox = l2;
        l2 = l2->prox;
    }
    p = p->prox;
}
if(l1 != NULL){
    p->prox = l1;
}
if(l2 != NULL){
    p->prox = l2;
}
}