#include <stdio.h>
void roman(int num, char *numero_romano) {
    int normais[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    int indice = 0;
    while (num > 0) {
        while (num >= normais[i]) {
            for (int j = 0; romanos[i][j] != '\0'; j++) {
                numero_romano[indice++] = romanos[i][j];
            }
            num -= normais[i];
        }
        i++;
    }
    numero_romano[indice] = '\0';
}
int main() {
    int numero;
    scanf("%d", &numero);
    int n[numero], i;
    for(i=0;i<numero;i++){
    scanf("%d", &n[i]);

    char numero_romano[20] = "";
    roman(n[i], numero_romano);
//IMPRIMIR
    printf("%s\n", numero_romano);
    }
    return 0;
}