#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} Node, *NodePtr;

typedef struct
{
    NodePtr head, tail;
} QueueType, *Queue;

Queue initQueue()
{
    Queue qp = (Queue) malloc(sizeof(QueueType));
    qp->head = NULL;
    qp->tail = NULL;
    return qp;
}

int emptyQueue(Queue Q)
{
    return (Q->head == NULL);
}

void enqueue(Queue Q, int d)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->data = d;
    np->next = NULL;

    if (emptyQueue(Q))
    {
        Q->head = np;
        Q->tail = np;
    }
    else
    {
        Q->tail->next = np;
        Q->tail = np;
    }
}

int dequeue(Queue Q)
{
    if (emptyQueue(Q))
    {
        printf("\nAttempt to remove from an empty queue.\n");
        exit(1);
    }

    NodePtr temp = Q->head;
    int hold = Q->head->data;
    Q->head = Q->head->next;
    if (Q->head == NULL)
        Q->tail = NULL;
    free(temp);
    return hold;
}

#endif // QUEUE_H_INCLUDED
