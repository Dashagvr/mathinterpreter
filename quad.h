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

void push_quad(QUAD** a, char* val);
char* pop_quad(QUAD** a);

#endif // QUAD_H
