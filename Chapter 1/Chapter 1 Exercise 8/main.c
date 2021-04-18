#include <stdio.h>
#include <stdlib.h>

int merge(int A[], int m, int B[], int n, int C[]);

int main()
{
    int A[] = {57, 52, 43, 38, 33, 25, 21, 15, 13};
    int B[] = {73, 64, 51, 48, 39, 14};
    int C[20];

    int e = merge(A, 9, B, 6, C);
    for (int h = 0; h < e; h++)
        printf("%d ", C[h]);
    printf("\n\n");

    return 0;
}

int merge(int A[], int m, int B[], int n, int C[])
{
    int i = 0;
    int j = 0;
    int k = -1;

    while (i < m || j < n)
    {
        if (i == m)
            C[++k] = B[j++];
        else if (j == n)
            C[++k] = A[i++];
        else if (A[i] > B[j])
            C[++k] = A[i++];
        else
            C[++k] = B[j++];
    }

    return m + n;
}
