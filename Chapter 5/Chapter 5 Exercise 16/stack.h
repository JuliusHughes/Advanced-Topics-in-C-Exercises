#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} Node, *NodePtr;

typedef struct
{
    NodePtr top;
} stackType, *Stack;

Stack initStack()
{
    Stack sp = (Stack) malloc(sizeof(stackType));
    sp->top = NULL;
    return sp;
}

int emptyStack(Stack S)
{
    return (S->top == NULL);
}

void push(Stack S, int d)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->data = d;
    np->next = S->top;
    S->top = np;
}

int pop(Stack S)
{
    if (emptyStack(S))
    {
        printf("\nAttempt to pop an empty stack.\n");
        exit(1);
    }

    NodePtr temp = S->top;
    int hold = S->top->data;
    S->top = S->top->next;
    free(temp);
    return hold;
}

#endif // STACK_H_INCLUDED
