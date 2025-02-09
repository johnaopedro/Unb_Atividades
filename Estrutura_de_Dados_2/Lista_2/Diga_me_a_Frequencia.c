#include <stdio.h>
#include <string.h>
typedef struct caracter{
    int ASCII;
    int qtd_frequencia;
} caracter;
int main(){
    char entrada[1001];
    while(fgets(entrada, 1001, stdin) != NULL){
        int frequenciasAscii[128] ={0};
        for(int i = 0; entrada[i] != '\0' && entrada[i] != '\n'; i++) frequenciasAscii[(int)entrada[i]]++;
        struct caracter caracteres[128]; int num_carac = 0;
        for(int i = 0; i < 128; i++){
            if(frequenciasAscii[i] > 0){
                caracteres[num_carac].ASCII = i;
                caracteres[num_carac].qtd_frequencia = frequenciasAscii[i];
                num_carac++;}}
        for(int i = 0; i < num_carac - 1; i++){
            for(int j = i + 1; j < num_carac; j++){
                if(caracteres[j].qtd_frequencia < caracteres[i].qtd_frequencia || (caracteres[j].qtd_frequencia == caracteres[i].qtd_frequencia && caracteres[j].ASCII < caracteres[i].ASCII)){
                    struct caracter aux = caracteres[i];
                    caracteres[i] = caracteres[j];
                    caracteres[j] = aux;}}}
        for(int i = 0; i < num_carac; i++) printf("%d %d\n", caracteres[i].ASCII, caracteres[i].qtd_frequencia);
        printf("\n");}
    return 0;}