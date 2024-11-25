#include <stdio.h>
#include <stdlib.h>
void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int particiona(int *v, int e, int d){
    int i, pivo=v[e], pos=d+1;
    for(i=d;i>=e;i--)
    if(v[i]>=pivo) troca(&v[i], &v[--pos]);
    return pos;
}
int quickSelect(int *v, int e, int d, int k){
    if(e<=d){
        int p=particiona(v,e,d);
        if(p==k) return v[p];
        else{
            if(k<p) quickSelect(v,e,p-1,k);
            else quickSelect(v,p+1,d,k);
        }
    }return -1;
} //Complexidade: O(lg n)
int main() {
    int vetor[] = {3, 2, 1, 5, 4, 6};  // Vetor de exemplo
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int k = 2;  // Queremos encontrar o 2º menor elemento (índice 1)

    int resultado = quickSelect(vetor, 0, tamanho - 1, k);
    printf("O %d-esimo menor elemento e: %d\n", k + 1, resultado);

    return 0;
}
