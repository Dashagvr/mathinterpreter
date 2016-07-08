#include "queue.h"

void push_Queue(Queue** a, char* val)
{
    Queue* next = NULL;
    next = (Queue*)malloc(sizeof(Queue));
    if (next != NULL)
    {
        next->data = (char*)malloc(strlen(val)+1);
        strcpy(next->data, val);
        next->next = NULL;
        if (*a == NULL)
        {
            *a = next;
        }
        else
        {
            Queue* b = *a;
            while (b->next != NULL)
            {
                b = b->next;
            }
            b->next = next;
        }

    }
    else
    {
        printf("memory is not access\n");
    }
}

char* pop_Queue(Queue** a)
{
    if (*a == NULL)
    {
        printf("Queue is clear\n");
        return NULL;
    }
    Queue* b = (*a);
    char* val = (char*)malloc(strlen((*a)->data)+1);
    strcpy(val, (*a)->data);
    (*a) = (*a)->next;
    free(b);
    return val;
}
