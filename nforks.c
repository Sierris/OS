#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>

int n=0;

void *func(void *ptr, pthread_mutex_t mutexes);
void salir();

/*void sigfun(int sig)
{
    //printf("You have presses Ctrl-C , please press again to exit");
	(void) signal(SIGINT, SIG_DFL);
    //salir();
}*/


int main(int argc, char* argv[])
{       
    n = atoi(argv[1]);
    int cont[n];
    pthread_t threads[n];
    pthread_mutex_t mutexes[n];
    int *args = 0;
    
    for(int i=0; i<n; i++)
    {
        pthread_create(&threads[i], NULL, *func, ((void *)i,&mutexes));
        pthread_mutex_init(&mutexes[i], NULL);
    }   
}


void *func(void *ptr, pthread_mutex_t mutexes){
    int i = (int)ptr;
    printf("Thread: %d\n",i);
}

/*void salir()
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", cont[i]);
    }

    printf("\n");
    exit(0);
}*/