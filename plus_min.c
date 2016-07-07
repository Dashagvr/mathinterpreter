#include "plus_min.h"

Result Plus_Minus(Result r)
{
    char sign = getChar(&r);
    int right = getValue(&r);
    if (sign != '+' && sign != '-')
    {
        printf("Ошибка\n");
        exit(-1);
    }
    if (sign == '+')
        r.res = r.res + right;
    else
        r.res = r.res - right;
    return r;
}
