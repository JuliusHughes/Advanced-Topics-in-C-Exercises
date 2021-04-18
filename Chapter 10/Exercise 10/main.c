#include <stdio.h>
#include <stdlib.h>

void insertionSort(int list[], int n);
int binarySearch(int key, int list[], int lo, int hi);
void swap(int list[], int i, int j);

int main()
{
    int num[] = {57, 48, 79, 65, 15, 33, 52};

    for (int i = 0; i < 7; i++)
        printf("%d ", num[i]);
    printf("\n");

    insertionSort(num, 7);

    for (int i = 0; i < 7; i++)
        printf("%d ", num[i]);
    printf("\n");

    return 0;
}

int binarySearch(int key, int list[], int lo, int hi)
{
    while (lo <= hi)
    {
        int mid = (lo + hi)/2;
        if (key == list[mid])
            return mid;
        if (key < list[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return -1;
}

void swap(int list[], int i, int j)
{
    //swap elements list[i] and list[j]
    int hold = list[i];
    list[i] = list[j];
    list[j] = hold;
}

void insertionSort(int list[], int n)
{
    int binarySearch(int, int[], int, int);
    void swap(int[], int, int);
    for (int j = 1; j < n; j++)
    {
        int key = list[j];
        int k2 = j - 1; // used to find smallest
        int k = j - 1;
        int smallestGreater = 0;

       //for (int i = k; i >= 0; i--)
       while (k >= 0)
       {
           if (list[k] > key)
           {
               if (smallestGreater == 0)
                smallestGreater = list[k];
               else if (smallestGreater > list[k])
                smallestGreater = list[k];
           }

           //if (j > 0)
           //{
               //if (list[j] < list[j - 1])
             //   swap(list, j - 1, j);
           //}
           --k;
       }

       int min = 0;
       min = binarySearch(smallestGreater, list, 0, k2);

       while (k2 >= min && key < list[k2])
       {
           list[k2 + 1] = list[k2];
           --k2;
       }

       list[min] = key;
    } //end outer for
}
