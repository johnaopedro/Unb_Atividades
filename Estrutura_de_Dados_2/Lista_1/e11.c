#include <stdio.h>
#include <stdlib.h>
typedef struct celula{
   int dado;
   struct celula *prox;
} celula;
void insere_inicio(celula *le, int x){
celula *novo_le =(celula *)malloc(sizeof(celula));
novo_le->dado = x;
novo_le->prox = le->prox;
le->prox = novo_le;
}
void insere_antes(celula *le, int x, int y){
celula *inicio = le;
while(inicio->prox != NULL && inicio->prox->dado != y){
    inicio = inicio->prox;}
celula *novo_valor =(celula *)malloc(sizeof(celula));
novo_valor->dado = x; //NOVO VALOR DENTRO DA LISTA
if(inicio->prox != NULL){ //GARANTINDO N ACESSAR NULO
    if (inicio->prox->dado == y){
        novo_valor->prox = inicio->prox; // Vê y E CONECTA AO PROX
        inicio->prox = novo_valor; // BOTA novo valor
    }
} else{
    //Y ausente
    novo_valor->prox = NULL;//Ultimo valor da lista
    inicio->prox = novo_valor;//Coloca valor
}}