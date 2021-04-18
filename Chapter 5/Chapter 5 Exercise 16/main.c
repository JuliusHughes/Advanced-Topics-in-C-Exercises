//Show how to implement a queue using two stacks

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    int n;
    Queue Q = initQueue();

    printf("Enter an integer to add to the queue: ");
    scanf("%d", &n);
    while (n != 0)
    {
        enqueue(Q, n);
        printf("Enter an integer to add to the queue: ");
        scanf("%d", &n);
    }

    printf("\nNumbers in order\n");
    while (!emptyQueue(Q))
        printf("%d ", dequeue(Q));
    printf("\n");

    return 0;
}
