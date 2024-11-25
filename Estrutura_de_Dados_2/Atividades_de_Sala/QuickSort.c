#include <stdio.h>
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
void quickSort(int *v, int e, int d){
if (e <=d){
    int p=particiona(v,e,d);
    quickSort(v, e, p-1);  // Ordena a primeira metade
    quickSort(v, p + 1, d);  // Ordena a segunda metade
}
}//Complexidade: O(n lg n)
int main(){
int vetor[] ={-3, 5, 1, -4, 2, 0};  // Vetor inicial
int tamanho = sizeof(vetor) / sizeof(vetor[0]);
printf("Vetor antes da ordenacao:\n");
for (int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
}
printf("\n");
quickSort(vetor, 0, tamanho-1);  // Chama a função de ordenação
printf("Vetor apos a ordenacao:\n");
for (int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
}
printf("\n");
return 0;
}