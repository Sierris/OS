#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define NUM_THREADS 4

pthread_mutex_t tenedor1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tenedor2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tenedor3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tenedor4 = PTHREAD_MUTEX_INITIALIZER;

void *func(void *ptr);
void salir();
void sigfun(int sig)
{
    //printf("You have presses Ctrl-C , please press again to exit");
	(void) signal(SIGINT, SIG_DFL);
    salir();
}

int cont[NUM_THREADS];

int main()
{
    pthread_t thread[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&thread[i], NULL, *func, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(thread[i], NULL);
    }
    salir();
    return 0;
}


void *func(void *ptr){
    int i = (int)ptr;
    int counter = 0;
    (void) signal(SIGINT, sigfun);
    while (1){
            counter++;

            switch (i){
            case 0:
                pthread_mutex_lock(&tenedor1);
                pthread_mutex_lock(&tenedor2);
                cont[i]++;
                pthread_mutex_unlock(&tenedor1);
                pthread_mutex_unlock(&tenedor2);
                break;
            case 1:
                pthread_mutex_lock(&tenedor2);
                pthread_mutex_lock(&tenedor3);
                cont[i]++;
                pthread_mutex_unlock(&tenedor2);
                pthread_mutex_unlock(&tenedor3);
                break;
            case 2:
                pthread_mutex_lock(&tenedor3);
                pthread_mutex_lock(&tenedor4);
                cont[i]++;
                pthread_mutex_unlock(&tenedor3);
                pthread_mutex_unlock(&tenedor4);
                break;
            case 3:
                pthread_mutex_lock(&tenedor4);
                pthread_mutex_lock(&tenedor1);
                cont[i]++;
                pthread_mutex_unlock(&tenedor4);
                pthread_mutex_unlock(&tenedor1);
                break;
            }
    }
}

void salir()
{
    for (int i = 0; i < NUM_THREADS; i++)
    {
        printf(" %d", cont[i]);
    }

    printf("\n");
    exit(0);
}