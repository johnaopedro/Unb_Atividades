#include <stdio.h>
int main() {
int a, s, m, D;
scanf("%d", &D);
while (scanf("%d %d %d", &a, &s, &m) != EOF) {
    int c[D], matriculados[D], aprovados[D], codigosmaisreprovados[D], cont=0, maxreprovados=-1;
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &c[i],&matriculados[i],&aprovados[i]);
        int reprovados = matriculados[i]-aprovados[i];
        if (reprovados > maxreprovados) {
            maxreprovados = reprovados;
            cont = 0;
            codigosmaisreprovados[cont++] = c[i];
    } else if (reprovados == maxreprovados) {
            codigosmaisreprovados[cont++] = c[i];
            for (int j = cont - 1; j > 0; j--) {
                if (codigosmaisreprovados[j] < codigosmaisreprovados[j - 1]) {
                    int temp = codigosmaisreprovados[j];
                    codigosmaisreprovados[j] = codigosmaisreprovados[j - 1];
                    codigosmaisreprovados[j - 1] = temp;
                } else {
                    break;
                }
            }
        }   
    }
    printf("%d/%d\n", a, s);
    for (int i = 0; i < cont; i++) {
        printf("%d ", codigosmaisreprovados[i]);
    }
    printf("\n\n");
}
return 0;
}