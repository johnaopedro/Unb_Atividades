#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no{
    char p[21]; 
    int ocorre;
    struct no* prox;
} no;
unsigned int hash(const char* p, size size){
    unsigned int hash = 0;
    while (*p) hash = (hash * 31) + *p++;
    return hash % size;}
no* criar_no(const char* p, int ocorre){
    no* novo_no = (no*)malloc(sizeof(no));
    if (!novo_no) exit(EXIT_FAILURE);
    strcpy(novo_no->p, p);
    novo_no->ocorre = ocorre;
    novo_no->prox = NULL;
    return novo_no;}
void manipular_dados(no* tb[], const char* p, int c, size size){
    size posicao = hash(p, size);
    no* r = tb[posicao];
    while (r){
        if (strcmp(r->p, p) == 0){
            if (c == 1) r->ocorre++;
            else if (c == 3) r->ocorre = 0;
            return;}
        r = r->prox;}
    no* novo_no = criar_no(p, c == 1);
    novo_no->prox = tb[posicao];
    tb[posicao] = novo_no;
}
int main(){
    const size M = 65536; int c; char p[21];
    no** tb = (no**)malloc(M * sizeof(no*));
    if(!tb) exit(EXIT_FAILURE);
    for(size i = 0; i < M; ++i) tb[i] = NULL;
    while(scanf("%d %s", &c, p) != EOF){
        if(c == 1 || c == 3) manipular_dados(tb, p, c, M);
        else if(c == 2){
            size posicao = hash(p, M);
            no* r = tb[posicao]; int captura = 0;
            while (r){
                if (strcmp(r->p, p) == 0){
                    printf("%d\n", r->ocorre);
                    captura = 1;
                    break;}
                r = r->prox;}
            if (!captura) printf("0\n");}}
    return 0;}