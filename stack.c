#include "stack.h"

void push1(STACK1** s, char* str, int l)
{
    STACK1* next = NULL;
    next = (STACK1*)malloc(sizeof(STACK1));
    if (next != NULL)
    {
        next->a = l;
        next->data = (char*)malloc(strlen(str));
        strcpy(next->data, str);
        next->next = *s;
        *s = next;
    }
    else
    {
        printf("memory is not access\n");
    }
}

char* pop1(STACK1** s)
{
    if (*s == NULL)
    {
        printf("STACK1 is clear\n");
        return NULL;
    }
    STACK1* b = (*s);
    char* str = (char*)malloc(strlen((*s)->data));
    strcpy(str, (*s)->data);
    (*s) = (*s)->next;
    free(b);
    return str;
}
