//Write a recursive function to implement selection sort
#include <stdio.h>
#include <stdlib.h>
#define MaxNumbers 10

void selectionSort(int list[], int lo, int hi, int max);
int getSmallest(int list[], int lo, int hi);
void swap(int list[], int i, int j);

int main()
{
    int num[MaxNumbers];
    printf("Type up to %d numbers followed by 0\n", MaxNumbers);
    int n = 0, v;
    scanf("%d", &v);

    while (v != 0 && n < MaxNumbers)
    {
        num[n++] = v;
        scanf("%d", &v);
    }

    if (v != 0)
    {
        printf("More than %d numbers entered.\n", MaxNumbers);
        printf("First %d used\n", MaxNumbers);
    }

    selectionSort(num, 0, n - 1, n - 1);
    printf("\nThe sorted numbers are\n");
    for (int i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");

    return 0;
}

int getSmallest(int list[], int lo, int hi)
{
    int small = lo;
    for (int h = lo + 1; h <= hi; h++)
        if (list[h] < list[small])
            small = h;

    return small;
}

void swap(int list[], int i, int j)
{
    int hold = list[i];
    list[i] = list[j];
    list[j] = hold;
}

void selectionSort(int list[], int lo, int hi, int max)
{
    int getSmallest(int list[], int lo, int hi);
    void swap(int list[], int i, int j);

    if (hi < lo)
        return;

    selectionSort(list, lo, hi - 1, max);
    int s = getSmallest(list, hi, max);
    swap(list, hi, s);
}
