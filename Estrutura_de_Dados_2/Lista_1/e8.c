#include <stdio.h>

int main(){
double notas[7], media, D; int i;
scanf("%lf", &D);
for(i=0; i < 7; i++){
    scanf("%lf", &notas[i]);
}
double menor_nota=notas[0], maior_nota=notas[0];
for(i=1; i < 7; i++){
    if(notas[i] < menor_nota){
        menor_nota=notas[i];
}
    if(notas[i] > maior_nota){
        maior_nota=notas[i];
}}double soma=0.0; int contador=0, removermenor=0, removermaior=0;
for(i=0; i < 7; i++){
    if(notas[i]==menor_nota && removermenor==0){
        removermenor=1;
    } else if(notas[i]==maior_nota && removermaior==0){
        removermaior=1;
    } else{
        soma += notas[i];
        contador++;
}}
    media=soma / contador;
    double final=media*D;
    printf("%.1f\n", final);
    return 0;
}