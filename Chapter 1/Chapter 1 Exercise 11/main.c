#include <stdio.h>
#include <stdlib.h>

int merge(int A[], int m, int B[], int n, int C[]);

int main()
{
    int A[] = {12, 24, 28, 35, 56, 63, 75, 51, 43, 38, 29, 25, 9};
    int B[13];
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < 13; i++)
    {
        if (i > 0)
        {
            if (A[i] > A[i - 1])
                ++count1;
            else
                ++count2;
        }
        else
            ++count1;
    }

    int mini_A1[count1];
    int mini_A2[count2];

    int j = 0;
    for (int i = 0; i < 13; i++)
    {
        if (i > 0)
        {
            if (A[i] > A[i - 1])
                mini_A1[i] = A[i];
            else
            {
                mini_A2[j] = A[i];
                ++j;
            }
        }
        else
            mini_A1[i] = A[i];
    }

    for (int i = 0; i < count1; i++)
        printf("%d ", mini_A1[i]);
    printf("\n");

    for (int i = 0; i < count2; i++)
        printf("%d ", mini_A2[i]);
    printf("\n");



    int e = merge(mini_A1, count1, mini_A2, count2, B);
    for (int i = 0; i < e; i++)
        printf("%d ", B[i]);

    return 0;
}

int merge(int A[], int m, int B[], int n, int C[])
{
    int i = 0;
    int j = n - 1;
    int k = -1;

    while(i < m || j != -1)
    {
        if (i == m)
            C[++k] = B[j--];
        else if (j == -1)
            C[++k] = A[i++];
        else if (A[i] < B[j])
            C[++k] = A[i++];
        else
            C[++k] = B[j--];
    }

    return m + n;
}
