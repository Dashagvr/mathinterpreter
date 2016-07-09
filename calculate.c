#include "calculate.h"

double calculate(Queue* input)
{
    STACK2 *stack = NULL;

    double firstN, secondN, res = 0;

   while(1)
    {
        char com = input->data[0];

        if((input->data[0]>='0')&&(input->data[0]<='9'))
        {
            push2(&stack, atof(input->data));
        }
        else if(((input->data[1]>='0')&&(input->data[1]<='9'))&&(input->data[0]=='-'))
        {
            push2(&stack, atof(input->data));
        }
        else if(input->data[0]=='+')
        {
            firstN = pop2(&stack);
            secondN = pop2(&stack);
            res = firstN+secondN;
            push2(&stack, res);
        }
        else if(input->data[0]=='-')
        {
            firstN = pop2(&stack);
            secondN = pop2(&stack);
            res = secondN-firstN;
            push2(&stack, res);
        }
        else if(input->data[0]=='*')
        {
            firstN = pop2(&stack);
            secondN = pop2(&stack);
            res = firstN*secondN;
            push2(&stack, res);
        }
        else if(input->data[0]=='/')
        {
            firstN = pop2(&stack);
            secondN = pop2(&stack);
            if(secondN == 0)
            {
                printf("Error: Division by zero.");
                break;
            }
            res = secondN/firstN;
            push2(&stack, res);
        }
        else if(input->data[0]=='^')
        {
            firstN = pop2(&stack);
            secondN = pop2(&stack);
            int i;
            res = secondN;
            for(i = 0;i<firstN-1;i++)
            {
                res*=secondN;
            }
            push2(&stack, res);
        }
        else if((input->data[0] == 'c')&&(input->data[1] == 'o')&&(input->data[2] == 's'))
        {
            firstN = pop2(&stack);
            res = cos(firstN);
            push2(&stack, res);
        }
        else if((input->data[0] == 's')&&(input->data[1] == 'i')&&(input->data[2] == 'n'))
        {
            firstN = pop2(&stack);
            res = sin(firstN);
            push2(&stack, res);
        }
        else if((input->data[0] == 't')&&(input->data[1] == 'a')&&(input->data[2] == 'n'))
        {
            firstN = pop2(&stack);
            res = tan(firstN);
            push2(&stack, res);
        }
        else if((input->data[0] == 'a')&&(input->data[1] == 'b')&&(input->data[2] == 's'))
        {
            firstN = pop2(&stack);
            res = fabs(firstN);
            push2(&stack, res);
        }
        else if((input->data[0] == 'e')&&(input->data[1] == 'x')&&(input->data[2] == 'p'))
        {
            firstN = pop2(&stack);
            res = exp(firstN);
            push2(&stack, res);
        }

        if(input->next == NULL)
        {
            return res;
            break;
        }
        else
        {
        input = input->next;
        }
    }

}
