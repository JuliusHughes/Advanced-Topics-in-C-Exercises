#include <stdio.h>
#include <stdlib.h>

int partition1(int A[], int m, int n);
void swap(int list[], int i, int j);
int kthSmall(int A[], int k, int lo, int n);

int main()
{
    int num[] = {0, 53, 12, 98, 63, 18, 32, 80, 46, 72, 21};
    int n = 10;
    int d = 0;
    int k = 2;

    for (int i = 1; i <= n; i++)
        printf("%d ", num[i]);

    d = kthSmall(num, k, 1, n);

    printf("\nThe 2nd smallest number is %d", d);

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

int kthSmall(int A[], int k, int lo, int n)
{
    int partition1(int A[], int m, int n);
    int kShift = 1 + k - 1;

    int dp = partition1(A, lo, n);
    int d = 0;

    if (dp != kShift)
    {
        if (kShift < dp)
        {
            n = dp - 1;
            return kthSmall(A, k, lo, n);
        }
        else
        {
            lo = dp + 1;
            return kthSmall(A, k, lo, n);
        }
    }

    d = dp;


    return A[d];
}
