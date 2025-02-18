#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int sinais=0;
void sinal(int sinal){sinais=sinal;};
int main(void){
signal(SIGUSR1, sinal);
signal(SIGUSR2, sinal);
pause();
int processo=fork();
if(!processo){
    exit(0);}
pause();
wait(NULL);
pause();
exit(0);}