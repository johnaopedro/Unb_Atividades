#include <stdio.h>
double mediav(int vet[], int tamanho){
double media, soma=0;
for(int i=0; i < tamanho; i++){
    soma += vet[i];
}
media=soma /(double)tamanho;
return media;
}
int main(void){
int n;
scanf("%d", &n);
int v[n];
for(int i=0; i < n; i++){
    scanf("%d", &v[i]);
}
double media=mediav(v, n);
int maior[n], cont=0;
for(int i=0; i < n; i++){
    if(v[i] > media){
        maior[cont]=v[i];
        cont++;
    }}
if(cont == 0){
    printf("0");
} else{
    for(int i=0; i < cont; i++){
        if(i == cont - 1){
            printf("%d", maior[i]);
        } else{
            printf("%d ", maior[i]);
}}}
return 0;
}