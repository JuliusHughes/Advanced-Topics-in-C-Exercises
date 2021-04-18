#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    int job, p, temp;

    Queue Q = initQueue();

    printf("Enter an integer for a job number: ");
    while (scanf("%d", &job) == 1)
    {
        printf("Enter an integer for a priority number: ");
        scanf("%d", &p);
        enqueue(Q, job, p);
        printf("Enter an integer for job number: ");
    }

    printf("Enter a job number you want to remove from the queue: ");
    while (scanf("%d", &temp) == 1)
    {
        int num = removeJob(Q, temp);
        if (num == -1)
        {
            printf("\nThis job is not in the queue.\n");
            break;
        }
        else
            printf("%d ", &num);
    }

    return 0;
}
