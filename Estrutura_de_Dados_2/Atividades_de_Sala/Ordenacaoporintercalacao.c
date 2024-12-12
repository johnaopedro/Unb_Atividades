#include <stdio.h>
#include <stdlib.h>
void intercala(int *v, int e, int m, int d){
int *aux=malloc((d-e+1)*sizeof(int));
int i=e,j=m+1,k=0;

while(i<=m && j<=d)
if(v[i]<=v[j]) aux[k++]=v[i++]; //Para ordenar de forma decrescente basta mudar o sinal para v[i]>=v[j]
else aux[k++]= v[j++];

while(i<=m) aux[k++]=v[i++];
while(j<=d) aux[k++]=v[j++];

k=0;i=e;
while(i<=d) v[i++]=aux[k++];
free(aux);
}//Complexidade: O(n)
void mergeSort(int *v, int e, int d){
if (e < d){
    int m =(e+d)/2;
    mergeSort(v, e, m);  // Ordena a primeira metade
    printf("mergesort(v, %d, %d)\n",e,m);
    mergeSort(v, m + 1, d);  // Ordena a segunda metade
    printf("mergesort(v, %d, %d)\n",m+1,d);
    intercala(v, e, m, d);  // Intercala as duas metades
    printf("intercala(v, %d, %d, %d)\n",e,m,d);
}
}//Complexidade: O(n lg n)

int main(){
int vetor[] ={-7,-3,10,-5,1,0,15,12,8,6};  // Vetor inicial
int tamanho = sizeof(vetor) / sizeof(vetor[0]);
printf("Vetor antes da ordenacao:\n");
for (int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
}
printf("\n");
mergeSort(vetor, 0, tamanho - 1);  // Chama a função de ordenação
printf("Vetor apos a ordenacao:\n");
for (int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
}
printf("\n");
return 0;
}