#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdlib.h>
#include "stack.h"

typedef struct
{
    Stack head, tail;
} QueueType, *Queue;

Queue initQueue()
{
    Queue qp = (Queue) malloc(sizeof(QueueType));
    qp->head = initStack();
    qp->tail = initStack();
    return qp;
}

int emptyQueue(Queue Q)
{
    return (Q->head->top == NULL);
}

void enqueue(Queue Q, int d)
{
    if (emptyQueue(Q))
        push(Q->head, d);
    else
        push(Q->tail, d);
}

int dequeue(Queue Q)
{
    if (emptyQueue(Q))
    {
        printf("\nAttempt to remove from an empty queue.\n");
        exit(1);
    }

    int hold = pop(Q->head);
    if (Q->head->top == NULL)
    {
        while (!emptyStack(Q->tail))
        {
            int num = pop(Q->tail);
            push(Q->head, num);
        }
    }

    return hold;
}



#endif // QUEUE_H_INCLUDED
