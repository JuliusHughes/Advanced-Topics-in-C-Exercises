#include <stdio.h>
#include <stdlib.h>

int repeat_search(int A[], int n, int x);

int main()
{
    int A[] = {1, 2, 3, 4, 4, 5, 5, 5, 32, 53, 64, 76, 86};

    int count = repeat_search(A, 13, 5);

    printf("The number of times 5 appears in A is %d\n", count);

    return 0;
}

int repeat_search(int A[], int n, int x)
{
    int count = 0;

    if (n == -1)
        return 0;

    count = repeat_search(A, n-1, x);
    if (A[n] == x)
        ++count;

    return count;
}
