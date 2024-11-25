#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct celula{
    char dado[100];
    struct celula *prox;
} celula;
void inserir(celula *p, char *str){
celula *auxil = malloc(sizeof(celula));
strcpy(auxil->dado, str);
auxil->prox = p->prox;
p->prox = auxil;
}
void desfazer(celula *p, char *dado){
celula *temp;
if(p->prox == NULL){
    strcpy(dado, "NULL");
    return;
}
temp = p->prox;
p->prox = temp->prox;
strcpy(dado, temp->dado);
}
int main(){
celula *p = malloc(sizeof(celula));
char inicial[10],STR[100];
while((scanf("%s", inicial)) != EOF){
    if(strcmp(inicial, "inserir") == 0){
        scanf(" %[^\n]", STR);
        inserir(p, STR);
    } else if(strcmp(inicial, "desfazer") == 0){
        char resultado[100];
        desfazer(p, resultado);
        printf("%s\n", resultado);

}}
    return 0;
}