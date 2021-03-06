#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#define MAXSLEEP 5

/**********************************
 * TODO: check the function void* and void
 * 1. Initialize the buffer
 * 2. Create comsumer & producer
 * 3. Sleep
 * 4. Terminate
***********************************/

bufferQueue buffer;

sem_t *full, *empty;
pthread_mutex_t mutex;

void *consume(int*);
void *produce(int*);

int main(int argc, char const *argv[])
{
    // Check the parameters
    if (4 != argc)
    {
        fprintf(stderr, "usage: Pds&Csm.out <int> <int> <int>\n");
        return -1;
    }
    if ((atoi(argv[1]) < 0) || (atoi(argv[2]) < 0) || (atoi(argv[3]) < 0))
    {
        fprintf(stderr, "Input should be positive interger!\n");
        return -1;
    }

    /* set the para */
    int numOfCsm, numOfPds, timeOfSleep;
    timeOfSleep = atoi(argv[1]);
    numOfPds = atoi(argv[2]);
    numOfCsm = atoi(argv[3]);
    srand(time(NULL));

    /* initialize data and semaphore */
    buffer.head = buffer.tail = 0;
    pthread_mutex_init(&mutex, NULL);
    empty = sem_open("empty", O_CREAT|O_RDWR, 0666, BUFFER_SIZE - 1);
    full = sem_open("full", O_CREAT|O_RDWR, 0666, 0);
    if (SEM_FAILED == empty || SEM_FAILED == full)
    {
        perror("semaphore failed");
        return -1;
    }

    /* create the handler of threads */
    pthread_t *consumers, *producers;
    consumers = (pthread_t *) malloc(numOfCsm * sizeof(pthread_t));
    producers= (pthread_t *) malloc(numOfPds * sizeof(pthread_t));

    /* get the default attributes */
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    /* create the thread */
    int i;
    for (i = 0; i < numOfCsm; ++i)
    {
        int num = i;
        pthread_create(&consumers[i], &attr, consume, &num);
    }
    for (i = 0; i < numOfPds; ++i)
    {
        int num = i;
        pthread_create(&producers[i], &attr, produce, &num);
    }

    /* sleep */
    sleep(timeOfSleep);

    /* destroy the semaphore and terminate */
    printf("The process is completed!\n");
    sem_unlink("empty");
    sem_unlink("full");
    pthread_mutex_destroy(&mutex);
    exit(0);
}

void *consume(int *i)
{
    int CsmID = *i;
    while (1)
    {
        sleep(rand() % MAXSLEEP) + 1;

        sem_wait(full);
        pthread_mutex_lock(&mutex);

        int x = remove_item(&buffer);
        if (x < 0)
        {
            fprintf(stderr, "the queue is empty! \n");
            exit(-1);
        }
        else
            printf("Consumer %d get %d from buffer\n", CsmID, x);

        pthread_mutex_unlock(&mutex);
        sem_post(empty);
    }
}

void *produce(int *i)
{
    int pdsID = *i;
    while (1)
    {
        sleep(rand() % MAXSLEEP);
        sem_wait(empty);
        pthread_mutex_lock(&mutex);

        int num = rand(), x = insert_item(&buffer, num);
        if (x < 0)
        {
            fprintf(stderr, "the queue is full! \n");
            exit(-1);
        }
        else
            printf("Producer %d add %d to buffer\n", pdsID, num);

        pthread_mutex_unlock(&mutex);
        sem_post(full);
    }
}