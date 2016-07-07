#ifndef QUAD_H
#define QUAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QUAD
{
    char* data;
    struct QUAD* next;
}QUAD;

void equeue(QUAD** a, char* val);
char* dequeue(QUAD** a);

#endif // QUAD_H
