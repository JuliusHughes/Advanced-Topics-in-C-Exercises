#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>
#include "queue.h"

typedef struct
{
    Queue top, tail;
} StackType, *Stack;

Stack initStack()
{
    Stack sp = (Stack) malloc(sizeof(StackType));
    sp->top = initQueue();
    sp->tail = initQueue();
    return sp;
}

int emptyStack(Stack S)
{
    return (S->top->head == NULL);
}

void push(Stack S, int d)
{
    if (S->top->head == NULL)
        enqueue(S->top, d);
    else
    {
        int num = dequeue(S->top);
        enqueue(S->tail, num);
        enqueue(S->top, d);
    }
}

int pop(Stack S)
{
    if (emptyStack(S))
    {
        printf("\nAttempt to pop an empty stack.\n");
        exit(1);
    }

    int hold = dequeue(S->top);
    NodePtr temp1, temp2, np, old;
    temp1 = NULL; //linked list to hold reverse order of the tail queue
    temp2 = NULL; //linked list to hold the original order of the tail queue

    //add each element in queue to the head of temp1 linked list to get reverse order
    while (!emptyQueue(S->top))
    {
        np = (NodePtr) malloc(sizeof(Node));
        np->data = dequeue(S->tail);
        np->next = temp1;
        temp1 = np;
    }

    enqueue(S->top, temp1->data);

    //remove top of temp1 linked list since that data is on top of the stack
    old = temp1;
    temp1 = temp1->next;
    free(old);

    //add each element in temp1 linked list to the head of temp2 linked list to restore the tail queue's original order
    while (temp1 != NULL)
    {
        np = (NodePtr) malloc(sizeof(Node));
        np->data = temp1->data;
        np->next = temp2;
        temp2 = np;
        old = temp1;
        temp1 = temp1->next;
        free(old);
    }

    //add each element in temp2 to tail queue
    while (temp2 != NULL)
    {
        enqueue(S->tail, temp2->data);
        old = temp2;
        temp2 = temp2->next;
        free(old);
    }

    return hold;
}

#endif // STACK_H_INCLUDED
