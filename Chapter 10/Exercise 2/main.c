#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 13

void siftUp(int heap[], int n);
void makeHeap(int heap[], int n);
int random(int m, int n);

int main()
{
    srand(time(0));
    int heap[MAX];
    heap[0] = MAX - 1;

    for (int i = 1; i <= 12; i++)
        heap[i] = random(1, 50);

    for (int i = 1; i <= 12; i++)
        printf("%d ", heap[i]);

    makeHeap(heap, MAX);

    printf("\n");
    for (int i = 1; i <= 12; i++)
        printf("%d ", heap[i]);

    return 0;
}

int random(int m, int n)
{
    //returns a random integer from m to n, inclusive
    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
} //end random

void siftUp(int heap[], int n)
{
    int siftItem = heap[n];
    int child = n;
    int parent = child/2;

    while (parent > 0)
    {
        if (siftItem <= heap[parent])
            break;

        heap[child] = heap[parent];
        child = parent;
        parent = child/2;
    }

    heap[child] = siftItem;
}

void makeHeap(int heap[], int n)
{
    void siftUp(int heap[], int n);
    int size = heap[0];

    for (int i = 2; i <= size; i++)
        siftUp(heap, i);
}


