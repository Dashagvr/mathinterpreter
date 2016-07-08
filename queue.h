#ifndef QUAD_H
#define QUAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue
{
    char* data;
    struct Queue* next;
}Queue;

void push_Queue(Queue** a, char* val);
char* pop_Queue(Queue** a);

#endif // QUAD_H
