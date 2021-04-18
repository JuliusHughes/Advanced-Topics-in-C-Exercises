//Advanced Topics in C: Chapter 1 Exercise 9
#include <stdio.h>
#include <stdlib.h>

int merge(int A[], int m, int B[], int n, int C[]);

int main()
{
    int A[] = {200, 184, 173, 164, 157, 148, 113, 95, 82};
    int B[] = {300, 215, 193, 167, 165, 154, 137, 126};
    int C[22];

    int e = merge(A, 9, B, 8, C);
    for (int i = 0; i < e; i++)
        printf("%d ", C[i]);
    printf("\n");
    return 0;
}

int merge(int A[], int m, int B[], int n, int C[])
{
    int i = m - 1;
    int j = n - 1;
    int k = -1;

    while (i != -1 || j != -1)
    {
        if (i == -1)
            C[++k] = B[j--];
        else if (j == -1)
            C[++k] = A[i--];
        else if (A[i] < B[j])
            C[++k] = A[i--];
        else
            C[++k] = B[j--];
    }
    return m + n;
}
