#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    double n; //Data you're adding to the queue

    Queue Q = initQueue();

    printf("Enter a floating point number to add to the queue (enter 0 to quit): ");
    while (scanf("%lf", &n) == 1)
    {
        enqueue(Q, n);
        printf("Enter a floating point number to add to the queue (enter 0 to quit): ");
    }

    printf("\nNumbers in order\n");
    while(!empty(Q))
    {
        printf("%.4f ", dequeue(Q));
    }

    printf("\n");

    return 0;
}
