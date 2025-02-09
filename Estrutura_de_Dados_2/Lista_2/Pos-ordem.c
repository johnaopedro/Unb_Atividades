#include <stdio.h>
#include <stdlib.h>
//Recursivo:
// typedef struct no{
//    int dado;
//    struct no *esq, *dir;
// } no;
// void pos_ordem(no *raiz){
//     pos_ordem(raiz->esq);
//     pos_ordem(raiz->dir);
//     printf("%d", raiz->dado);
// }
typedef struct no{
    int dado;
    struct no *esq, *dir;
} no;
typedef struct pilha{
    no* dados;
    struct pilha* prox;
} pilha;
void empilha(pilha **topo, no *n){
    pilha *novo =(pilha*)malloc(sizeof(pilha));
    novo->dados = n;
    novo->prox = *topo;
    *topo = novo;
}
no* desempilha(pilha **topo){
    if(*topo != NULL){
    pilha *temp = *topo;
    *topo = temp->prox;
    no *n = temp->dados;
    free(temp);
    return n;
    }else{
        return NULL;
    }
}
void pos_ordem(no *raiz){
    if(raiz == NULL) return;
    pilha *topo = NULL;
    no *atual = raiz;
    no *ultimo_processado = NULL;
    while(atual != NULL || topo != NULL){
        while(atual != NULL){
            empilha(&topo, atual);
            atual = atual->esq;
        }
        atual = topo->dados;
        if(atual->dir == NULL || atual->dir == ultimo_processado){
            printf("%d ", atual->dado);
            ultimo_processado = atual;
            desempilha(&topo);
            atual = NULL;
        } else{
            atual = atual->dir;
        }
    }
    printf("\n");
}