#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int *tb;
    int M;
    int N;
} TH;
int aumentaTamanho(int M);
void THinsere(TH *h, int ch){
    if (h->N > h->M / 2){
        int novo_M = aumentaTamanho(h->M);
        if (novo_M == h->M) return;
        int *tb = malloc(sizeof(int) * novo_M);
        if (!tb) return;
        for (int i = 0; i < novo_M; ++i) tb[i] = -1;
        for (int i = 0; i < h->M; ++i){
            if (h->tb[i] != -1){
                int posicao = h->tb[i] % novo_M;
                while (tb[posicao] != -1) posicao = (posicao + 1) % novo_M;
                tb[posicao] = h->tb[i];}}
        free(h->tb);
        h->tb = tb;
        h->M = novo_M;}
    int posicao = ch % h->M;
    while (h->tb[posicao] != -1 && h->tb[posicao] != ch) posicao = (posicao + 1) % h->M;
    if (h->tb[posicao] == -1){
        h->tb[posicao] = ch;
        ++h->N;}}
int THremove(TH *h, int ch){
    int posicao = ch % h->M;
    while (h->tb[posicao] != -1){
        if (h->tb[posicao] == ch){
            h->tb[posicao] = -1;
            --h->N;
            posicao = (posicao + 1) % h->M;
            while (h->tb[posicao] != -1){
                int dado = h->tb[posicao];
                h->tb[posicao] = -1;
                h->N--;
                THinsere(h, dado);
                posicao = (posicao + 1) % h->M;}
            return 0;}
        posicao = (posicao + 1) % h->M;}
    return -1;}
int THbusca(TH *h, int ch){
    int posicao = ch % h->M;
    while (h->tb[posicao] != -1){
        if (h->tb[posicao] == ch) return 1;
        posicao = (posicao + 1) % h->M;}
    return 0;}