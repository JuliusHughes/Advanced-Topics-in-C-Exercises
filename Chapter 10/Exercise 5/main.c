#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void siftUp(int heap[], int n);

int main()
{
    int num[MAX + 1];
    int n = 0;
    int number;

    FILE * in = fopen("heap.txt", "r");

    while (fscanf(in, "%d ", &number) == 1 && number != 0)
    {
        if (n < MAX)
        {
            num[++n] = number;
            siftUp(num, n);
        }
        else
        {
            printf("\nArray too small\n");
            exit(1);
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", num[i]);

    printf("\n");
    fclose(in);

    return 0;
}

void siftUp(int heap[], int n)
{
    int siftItem = heap[n];
    int child = n;
    int parent = child/2;

    while (parent > 0)
    {
        if (siftItem >= heap[parent])
            break;
        heap[child] = heap[parent];
        child = parent;
        parent = child/2;
    }
    heap[child] = siftItem;
}
