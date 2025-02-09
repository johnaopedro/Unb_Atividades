#include <stdio.h>
#include <stdlib.h>
//Recursivo:
// typedef struct no{
//    int dado;
//    struct no *esq, *dir;
// } no;
// void pre_ordem(no *raiz){
//     printf("%d", raiz->dado);
//     pre_ordem(raiz->esq);
//     pre_ordem(raiz->dir);
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
void pre_ordem(no *raiz){
    if(raiz == NULL) return;
    pilha *topo = NULL;
    empilha(&topo, raiz);
    while(topo != NULL){
        no *atual = desempilha(&topo);
        printf("%d ", atual->dado);
        if(atual->dir != NULL){
            empilha(&topo, atual->dir);
        }
        if(atual->esq != NULL){
            empilha(&topo, atual->esq);
        }
    }
    printf("\n");
}