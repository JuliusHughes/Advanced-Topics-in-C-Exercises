//Advanced Topics in C: Chapter 1 Exercise 5
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int lo, int hi, int list[], int key);
void selectionSort(int list[], int lo, int hi);
int getLargest(int [], int, int);
void swap(int[], int, int);
void insertionSort(int lo, int hi, int list1[], int list2[]);

int main()
{
    int num[] = {5, 5, 5, 5, 6, 7, 4, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4};


    selectionSort(num, 0, 21);
    for (int i = 0; i < 21; i++)
        printf("%d, ", num[i]);
    int count = 0; //determines size of unique_num and frequency arrays

    for (int i = 0; i < 21; i++)
    {
        if (i == 0)
            ++count;
        else
        {
            int loc = binarySearch(0, (i - 1), num, num[i]);
            if (loc == -1) //new unique number
                ++count;
        }
    }

    int unique_num[count];
    int frequency[count];

    int j;
    for (int i = 0, j = 0; j < 21; j++)
    {
        if (j > 0)
        {
            int loc = binarySearch(0, (j - 1), num, num[j]);
            if (loc == -1)
            {
                unique_num[i] = num[j];
                ++i;
            }
        }
    }

    for (int i = 0; i < count; i++)
        frequency[i] = 0;

    int j2;
    for (int i = 0, j2 = 0; j2 < 21; j2++)
    {
        if (j2 > 0)
        {
            int loc = binarySearch(0, (j2 - 1), num, num[j2]);
            if (loc == -1)
            {
                ++i;
                ++frequency[i];
            }
            else
                ++frequency[i];
        }
        else
            ++frequency[i];
    }

    insertionSort(0, count, unique_num, frequency);

    printf("\nThe mode of this array is %d ", unique_num[0]);

    return 0;
}

int getLargest(int list[], int lo, int hi)
{
        int large = lo;
        for (int h = lo + 1; h <= hi; h++)
        {
            if (list[h] > list[large])
                large = h;
        }

        return large;
}

void swap(int list[], int i, int j)
{
        int hold = list[i];
        list[i] = list[j];
        list[j] = hold;
}

void selectionSort(int list[], int lo, int hi)
{
    //sort list[lo] to list[hi] in descending order
    for (int h = lo; h < hi; h++)
    {
        int l = getLargest(list, h, hi);
        swap(list, h, l);
    }
}

void insertionSort(int lo, int hi, int list1[], int list2[])
{
    for (int h = lo + 1; h < hi; h++)
    {
        int key1 = list1[h];
        int key2 = list2[h];
        int k = h - 1;
        while (k >= 0 && key2 > list2[k])
        {
            list2[k + 1] = list2[k];
            --k;
        }
        list2[k + 1] = key2;
        list1[k + 1] = key1;
    }
}

int binarySearch(int lo, int hi, int list[], int key)
{
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (key == list[mid])
            return mid;
        if (key < list[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1; //key not found
}
