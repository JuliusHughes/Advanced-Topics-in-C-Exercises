#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 12

void deleteRoot(int num[], int n);
void siftDown(int key, int num[], int root, int last);
void makeHeap(int num[], int n);
int random(int m, int n);

int main()
{
    srand(time(0));
    int num[MAX];

    for (int i = 1; i < MAX; i++)
        num[i] = random(1, 50);

    makeHeap(num, MAX);

    for (int i = 1; i < MAX; i++)
        printf("%d ", num[i]);

    printf("\n");

    deleteRoot(num, MAX);

    for (int i = 1; i < MAX - 1; i++)
        printf("%d ", num[i]);

    return 0;
}

int random(int m, int n)
{
    //returns a random integer from m + n, inclusive
    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
}

void siftDown(int key, int num[], int root, int last)
{
    int bigger = 2 * root;

    while (bigger <= last)
    {
        if (bigger < last)
        {
            if (num[bigger + 1] > num[bigger])
                bigger++;
        }
        if (key >= num[bigger])
            break;
        num[root] = num[bigger];
        root = bigger;
        bigger = 2 * root;
    }
    num[root] = key;
}

void makeHeap(int num[], int n)
{
    void siftDown(int key, int num[], int root, int last);

    //convert array to a heap
    for (int i = n/2; i >= 1; i--)
        siftDown(num[i], num, i, n);
}

void deleteRoot(int num[], int n)
{

    for (int i = 2; i < n; i++)
        num[i - 1] = num[i];

    int size = n - 1;

    for (int i = size/2; i >= 1; i--)
        siftDown(num[i], num, i, size);
}

