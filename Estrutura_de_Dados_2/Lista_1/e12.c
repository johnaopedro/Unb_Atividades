#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
   int dado;
   struct celula *prox;
} celula;
int remove_depois(celula *p){
if(p->prox==NULL){
    return -1;
}
celula *x=p->prox;
p->prox=x->prox;
free(x);
return  0; //função int. LEMBRAR DE FAZER RETORNO.
}
void remove_elemento(celula *le, int x){
celula *atual=le;
celula *anterior=NULL;
while(atual != NULL){
    if(atual->dado==x){
        if(anterior != NULL){
            anterior->prox=atual->prox;
        } else{
            le=atual->prox;
        }
        free(atual);
        break;
    }
    anterior=atual;
    atual=atual->prox;
}}
void remove_todos_elementos(celula *le, int x){
celula *atual=le;
celula *anterior=NULL;
while(atual != NULL){
    if(atual->dado==x){
        if(anterior==NULL){
            le=atual->prox;
            free(atual);
            atual=le;
        } else{
            anterior->prox=atual->prox;
            free(atual);
            atual=anterior->prox;
        }
    } else{
        anterior=atual;
        atual=atual->prox;
}}}