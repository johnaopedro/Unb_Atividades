#include <stdio.h>
int main(void){
    int total, diaria;
    int D, A, N;
    scanf ("%d", &D);
    scanf ("%d", &A);
    scanf ("%d", &N);
    int chegar = N;
    diaria = D + (chegar-1)*A;
    total=(31 - N + 1)*diaria;
    printf("%d\n",total);
    return 0;
}