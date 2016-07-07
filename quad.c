#include "quad.h"

void push_quad(QUAD** a, char* val)
{
    QUAD* next = NULL;
    next = (QUAD*)malloc(sizeof(QUAD));
    if (next != NULL)
    {
        next->data = val;
        next->next = NULL;
        if (*a == NULL)
        {
            *a = next;
        }
        else
        {
            QUAD* b = *a;
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

char* pop_quad(QUAD** a)
{
    if (*a == NULL)
    {
        printf("QUAD is clear\n");
        return NULL;
    }
    QUAD* b = (*a);
    char* val = (*a)->data;
    (*a) = (*a)->next;
    free(b);
    return val;
}
