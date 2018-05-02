#include <pthread.h>
#include <stdio.h>

#define NTRHEADS 8
void *prime(void *ptr);

int n=0;

int main(int argc, char* argv[])
{
	n = atoi(argv[1]);
	pthread_t thread[NTRHEADS];

    for (int i = 0; i < NTRHEADS; ++i)
    {
        pthread_create(&thread[i], NULL, *prime, (void *) i);
    }
	
    for (int i = 0; i < NTRHEADS; ++i)
    {
        pthread_join(thread[i],NULL);
    }
    printf("\n");  

    return 0;
}

void *prime(void *ptr)
{
    int thread_num = (int)ptr;
    int prime;
    int end = (thread_num+1)*n/NTRHEADS;
    int start = thread_num*(n/NTRHEADS)+1;
    
    //printf("Thread: %d start: %d end: %d\n",thread_num,start,end);
    //printf("\nThread num: %d\n", thread_num);

    for (int i = start; i < end; i++)
    {
        prime = 1;
        for (int j = 2; j*j <= i; j++)
        {
            if(i%j == 0)
            {
                prime = 0;
                break;
            }   
        }
        if(prime)
        {
            printf("Hilo(%d) %d\n",thread_num, i);
        }
    }
}