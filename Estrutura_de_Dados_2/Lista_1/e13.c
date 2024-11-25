#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
   int dado;
   struct celula *prox;
} celula;
celula *busca (celula *le, int x){
if(le == NULL){
    return NULL;
}
celula *p;
p = le->prox;
while(p != NULL && p->dado != x){
p = p->prox;}
return p;}
celula *busca_rec (celula *p, int x){
if(p == NULL){
    return NULL;
}
if(p->dado == x){
    return p;
}
return busca_rec(p->prox, x);
}