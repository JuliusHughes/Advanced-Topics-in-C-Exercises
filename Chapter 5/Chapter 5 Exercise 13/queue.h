#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct node
{
    int job_num;
    int priority;
    struct node * next;
} Node, *NodePtr;

typedef struct
{
    NodePtr head;
} QueueType, *Queue;

Queue initQueue()
{
    Queue qp = (Queue) malloc(sizeof(QueueType));
    qp->head = NULL;
    return qp;
}

int empty(Queue Q)
{
    return (Q->head == NULL);
}

void enqueue(Queue Q, int job, int p)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->job_num = job;
    np->priority = p;
    np->next = NULL;

    NodePtr prev, curr;
    prev = NULL;
    curr = Q->head;

    if(empty(Q))
    {
        Q->head = np;
    }
    else
    {
        //builds sorted queue based on priority number
        while (curr != NULL && p < curr->priority)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL) //new head of queue
        {
            np->next = Q->head;
            Q->head = np;
        }
        else
        {
            np->next = curr;
            prev->next = np;
        }
    }
}

int dequeue(Queue Q)
{
    if (empty(Q))
    {
        printf("Attempt to remove from an empty queue.\n");
        exit(1);
    }

    int hold = Q->head->job_num;
    NodePtr temp = Q->head;
    Q->head = Q->head->next;
    free(temp);
    return hold;
}

int removeJob(Queue Q, int job)
{
    NodePtr curr, prev, old;
    int hold;
    prev = NULL;
    curr = Q->head;

    while (curr != NULL && job != curr->job_num)
    {
        prev = curr;
        curr = curr->next;
    }
    if (job == curr->job_num)
    {
        //remove job at head of the queue
        if (prev == NULL)
        {
            old = Q->head;
            hold = Q->head->job_num;
            free(old);
            return hold;
        }
        else
        {
            hold = curr->job_num;
            prev->next = curr->next;
            free(curr);
            return hold;
        }
    }
    else
        return -1;

}

#endif // QUEUE_H_INCLUDED
