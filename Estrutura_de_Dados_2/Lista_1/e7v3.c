#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct celula{
    char dado[100];
    struct celula *prox;
} celula;
void inserir(celula *p, char *str){
celula *nova = malloc(sizeof(celula));
strcpy(nova->dado, str);
nova->prox = p->prox;
p->prox = nova;
}
char *desfazer(celula *p){
celula *temp;
if(p->prox==NULL){
    return "NULL";
}
temp = p->prox;
p->prox=temp->prox;
return temp->dado;
}
int main(){
celula *p = malloc(sizeof(celula));
p->prox = NULL;
char STR[100];
while(scanf(" %[^\n]", STR) != EOF){
    if(strncmp(STR, "inserir ", 8) == 0){
        char conteudo[92];
        strcpy(conteudo, STR + 8);
        inserir(p, conteudo);
    } else if(strcmp(STR, "desfazer") == 0){
        printf("%s\n", desfazer(p));
}}
    return 0;
}