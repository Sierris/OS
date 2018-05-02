#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 4

pthread_mutex_t tenedor1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tenedor2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tenedor3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tenedor4 = PTHREAD_MUTEX_INITIALIZER;

void *func(void *ptr);
void salir();

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

void *func(void *ptr)
{
    int i = (int)ptr;
    int counter = 0;
    while (counter<100)
    {
        counter++;

        /*if ('c' == getchar())
        {
            salir();
        }*/

        switch (i)
        {
        case 0:
            pthread_mutex_lock(&tenedor1);
            pthread_mutex_lock(&tenedor2);
            printf("Soy el hilo 1\n");
            cont[i]++;
            pthread_mutex_unlock(&tenedor1);
            pthread_mutex_unlock(&tenedor2);
            break;
        case 1:
            pthread_mutex_lock(&tenedor2);
            pthread_mutex_lock(&tenedor3);
            printf("Soy el hilo 2\n");
            cont[i]++;
            pthread_mutex_unlock(&tenedor2);
            pthread_mutex_unlock(&tenedor3);
            break;
        case 2:
            pthread_mutex_lock(&tenedor3);
            pthread_mutex_lock(&tenedor4);
            printf("Soy el hilo 3\n");
            cont[i]++;
            pthread_mutex_unlock(&tenedor3);
            pthread_mutex_unlock(&tenedor4);
            break;
        case 3:
            pthread_mutex_lock(&tenedor4);
            pthread_mutex_lock(&tenedor1);
            printf("Soy el hilo 4\n");
            cont[i]++;
            pthread_mutex_unlock(&tenedor4);
            pthread_mutex_unlock(&tenedor1);
            break;
        }
        //sleep(2);
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