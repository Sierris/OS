#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define READING_THREADS 4

pthread_t producer;
pthread_t consumers[READING_THREADS];
pthread_mutex_t mutex_producer;
pthread_mutex_t mutexes[READING_THREADS];
int cont =0;

void sigfun(int sig)
{
    printf("You have presses Ctrl-C , please press again to exit");
	(void) signal(SIGINT, SIG_DFL);
    printf("La variable quedó en: %d", cont);
    exit(1);
}

void* producer_fct()
{
    (void) signal(SIGINT, sigfun);
    while(1){
        pthread_mutex_lock(&mutex_producer);
        cont++;
        pthread_mutex_unlock(&mutex_producer); 
    }
   
}

void* consumer_fct(void* ptr)
{
    int i = (int)ptr;

    (void) signal(SIGINT, sigfun);
    while(1){
        pthread_mutex_lock(&mutexes[i]);
        printf("El hilo (%d) accede a la variable: %d\n", i, cont);
        pthread_mutex_unlock(&mutexes[i]);
    }
    
}

int main(int argc, char *argv[]){

    pthread_create(&producer, NULL, producer_fct, NULL); /*Create producer*/
    pthread_mutex_init(&mutex_producer, NULL);

    for(int i=0; i<READING_THREADS; i++) /*Create consumer threads*/
    {
        pthread_create(&consumers[i], NULL, consumer_fct, (void*)i);
        pthread_mutex_init(&mutexes[i], NULL);
    }

    pthread_join(producer, NULL);

    for(int i=0; i<READING_THREADS; i++)
    {
        pthread_join(consumers[i], NULL);
    }

   return 0;

}