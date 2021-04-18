#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 12

void makeHeap(int num[], int n);
int random(int m, int n);
void siftDown(int key, int num[], int root, int last);
void siftUp(int num[], int n);
void addElement(int num[], int max, int v);

int main()
{
    srand(time(0));
    int num[MAX];

    num[0] = 0;

    for (int i = 1; i <= MAX; i++)
    {
        int v = random(1, 70);
        addElement(num, MAX, v);
    }

    printf("Heap: ");
    for (int i = 1; i < MAX; i++)
        printf("%d ", num[i]);

    printf("\n");

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

void siftUp(int num[], int n)
{
    int siftItem = num[n];
    int child = n;
    int parent = child/2;

    while (parent > 0)
    {
        if (siftItem <= num[parent])
            break;

        num[child] = num[parent];
        child = parent;
        parent = child/2;
    }
    num[child] = siftItem;
}

void addElement(int num[], int max, int v)
{
    num[0]++;
    int size = num[0];

    if (size < max)
    {
        num[size] = v;
        siftUp(num, size);
    }
    else if (size >= max)
        printf("There's no room in the heap to store %d \n", v);
}
