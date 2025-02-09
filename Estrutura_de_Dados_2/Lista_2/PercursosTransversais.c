#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no{
    char chave;
    struct no *esq, *dir;
} no;
no* arvore(char* S1, char* S2, int inicio, int fim, int* pID);
no* criar_no(char chave){
    no* novo_no =(no*)malloc(sizeof(no));
    if(novo_no){
        novo_no->chave = chave;
        novo_no->esq = NULL;
        novo_no->dir = NULL;}
    return novo_no;}
void subarvores(no* raiz, char* S1, char* S2, int inicio, int fim, int* pID){
    int inID;
    for(inID = inicio; inID <= fim; inID++){
        if(S2[inID] == raiz->chave) break;}
    raiz->esq = arvore(S1, S2, inicio, inID - 1, pID);
    raiz->dir = arvore(S1, S2, inID + 1, fim, pID);}
no* arvore(char* S1, char* S2, int inicio, int fim, int* pID){
    if(inicio > fim) return NULL;
    char chave_atual = S1[*pID]; (*pID)++;
    no* raiz = criar_no(chave_atual);
    if(inicio == fim) return raiz;
    subarvores(raiz, S1, S2, inicio, fim, pID);
    return raiz;}
void percurso(no* raiz){
    if(raiz != NULL){
        percurso(raiz->esq);
        percurso(raiz->dir);
        printf("%c", raiz->chave);
    } else return;}
int main(){
    int C, N;
    char S1[52], S2[52];
    scanf("%d", &C);
    while(C > 0){
        scanf("%d %s %s", &N, S1, S2);
        int pID = 0;
        no* raiz = arvore(S1, S2, 0, N - 1, &pID);
        percurso(raiz);
        printf("\n");
        C--;}
    return 0;}