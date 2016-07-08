#include "parcer.h"

Queue *parcer(char *sr)
{
    str = (char*)malloc(strlen(sr) + 1);
    strcpy(str, sr);
    char ch, ch_p = '(';
    Queue *q = NULL;
    STACK1 *s = NULL;
    ch = getChar();
    while (ch != '\0')
    {
        if (ch == '-' && !isDigit(ch_p))
        {
            returnChar(ch);
            char *st = getValue();
            push_Queue(&q, st);
        }
        else if (isDigit(ch))
        {
            returnChar(ch);
            char *st = getValue();
            push_Queue(&q, st);
        }
        else if (ch == '(')
        {
            char *t = (char*)malloc(2);
            t[0] = ch;
            t[1] = '\0';
            push1(&s, t, _true(ch, 0));
        }
        else if (ch == ')')
        {
            char temp;
            temp = *(pop1(&s));
            while (temp != '(')
            {
                char *t = (char*)malloc(2);
                t[0] = temp;
                t[1] = '\0';
                push_Queue(&q, t);
                temp = *(pop1(&s));
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while ((s != NULL) && (_true(ch, s->a) <= 0))
            {
                push_Queue(&q, pop1(&s));
            }
            char *t = (char*)malloc(2);
            t[0] = ch;
            t[1] = '\0';
            push1(&s, t, _true(ch, 0));
        }
        else if (ch == '^')
        {
            while ((s != NULL) && (_true(ch, s->a) < 0))
            {
                push_Queue(&q, pop1(&s));
            }
            char *t = (char*)malloc(2);
            t[0] = ch;
            t[1] = '\0';
            push1(&s, t, _true(ch, 0));
        }
        ch_p = (ch == ')') ? '0' : ch;
        ch = getChar();
    }
    while (s != NULL)
        push_Queue(&q, pop1(&s));
    return q;
}

int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

void returnChar(char ch)
{
    char *s_t = (char*)malloc(strlen(str) + 2);
    strcpy(s_t + 1, str);
    s_t[0] = ch;
    free(str);
    str = s_t;
}

char getChar()
{
    char* s_t = (char*)malloc(strlen(str));
    char t = str[0];
    strcpy(s_t, str + 1);
    free(str);
    str = s_t;
    return t;
}

char *getValue()
{
    int i = 0;
    while (str[i] != '\0' && (isDigit(str[i]) || str[0] == '-'))
        i++;
    char *s_t = (char*)malloc(i+1);
    strncpy(s_t, str, i);
    s_t[i] = '\0';
    char *temp = (char*)malloc(strlen(str)-i+1);
    strcpy(temp, str + i);
    free(str);
    str = temp;
    return s_t;
}

int _true(char ch, int i)
{
    switch (ch)
    {
    case '(':
    case ')':
        if (i == 1)
            return 0;
        if (i > 1)
            return -1;
        return 1;

    case '+':
    case '-':
        if (i == 2)
            return 0;
        if (i > 2)
            return -1;
        return 2;

    case '*':
    case '/':
        if (i == 3)
            return 0;
        if (i > 3)
            return -1;
        return 3;

    case '^':
        if (i == 4)
            return 0;
        if (i > 4)
            return -1;
        return 4;
    }
    return 10;
}
