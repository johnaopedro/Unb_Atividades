#include <stdio.h>

int main(void) {
    int ga, gcb, gcl;

    // Entrada das quantidades dos ingredientes
    scanf("%d %d %d", &ga, &gcb, &gcl);

    // Contadores para bombons
    int crocante = 0, misto = 0, tradicional = 0;

    // Produção de bombons 'crocante'
    while (ga >= 5 && gcb >= 25 && gcl >= 20) {
        ga -= 5;   
        gcb -= 25; 
        gcl -= 20; 
        crocante++;
    }

    // Produção de bombons 'misto'
    while (gcb >= 25 && gcl >= 25) {
        gcb -= 25; 
        gcl -= 25; 
        misto++;
    }

    // Produção de bombons 'tradicional'
    while (gcl >= 50) {
        gcl -= 50; 
        tradicional++;
    }

    // Caixas de bombons
    int especial = 0, predileta = 0, sortida = 0;

    // Caixas sortidas
    while (crocante >= 10 && misto >= 10 && tradicional >= 10) {
        sortida++;
        crocante -= 10;      
        misto -= 10;         
        tradicional -= 10;   
    }

    // Caixas prediletas
    while (crocante >= 10 && misto >= 20) {
        predileta++;
        crocante -= 10; 
        misto -= 20;    
    }

    // Caixas especiais
    while (crocante >= 30) {
        especial++;
        crocante -= 30; 
    }
        printf("%d %d %d\n", especial, predileta, sortida);
    return 0;
}