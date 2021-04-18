#include <stdio.h>
#include <stdlib.h>

#define n 8
#define m 7

void insertionSort(int lo, int hi, int list[]);
int binarySearch(int key, int list[], int lo, int hi);

int main()
{
    int chosen[n];
    int winners[m];

    printf("Please enter distinct integers.\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter element #%d for chosen: ", (i + 1));
        scanf("%d", &chosen[i]);
    }

    for (int i = 0; i < m; i++)
    {
        printf("Enter element #%d for winners: ", (i + 1));
        scanf("%d", &winners[i]);
    }

    insertionSort(0, m, winners);

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int loc = binarySearch(chosen[i], winners, 0, m);
        if (loc != -1)
            ++count;
    }

    printf("%d of the numbers in chosen appear in winners\n", count);
    return 0;
}

void insertionSort(int lo, int hi, int list[])
{
    //sort list[lo] to list[hi] in ascending order
    for (int h = lo; h < hi; h++)
    {
        int key = list[h];
        int k = h - 1;
        while (k >= 0 && key < list[k])
        {
            list[k + 1] = list[k];
            --k;
        }
        list[k + 1] = key;
    }
}

int binarySearch(int key, int list[], int lo, int hi)
{
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (key == list[mid])
            return mid; //found
        if (key < list[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1; //key not found
}
