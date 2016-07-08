#include "result.h"
int result(Queue* input)
{
    STACK2 *stack = NULL;

    int firstN, secondN, res = 0;

   while(1)
    {
        char com = input->data[0];

        if((input->data[0]>='0')&&(input->data[0]<='9'))
        {
            push2(&stack, atoi(input->data));
        }
        else if(((input->data[1]>='0')&&(input->data[1]<='9'))&&(input->data[0]=='-'))
        {
            push2(&stack, atoi(input->data));
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
