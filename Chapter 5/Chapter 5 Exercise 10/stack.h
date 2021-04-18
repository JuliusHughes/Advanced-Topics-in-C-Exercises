#include <stdlib.h>


typedef struct node
{
    double num;
    struct node * next;
} *NodePtr, Node;

typedef struct stackType
{
    NodePtr top;
} *Stack, StackType;

Stack initStack()
{
    Stack sp = (Stack) malloc(sizeof(StackType));
    sp -> top = NULL;
    return sp;
}

void push(Stack S, double n)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->num = n;
    np->next = S->top;
    S->top = np;
}

int empty(Stack S)
{
    return (S->top == NULL);
}

double pop(Stack S)
{
    if (empty(S))
    {
        printf("Attempt to pop an empty stack.\n");
        exit(1);
    }

    double hold = S->top->num;
    NodePtr temp = S->top;
    S->top = S->top->next;
    free(temp);
    return hold;
}


