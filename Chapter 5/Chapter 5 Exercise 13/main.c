#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    int job, p;
    int jack;

    Queue Q = initQueue();

    printf("Enter an integer for a job number: ");
    scanf("%d", &job);
    while (job != -1)
    {
        printf("Enter an integer for a priority number: ");
        scanf("%d", &p);
        enqueue(Q, job, p);
        printf("Enter an integer for job number: ");
        scanf("%d", &job);
    }


    printf("Enter a job number you want to remove from the queue: ");
    scanf("%d", &jack);

        int num = removeJob(Q, jack);
        if (num == -1)
        {
            printf("\nThis job is not in the queue.\n");
        }
        else
            printf("%d ", &num);


    /*
    while (!empty(Q))
    {
        printf("%d ", dequeue(Q));
    }
    */

    return 0;
}
