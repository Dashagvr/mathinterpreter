#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK1
{
    int a;
    char* data;
    struct STACK1* next;
}STACK1;

void push1(STACK1** s, char* str, int l);
char* pop1(STACK1** s);

#endif // STACK_H
