#ifndef PARCER_H
#define PARCER_H

#include "quad.h"
#include "stack.h"

static char *str;

QUAD *parcer(char *sr);
int isDigit(char ch);
void returnChar(char ch);
char getChar();
char *getValue();
int _true(char ch, int i);

#endif // PARCER_H
