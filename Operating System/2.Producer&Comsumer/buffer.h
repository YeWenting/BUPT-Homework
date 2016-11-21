typedef int buffer_item;

#define BUFFER_SIZE 10

typedef struct{
    buffer_item data[BUFFER_SIZE];
    int head, tail;
} bufferQueue;

int insert_item(bufferQueue *, buffer_item);
int remove_item(bufferQueue *);

// bufferQueue's function