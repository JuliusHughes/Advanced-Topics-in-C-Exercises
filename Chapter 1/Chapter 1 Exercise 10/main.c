#include <stdio.h>
#include <stdlib.h>

int merge(int A[], int m, int B[], int n, int C[]);

int main()
{
    int A[] = {7, 24, 29, 36, 45, 53, 64, 71, 88};
    int B[] = {90, 73, 65, 51, 48, 33, 28};
    int C[20];

    int e = merge(A, 9, B, 7, C);
    for (int h = 0; h < e; h++)
        printf("%d ", C[h]);
    printf("\n");

    return 0;
}

int merge(int A[], int m, int B[], int n, int C[])
{
    int i = 0;
    int j = n - 1;
    int k = -1;

    while (i < m || j != -1)
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
