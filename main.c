#include <stdio.h>
#include "parcer.h"
#include "result.h"
int main(void)
{
    Queue *q;
    q = parcer("95-1+5^(2*2)+10^2+3");
    int r = result(q);
    printf("%i", r);
    printf("Все");
    return 0;
}
