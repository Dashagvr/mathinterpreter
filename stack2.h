#ifndef STACK2_H
#define STACK2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK2
{
    int a;
    struct STACK2* next;
}STACK2;

void push2(STACK2** s, int l);
int pop2(STACK2** s);

#endif // STACK2_H
