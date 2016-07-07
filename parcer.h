#ifndef PARCER_H
#define PARCER_H

#include "quad.h"
#include "stack.h"

QUAD *parcer(char *str);
int isDigit(char ch);
void returnChar(char **str, char ch);
char getChar(char **str);
char *getValue(char **str);
int _true(char ch, int i);

#endif // PARCER_H
