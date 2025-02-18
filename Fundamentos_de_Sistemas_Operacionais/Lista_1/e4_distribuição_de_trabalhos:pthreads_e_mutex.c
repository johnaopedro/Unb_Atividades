#include <pthread.h>
#include <stdio.h>
int count;
int work(int id);
pthread_mutex_t mut;
struct thread_arg{
    int vezes;
};
typedef struct thread_arg thread_arg;
void *thread_func(void *arg){
    thread_arg *x = arg;
    int i=0;
    while(i < x->vezes){
        pthread_mutex_lock(&mut);
        int id = ++count;
        pthread_mutex_unlock(&mut);
        work(id);
        i++;
    }   pthread_exit(NULL);}