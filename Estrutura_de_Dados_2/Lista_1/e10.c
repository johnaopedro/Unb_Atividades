#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
   int dado;
   struct celula *prox;
} celula;
void imprime(celula *le){
if(le == NULL){
    printf("NULL\n");
}
celula *atual = le->prox;
while(atual != NULL){
    printf("%d -> ", atual->dado);
    atual = atual->prox;
}
    printf("NULL\n");
}
void imprime_rec(celula *le){
if(le == NULL){
    printf("NULL\n");
}
if(le->prox != NULL){
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
} else{
    printf("NULL\n");
}}