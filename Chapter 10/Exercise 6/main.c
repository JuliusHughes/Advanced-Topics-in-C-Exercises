#include <stdio.h>
#include <stdlib.h>

int quicksort(int A[], int m, int n);
int partition1(int A[], int m, int n);
void swap(int list[], int i, int j);


int main()
{
    int num[] = {0, 53, 12, 98, 63, 18, 32, 80, 46, 72, 21};
    int n = 10;
    int d;

    d = quicksort(num, 1, n);

    for (int i = 1; i <= n; i++)
        printf("%d ", num[i]);

    printf("\nThe division point subscript is %d", d);

    return 0;
}

void swap(int list[], int i, int j)
{
    //swap list[i] and list[j]
    int hold = list[i];
    list[i] = list[j];
    list[j] = hold;
} //end swap

int partition1(int A[], int m, int n)
{
    void swap(int list[], int i, int j);

    int pivot = A[m];
    int lastSmall = m;

    for (int i = m + 1; i <= n; i++)
    {
        if (A[i] < pivot)
        {
            ++lastSmall;
            swap(A, lastSmall, i);
        }
    }

    swap(A, m, lastSmall);

    return lastSmall;
}

int quicksort(int A[], int m, int n)
{
    int partition1(int A[], int m, int n);

    int d;

    if (m < n)
    {
        int dp = partition1(A, m, n);

        d = quicksort(A, m, dp - 1);
        d = quicksort(A, m + 1, dp);
        d = dp;
    }


    return d;
}
