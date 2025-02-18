#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#define MAX 255
void rodar(const char *path_binario, const char *argumento){
    if(execl(path_binario, path_binario, argumento,(char *)NULL)){
        printf("> Erro: %s\n", strerror(errno));
        fclose(stdin);
        exit(errno);}}
void calcular_tempo(struct timeval *start, struct timeval *stop, float *tempo_segundos){
    *tempo_segundos =(stop->tv_sec - start->tv_sec) +(stop->tv_usec - start->tv_usec) / 1000000.0;}
void print_tempo_e_codigo(float tempo_segundos, int codigo_de_retorno){
    printf("> Demorou %.1f segundos, retornou %d\n", tempo_segundos, WEXITSTATUS(codigo_de_retorno));}
void print_totaltempo(float tempototal){
    printf(">> O tempo total foi de %.1f segundos\n", tempototal);}
int main(){
    char path_binario[MAX], argumento[MAX];
    float tempo_segundos, tempototal = 0.0;
    struct timeval start, stop;
    int codigo_de_retorno;
    while(scanf("%s %s", path_binario, argumento) != EOF){
        fflush(stdout);
        gettimeofday(&start, NULL);
        if(!fork()){
            rodar(path_binario, argumento);
        } else{
            wait(&codigo_de_retorno);
            gettimeofday(&stop, NULL);
            calcular_tempo(&start, &stop, &tempo_segundos);
            print_tempo_e_codigo(tempo_segundos, codigo_de_retorno);
            tempototal += tempo_segundos;
        }}
    print_totaltempo(tempototal);
    return 0;}