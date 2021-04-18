#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void deleteMax(int A[], int n);
void siftDown(int key, int num[], int root, int last);
void heapSort(int num[], int n);
int merge(int A[], int m, int B[], int n, int C[]);

int main()
{
    int A[] = {0, 9, 22, 5, 18, 12, 7, 33, 16, 19, 21};
    int B[] = {0, 8, 20, 13, 4, 3, 45, 30, 24, 53};
    int C[MAX];
    C[0] = 19;


    //convert A[] to max heap
    for (int i = 10/2; i >= 1; i--)
        siftDown(A[i], A, i, 11);
      A[0] = 10;

    //convert B[] to max heap
    for (int i = 9/2; i >= 1; i--)
        siftDown(B[i], B, i, 10);
      B[0] = 9;


    printf("A: ");
    for (int i = 1; i <= 10; i++)
        printf("%d ", A[i]);

    printf("\n");

    printf("B: ");
    for (int i = 1; i <= 9; i++)
        printf("%d ", B[i]);

    printf("\n");

    heapSort(A, 10);
    heapSort(B, 9);

    int mergeMax = 0;


    mergeMax = merge(A, 11, B, 10, C);

    printf("C: ");
    for (int i = 1; i <= 18; i++)
        printf("%d ", C[i]);

    printf("\n");

//    deleteMax(A, 11);
//    deleteMax(B, 10);
//
//    printf("A after deleteMax: ");
//    for (int i = 1; i <= 9; i++)
//        printf("%d ", A[i]);
//
//    printf("\n");
//
//    printf("B after deleteMax: ");
//    for (int i = 1; i <= 8; i++)
//        printf("%d ", B[i]);
//
//    printf("\n");


    return 0;
}

void siftDown(int key, int num[], int root, int last)
{
    int larger = 2 * root;

    while (larger <= last)
    {
        if (larger < last)
        {
            if (num[larger + 1] > num[larger])
                larger++;
        }
        //'larger' holds the index of the bigger chil
        if (key >= num[larger])
            break;
        //key is smaller; promote num[larger]
        num[root] = num[larger];
        root = larger;
        larger = 2 * root;
    }
    num[root] = key;
} //end siftDown

void heapSort(int num[], int n)
{
    //sort num[1] to num[n]
    void siftDown(int, int[], int, int);
    //convert the array to a heap
    for (int i = n/2; i >= 1; i--)
        siftDown(num[i], num, i, n);

    for (int i = n; i > 1; i--)
    {
        int item = num[i];
        num[i] = num[1];
        siftDown(item, num, 1, i - 1);
    }
} //end heapSort

void deleteMax(int A[], int n)
{
    int hold = A[1];

    for (int i = 2; i < n; i++)
        A[i - 1] = A[i];

    //convert to max heap
    for (int i = n/2; i >= 1; i--)
        siftDown(A[i], A, i, n);

    A[0] -= 1;
} //end deleteMax

int merge(int A[], int m, int B[], int n, int C[])
{
    int i = 1;
    int j = 1;
    int k = -1;

    while (i < m || j < n)
    {
        if (i == m)
            C[++k] = B[j++];
        else if (j == n)
            C[++k] = A[i++];
        else if (A[i] < B[j])
            C[++k] = A[i++];
        else
            C[++k] = B[j++];
    }

    return m + n;
} //end merge
