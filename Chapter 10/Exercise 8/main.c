#include <stdio.h>
#include <stdlib.h>


void siftDown(int key, int num[], int root, int last);
void convertHalfMinHeap(int num[], int n);
void convertToMinHeap(int num[], int n);

int main()
{
    int num[] = {0, 37, 25, 43, 65, 48, 84, 73, 18, 79, 56, 69, 32};
    int n = 12;

    convertHalfMinHeap(num, 6);

    for (int i = 1; i <= n; i++)
        printf("%d ", num[i]);


    convertToMinHeap(num, n);

    printf("\n");

    for (int i = 1; i <= n; i++)
        printf("%d ", num[i]);


    return 0;
}

void siftDown(int key, int num[], int root, int last)
{
    int smaller = 2 * root;

    while (smaller <= last)
    {
        if (smaller < last)
        {
            if (num[smaller + 1] < num[smaller])
                smaller++;
        }
        if (key <= num[smaller])
            break;

        num[root] = num[smaller];
        root = smaller;
        smaller = 2 * root;
    }

    num[root] = key;
}

void convertHalfMinHeap(int num[], int n)
{
    void siftDown(int key, int num[], int root, int last);

    for (int i = n/2; i >= 1; i--)
        siftDown(num[i], num, i, n);
}

void convertToMinHeap(int num[], int n)
{
    void siftDown(int key, int num[], int root, int last);

    for (int i = n/2; i >= 1; i--)
        siftDown(num[i], num, i, n);
}
