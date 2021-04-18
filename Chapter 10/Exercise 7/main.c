#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 16

int hsort(int A[], int n, int h);
int random(int m, int n);

int main()
{
    srand(time(0));
    int num[MAX + 1];
    int size = MAX + 1;

    for (int i = 1; i < size; i++)
        num[i] = random(1, 100);

    int incr[100];
    int j = 1;
    int h = 1;
    incr[j] = h;

    while (h < size)
    {
        h = 3 * h + 1;
        j++;
        incr[j] = h;
    }

    incr[0] = j - 2;

    int comp = 0;

    for (int i = 1; i < size; i++)
        printf("%d ", num[i]);

    for (int i = 1; i <= incr[0]; i++)
        comp += hsort(num, size, incr[i]);

    printf("\n");

    for (int i = 1; i < size; i++)
        printf("%d ", num[i]);

    printf("\n");

    printf("Number of key comparisons: %d ", comp);

    return 0;
}

int hsort(int A[], int n, int h)
{
    int comp = 0;

    for (int k = h + 1; k < n; k++)
    {
        int j = k - h;
        int key = A[k];

        while (j > 0 && key < A[j])
        {
            A[j + h] = A[j];
            j = j - h;
            ++comp;
        }
        A[j + h] = key;
    }

    return comp;
}


int random(int m, int n)
{
    //returns a random integer from m to n, inclusive
    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);

    return m + offset;
}
