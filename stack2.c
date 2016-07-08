#include "stack2.h"

void push2(STACK2** s, int l)
{
    STACK2* next = NULL;
    next = (STACK2*)malloc(sizeof(STACK2));
    if (next != NULL)
    {
        next->a = l;
        next->next = *s;
        *s = next;
    }
    else
    {
        printf("memory is not access\n");
    }
}

int pop2(STACK2** s)
{
    if (*s == NULL)
    {
        printf("STACK1 is clear\n");
        return NULL;
    }
    STACK2* b = (*s);
    int val = (*s)->a;
    (*s) = (*s)->next;
    free(b);
    return val;
}
