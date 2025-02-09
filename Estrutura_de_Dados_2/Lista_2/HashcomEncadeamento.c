#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef struct celula{
    int dado;
    struct celula *prox;
} celula;
typedef struct{
    celula *tb; // tabela hash
    int M;      // tamanho da tabela hash
    int N;      // total de chaves presentes na tabela
} TH;
inline int hash(TH *hasht, int posicao){
    return posicao % hasht->M;
}
void THinsere(TH *h, int ch){
    const int posicao = hash(h, ch);
    celula *r = h->tb[posicao].prox;
    while (r && r->dado != ch)
        r = r->prox;
    if (r) return;
    celula *nova = malloc(sizeof(celula));
    if (!nova) return;
    nova->dado = ch;
    nova->prox = h->tb[posicao].prox;
    h->tb[posicao].prox = nova;
    ++h->N;
}
int THremove(TH *h, int ch){
    const int posicao = hash(h, ch);
    celula *r = &h->tb[posicao];
    while (r->prox && r->prox->dado != ch){
        r = r->prox;
    }
    if (!r->prox) return -1;
    celula *temp = r->prox;
    if (r->prox->prox) r->prox = r->prox->prox;
    else r->prox = NULL;
    free(temp);
    --h->N;
    return 0;
}
int THbusca(TH *h, int ch){
    const int posicao = hash(h, ch);
    celula *r = h->tb[posicao].prox;
    while (r && r->dado != ch)
        r = r->prox;
    return r ? 1 : 0;
}