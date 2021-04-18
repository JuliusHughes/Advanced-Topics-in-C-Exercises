#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 10
#define MAX2 100
#define MAX3 1000
#define MAX4 10000
#define MAX5 100000

long * heapsort(long num[], long n);
long * heapsort2(long num[], long n);
long * siftDown(long key, long num[], long root, long last);
void siftDown2(long key, long num[], long root, long last);
long * quickSort(long A[], long lo, long hi);
long * quickSort2(long A[], long lo, long hi);
long * partition(long A[], long lo, long hi);
long * partition2(long A[], long lo, long hi);
void swap(long A[], long i, long j);
long * hsort(long A[], long n, long h);
long random(long m, long n);


long random(long m, long n)
{
    //returns a random integer from m to n, inclusive
    long offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);

    return m + offset;
}

long * siftDown(long key, long num[], long root, long last)
{
    long bigger = 2 * root;
    static long comp[2];
    while (bigger <= last) //while there is at least one child
    {
        if (bigger < last) //there is a right child as well; find the bigger
        {
            if (num[bigger + 1] > num[bigger])
            {
                bigger++; // 'bigger' holds the index of the bigger child
            }
            comp[0]++;
        }

        if (key >= num[bigger])
        {
            comp[0]++;
            break;
        }

        num[root] = num[bigger];
        comp[1]++;
        root = bigger;
        bigger = 2 * root;

    }
    num[root] = key;
    comp[1]++;
    return comp;
}

void siftDown2(long key, long num[], long root, long last)
{
    long bigger = 2 * root;
    while (bigger <= last) //while there is at least one child
    {
        if (bigger < last) //there is a right child as well; find the bigger
        {
            if (num[bigger + 1] > num[bigger])
            {
                bigger++; // 'bigger' holds the index of the bigger child
            }
        }

        if (key >= num[bigger])
        {
            break;
        }

        num[root] = num[bigger];
        root = bigger;
        bigger = 2 * root;

    }
    num[root] = key;
}

long * heapsort(long num[], long n)
{
    long * siftDown(long key, long num[], long root, long last);
    void siftDown2(long key, long num[], long root, long last);

    //convert the array to a heap
    for (long h = n/2; h >= 1; h--)
        siftDown2(num[h], num, h, n);
    static long * r;
    static long num2[2];

    for (long k = n; k > 1; k--)
    {
        int item = num[k];
        num[k] = num[1];
        r = siftDown(item, num, 1, k - 1);
        num2[0] += *(r);
        num2[1] += *(r + 1);
    }

    return num2;
}

long * heapsort2(long num[], long n)
{
    long * siftDown(long key, long num[], long root, long last);
    void siftDown2(long key, long num[], long root, long last);

    //convert the array to a heap
    for (long h = n/2; h >= 1; h--)
        siftDown2(num[h], num, h, n);
    static long * r;
    static long num5[2];

    for (long k = n; k > 1; k--)
    {
        int item = num[k];
        num[k] = num[1];
        r = siftDown(item, num, 1, k - 1);
        num5[0] += *(r);
        num5[1] += *(r + 1);
    }

    return num5;
}


void swap(long A[], long i, long j)
{
    //swap list[i] and list[j]
    int hold = A[i];
    A[i] = A[j];
    A[j] = hold;
} //end swap

long * partition(long A[], long lo, long hi)
{
    void swap(long A[], long lo, long hi);

    static long comp2[3];
    int pivot = A[lo];

    long lastSmall = lo;

    for (long h = lo + 1; h <= hi; h++)
    {
        if (A[h] < pivot)
        {
            ++lastSmall;
            swap(A, lastSmall, h);
            ++comp2[2];
        }
        ++comp2[1];
    }
    swap(A, lo, lastSmall);
    comp2[0] = lastSmall;

    return comp2;
}

long * partition2(long A[], long lo, long hi)
{
    void swap(long A[], long lo, long hi);

    swap(A, lo, random(lo, hi));
    static long comp3[3];
    int pivot = A[lo];

    for (int i = 0; i < 3; i++)
        comp3[i] = 0;

    long lastSmall = lo;

    for (long h = lo + 1; h <= hi; h++)
    {
        if (A[h] < pivot)
        {
            ++lastSmall;
            swap(A, lastSmall, h);
            ++comp3[2];
        }
        ++comp3[1];
    }
    swap(A, lo, lastSmall);
    comp3[0] = lastSmall;

    return comp3;
}

long * quickSort(long A[], long lo, long hi)
{
    long * partition2(long A[], long lo, long hi);

    long * dp;
    static long num3[2];

    for (long i = 0; i < 2; i++)
    {
        num3[i] = 0;
    }

    long * r;

    if (lo < hi)
    {
        dp = partition2(A, lo, hi);
        r = quickSort(A, lo, *(dp) - 1);
        num3[0] += *(dp + 1);
        num3[1] += *(dp + 2);
        r = quickSort(A, *(dp) + 1, hi);
    }


    return num3;
}

long * quickSort2(long A[], long lo, long hi)
{
    long * partition(long A[], long lo, long hi);

    long * dp;
    static long num4[2];

    for (long i = 0; i < 2; i++)
    {
        num4[i] = 0;
    }

    long * r;

    if (lo < hi)
    {
        dp = partition(A, lo, hi);
        r = quickSort2(A, lo, *(dp) - 1);
        num4[0] += *(dp + 1);
        num4[1] = *(dp + 2);
        r = quickSort2(A, *(dp) + 1, hi);
    }

    return num4;
}

long * hsort(long A[], long n, long h)
{
    static long comp5[2];

    for (int i = 0; i < 2; i++)
        comp5[i] = 0;

    for (long k = h + 1; k <= n; k++)
    {
        long j = k - h;
        long key = A[k];

        while (j > 0 && key < A[j])
        {
            A[j + h] = A[j];
            j = j - h;
            ++comp5[0];
            ++comp5[1];
        }

        A[j + h] = key;
        ++comp5[1];

    }

    return comp5;
}


int main()
{
    srand(time(0));

    long comparison[5];
    long assignments[5];
    long * sortData;

    long arr1[MAX1];
    long arr2[MAX2];
    long arr3[MAX3];
    long arr4[MAX4];
    long arr5[MAX5];

    for (long i = 0; i < MAX1; i++)
        arr1[i] = random(1, 50);

    for (long i = 0; i < MAX2; i++)
        arr2[i] = random(1, MAX2);

    for (long i = 0; i < MAX3; i++)
        arr3[i] = random(1, MAX3);

    for (long i = 0; i < MAX4; i++)
        arr4[i] = random(1, MAX4);

     for (long i = 0; i < MAX5; i++)
        arr5[i] = random(1, MAX5);


    sortData = heapsort(arr1, MAX1);
    comparison[0] = *(sortData);
    assignments[0] = *(sortData + 1);

    sortData = quickSort(arr2, 0, MAX2);
    comparison[1] = *(sortData);
    assignments[1] = *(sortData + 1);

    sortData = quickSort2(arr3, 0, MAX3);
    comparison[2] = *(sortData);
    assignments[2] = *(sortData + 1);


    long incr[MAX4];
    long j = 1;
    long h = 1;
    incr[j] = h;
    long * size = malloc(sizeof(long));

    while (h < MAX4)
    {
        h = 3 * h + 1;
        j++;
        incr[j] = h;
        *(size)++;
    }

    *size = j - 2;
    incr[0] = *size;

    for (long i = 1; i <= incr[0]; i++)
    {
        sortData = hsort(arr4, MAX4, incr[i]);
        comparison[3] += *(sortData);
        assignments[3] += *(sortData + 1);
    }

    sortData = heapsort2(arr5, MAX5);
    comparison[4] = *(sortData);
    assignments[4] = *(sortData + 1);

    printf("The number of comparisons made using heapsort on an array of %d elements is %d\n", MAX1, comparison[0]);
    printf("The number of assignments made using heapsort on an array of %d elements is %d\n", MAX1, assignments[0]);
    printf("The number of comparisons made using quicksort on an array of %d elements is %d\n", MAX2, comparison[1]);
    printf("The number of assignments made using quicksort on an array of %d elements is %d\n", MAX2, assignments[1]);
    printf("The number of comparisons made using quicksort2 on an array of %d elements is %d\n", MAX3, comparison[2]);
    printf("The number of assignments made using quicksort2 on an array of %d elements is %d\n", MAX3, assignments[2]);
    printf("The number of comparisons made using shellsort on an array of %d elements is %d\n", MAX4, comparison[3]);
    printf("The number of assignments made using shellsort on an array of %d elements is %d\n", MAX4, assignments[3]);
    printf("The number of comparisons made using heapsort on an array of %d elements is %d\n", MAX5, comparison[4]);
    printf("The number of assignments made using heapsort on an array of %d elements is %d\n", MAX5, assignments[4]);

    free(size);
    return 0;
}
