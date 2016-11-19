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

typedef struct{
    buffer_item data[BUFFER_SIZE];
    int head, tail;
} bufferQueue;
bufferQueue buffer;

sem_t *full, *empty;
pthread_mutex_t mutex;

int insert_item(bufferQueue *queue, buffer_item x)
{
    if ((queue->tail + 1) % BUFFER_SIZE == queue->tail) return -1;
    queue->data[queue->tail] = x;
    queue->tail = (queue->tail + 1) % BUFFER_SIZE;
    return 0;
}
int remove_item(bufferQueue *queue)
{
    if (queue->head == queue->tail) return -1;

    int temp = queue->data[queue->head];
    queue->head = (queue->head + 1) % BUFFER_SIZE;
    return temp;
}

void *consume(int*);
void *produce(int*);

int main(int argc, char const *argv[])
{
    // Check the parameters
//    if (4 != argc)
//    {
//        fprintf(stderr, "usage: Pds&Csm.out <int> <int> <int>\n");
//        return -1;
//    }
//    if ((atoi(argv[1]) < 0) || (atoi(argv[2]) < 0) || (atoi(argv[3]) < 0))
//    {
//        fprintf(stderr, "Input should be positive interger!\n");
//        return -1;
//    }

    /* set the para */
    int numOfCsm = 2, numOfPds = 3, timeOfSleep = 10;
//    timeOfSleep = atoi(argv[1]);
//    numOfPds = atoi(argv[2]);
//    numOfCsm = atoi(argv[3]);
    srand(time(NULL));

    /* initialize data and semaphore */
    buffer.head = buffer.tail = 0;
    pthread_mutex_init(&mutex, NULL);
    empty = sem_open("empty", O_CREAT|O_RDWR, 0666, BUFFER_SIZE);
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
    /* sleep and exit */
    sleep(timeOfSleep);
    printf("The process is completed!\n");
    exit(0);
}

void *consume(int *i)
{
    int CsmID = *i;
    while (1)
    {
        sleep(rand() % MAXSLEEP);

        sem_wait(full);
        pthread_mutex_lock(&mutex);

        int x = remove_item(&buffer);
        if (x < 0)
        {
            perror("queue is empty!");
            exit(-1);
        }
        else{
            printf("Consumer %d get %d from buffer\n", CsmID, x);
        }

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
            perror("queue is full!");
            exit(-1);
        }
        else{
            printf("Producer %d add %d to buffer\n", pdsID, num);
        }

        pthread_mutex_unlock(&mutex);
        sem_post(full);
    }
}