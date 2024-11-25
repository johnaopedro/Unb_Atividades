#include <stdio.h>
int busca(int *v, int n, int x){//vetor, tamanho, numero que quero achar
    for(int i=0;i<n;i++)
        if(v[i]==x) return 1;
    return 0; 
}//Complexidade O(n)

int main() {
    int numeros_sorteados[] = {7, 13, 22, 34, 45, 50};
    int tamanho = sizeof(numeros_sorteados) / sizeof(numeros_sorteados[0]); //É necessario a divisão para ter o tamanho.
    int numero = 22; // Número que queremos verificar

    if (busca(numeros_sorteados, tamanho, numero)) {
        printf("O número %d foi sorteado!\n", numero);
    } else {
        printf("O número %d não foi sorteado.\n", numero);
    }

    return 0;
}