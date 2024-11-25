#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* sigla(const char* s, const char* t) {
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (toupper(s[i]) == t[0]) {
            for (int j = i + 1; j < n; ++j) {
                if (toupper(s[j]) == t[1]){ //se o maiusculo de s for igual ao t
                    if (t[2] == 'X') {
                        return "Sim";
                    }
                    for (int k = j + 1; k < n; ++k) {
                        if (toupper(s[k]) == t[2]) {
                            return "Sim";
                        }
                    }
                }
            }
        }
    }
    return "Nao";
}
int main() {
    char s[100000], t[4]; //s=10^5 e t=3
    scanf("%s %s", s, t);
    printf("%s\n", sigla(s, t));
    return 0;
}

//ou

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// const char* sigla(const char* s, const char* t) {
//     int n = strlen(s); //conta
//     int j = 0; //controle de indice do vetor com a sigla
//     for (int i = 0; i < n; ++i) {
//         if (toupper(s[i]) == t[j]) {
//             j++; //Apos ter o primeiro valor igual, acrescenta 1 no controle da sigla.
//             if (j == 3 || (j == 2 && t[2] == 'X')) {
//                 return "Sim";
//             }
//         }
//     }
//     return "Nao";
// }
// int main() {
//     char s[100000], t[4]; //s=10^5 e t=3
//     scanf("%s %s", s, t);
//     printf("%s\n", sigla(s, t)); //retorna sim ou nao
//     return 0;
// }