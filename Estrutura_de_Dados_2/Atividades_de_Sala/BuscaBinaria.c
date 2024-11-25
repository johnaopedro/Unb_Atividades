#include <stdio.h>

int busca_binaria(int *v, int n, int x){//vetor, tamanho, numero que quero achar
int esquerda = 0, direita = n - 1;
while (esquerda <= direita){
    int meio = esquerda + (direita - esquerda) / 2;
    if (v[meio] == x){
        return 1;//Elemento encontrado
    }
    if (v[meio] < x){
        esquerda = meio + 1;//Ajusta o intervalo para a direita
    } else{
        direita = meio - 1;//Ajusta o intervalo para a esquerda
    }
}
return 0;//Elemento não encontrado
}//Complexidade O(lg n)

int main(){
int numeros_ordenados[] ={7, 13, 22, 34, 45, 50};
int tamanho = sizeof(numeros_ordenados) / sizeof(numeros_ordenados[0]);
int numero = 22;//Número que queremos verificar
if (busca_binaria(numeros_ordenados, tamanho, numero)){
    printf("O número %d foi encontrado!\n", numero);
} else{
    printf("O número %d não foi encontrado.\n", numero);
}
return 0;
}
