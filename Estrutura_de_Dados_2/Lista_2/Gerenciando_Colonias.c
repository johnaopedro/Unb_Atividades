#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no{
    char chave[12];
    struct no *esq, *dir;
} no;
typedef struct formiga{
    long long c;
    no *chaves;
    struct formiga *esq, *dir;
} formiga;
no* criar_no(const char *x){
    no* novo =(no*)malloc(sizeof(no));
    if(novo){
        strncpy(novo->chave, x, 10);
        novo->chave[10] = '\0';
        novo->esq = novo->dir = NULL;}
    return novo;}
void liberar_nos(no *raiz){
    if(raiz){
        liberar_nos(raiz->esq);
        liberar_nos(raiz->dir);
        free(raiz);}}
void liberar_formigas(formiga *raiz){
    if(raiz){
        liberar_formigas(raiz->esq);
        liberar_formigas(raiz->dir);
        liberar_nos(raiz->chaves);
        free(raiz);}}
int hash(long long c, int formigueiros){
    return llabs(c) % formigueiros;}
formiga* criar_formiga(long long c){
    formiga *nova =(formiga *)malloc(sizeof(formiga)); //Mesmo principio de criar o no
    nova->c = c;
    nova->chaves = NULL;
    nova->esq = nova->dir = NULL;
    return nova;}
no* inserir_chave(no *raiz, const char *p){
    if(!raiz) return criar_no(p);
    int compara = strcmp(p, raiz->chave);
    if(compara < 0) raiz->esq = inserir_chave(raiz->esq, p);
    else if(compara > 0) raiz->dir = inserir_chave(raiz->dir, p);
    return raiz;}
int buscar_chave(no *raiz, const char *p){
    if(!raiz) return 0;
    int compara = strcmp(p, raiz->chave);
    if(compara == 0) return 1;
    return buscar_chave(compara < 0 ? raiz->esq : raiz->dir, p);}
formiga* inserir_formiga(formiga *raiz, long long c){
    if(!raiz) return criar_formiga(c);
    if(c < raiz->c) raiz->esq = inserir_formiga(raiz->esq, c);
    else if(c > raiz->c) raiz->dir = inserir_formiga(raiz->dir, c);
    return raiz;}
void manipular_dados(formiga **tb, int tam, long long c, const char *p){
    int posicao = hash(c, tam);
    if(!tb[posicao]) tb[posicao] = criar_formiga(c);
    formiga *atual = tb[posicao];
    while(atual){
        if(atual->c == c) break;
        atual =(c < atual->c) ? atual->esq : atual->dir;}
    if(!atual){
        tb[posicao] = inserir_formiga(tb[posicao], c);
        atual = tb[posicao];
        while(atual){
            if(atual->c == c) break;
            atual =(c < atual->c) ? atual->esq : atual->dir;}}
    if(buscar_chave(atual->chaves, p)) printf("%lld\n", c);
    else atual->chaves = inserir_chave(atual->chaves, p);}
int main(){
    int formigueiros = 1048576; long long c; char p[11];
    formiga **tb =(formiga **)calloc(formigueiros, sizeof(formiga *));
    while(scanf("%lld %10s", &c, p) != EOF) manipular_dados(tb, formigueiros, c, p);
    for(int i = 0; i < formigueiros; i++) if(tb[i]) liberar_formigas(tb[i]);
    return 0;}