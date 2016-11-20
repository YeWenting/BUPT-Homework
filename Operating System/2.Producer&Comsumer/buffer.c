//
// Created by YeWenting. on 20/11/2016.
//

#include "buffer.h"

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