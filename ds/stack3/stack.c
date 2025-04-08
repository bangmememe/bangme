#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(struct stack *ps)
{
    ps->tos = 0;
}

void push(struct stack *ps, int data)
{
    // s.array[s.tos] = data;
    // ++s.tos;
    // (*ps).array[(*ps).tos] = data;
    // ++(*ps).tos;

    if (ps->tos == STACKSIZE)
    {
        printf("stack is full.\n");
        exit(1);
    }
    ps->array[ps->tos] = data;
    ++ps->tos;
}

int pop(struct stack *ps)
{
    // ++s.tos;
    // return s.array[s.tos];
    // --(*ps).tos;
    // return (*ps).array[(*ps).tos];

    if (ps->tos == 0)
    {
        printf("stack is empty.\n");
        exit(2);
    }
    --ps->tos;
    return ps->array[ps->tos];
}
