#include <stdlib.h>
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct node
{
    double num;
    struct node * next;
} Node, *NodePtr;

typedef struct queueType
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

int empty(Queue Q)
{
    return (Q->head == NULL);
}

void enqueue(Queue Q, double n)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    if (empty(Q))
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

double dequeue(Queue Q)
{
    if (empty(Q))
    {
        printf("Attempt to remove from an empty queue.\n");
        exit(1);
    }

    double hold = Q->head->num;
    NodePtr temp = Q->head;
    Q->head = Q->head->next;
    if (Q->head == NULL)
        Q->tail = NULL;
    free(temp);
    return hold;
}

#endif // QUEUE_H_INCLUDED
