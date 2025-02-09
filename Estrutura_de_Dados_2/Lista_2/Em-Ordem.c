#include <stdio.h>
#include <stdlib.h>
//Recursivo:
// typedef struct no{
//    int dado;
//    struct no *esq, *dir;
// } no;
// void em_ordem (no *raiz){
//     em_ordem(raiz->esq);
//     printf("%d", raiz->dado);
//     em_ordem(raiz->dir);
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
    pilha *novo = (pilha*)malloc(sizeof(pilha));
    novo->dados = n;
    novo->prox = *topo;
    *topo = novo;
}
no* desempilhar(pilha **topo){
    if (*topo != NULL){
    pilha *temp = *topo;
    *topo = temp->prox;
    no *n = temp->dados;
    free(temp);
    return n;
    }else{
        return NULL;
    }
}
void em_ordem(no *raiz){
    pilha *topo = NULL;
    no *atual = raiz;
    while (atual != NULL || topo != NULL){
        while (atual != NULL){
            empilha(&topo, atual);
            atual = atual->esq;
        }
        atual = desempilhar(&topo);
        if (atual != NULL){
            printf("%d ", atual->dado);
            atual = atual->dir;
        }
    }
    printf("\n");
}