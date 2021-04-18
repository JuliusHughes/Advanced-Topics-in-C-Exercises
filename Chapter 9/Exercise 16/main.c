#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

void insertionSort(int list[], int lo, int hi);
void complete_bst(int list[], int bst[], int lo, int hi);
void inOrder(int bst[], int lo, int hi);
void preOrder(int bst[], int lo, int hi);

int main()
{
    int num[] = {0, 34, 23, 45, 46, 37, 78, 90, 2, 40, 20, 87, 53, 12, 15, 91};
    int bst[SIZE];
    //int *bst = calloc(SIZE, sizeof(int));

    for (int i = 0; i < SIZE; i++)
        bst[i] = 0;

    insertionSort(num, 1, 15);
    printf("num: ");
    for (int i = 1; i < SIZE; i++)
        printf("%d, ", num[i]);

    complete_bst(num, bst, 1, 15);
    printf("\nIn-order traversal: ");
    inOrder(bst, 1, 15);
    printf("\nPre-order traversal: ");
    preOrder(bst, 1, 15);

    //free(bst);
    return 0;
}

void inOrder(int bst[], int lo, int hi)
{
    if (lo <= hi)
    {
        inOrder(bst, lo * 2, hi);
        printf("%d ", bst[lo]);
        inOrder(bst, lo * 2 + 1, hi);
    }
}

void preOrder(int bst[], int lo, int hi)
{
    if (lo <= hi)
    {
        printf("%d ", bst[lo]);
        preOrder(bst, lo * 2, hi);
        preOrder(bst, lo * 2 + 1, hi);
    }
}

void insertionSort(int list[], int lo, int hi)
{
    //sort list[lo] to list[hi] in ascending order
    for (int i = lo + 1; i <= hi; i++)
    {
        int key = list[i]; //start comparing with the previous element
        int k = i - 1;
        while (i >= lo && key < list[k])
        {
            list[k + 1] = list[k];
            --k;
        }
        list[k + 1] = key;
    } //end for
} //end insertionSort

void complete_bst(int list[], int bst[], int lo, int hi)
{
    int median = 0;
    int mid = 0;
    int mid2 = 0;
    int mid3 = 0;
    int diff = 0;
    int diff2 = 0;

    for (int i = hi; i >= 1; i--)
    {
        if (i % 2 == 1)
        {
            mid = hi/2;
            median = list[mid];
        }
        else if (i % 2 == 0)
        {
            mid = hi/2;
            mid2 = mid + 1;
            median = (list[mid] + list[mid2])/2;
            diff = median - list[mid];
            diff2 = list[mid2] - median;

            if (diff > diff2)
            {
                median = list[mid2];
                mid3 = mid2;
            }
            else if (diff < diff2)
            {
                median = list[mid];
                mid3 = mid;
            }
        }

        if (i == hi)
            bst[lo] = median; //root of binary search tree
        else
        {
            int curr = lo;
            int next = 0;
            while (median != bst[curr] && curr <= hi)
            {
                if (bst[curr] == 0)
                {
                    bst[curr] = median;
                    break;
                }
                else if (median < bst[curr])
                {
                    next = 2 * curr;
                    if (bst[next] == 0 && next <= hi)
                    {
                        bst[next] = median;
                        break;
                    }
                    curr = next;
                }
                else if (median > bst[curr])
                {
                    next = (2 * curr) + 1;
                    if (bst[next] == 0 && next <= hi)
                    {
                        bst[next] = median;
                        break;
                    }
                    curr = next;
                }
            }
        }

        if (i % 2 == 1)
        {
            for (int j = mid; j <= i; j++)
                list[j] = list[j + 1];
        }
        else if (i % 2 == 0)
        {
            for (int j = mid3; j <= i; j++)
                list[j] = list[j + 1];
        }

    }
} //end complete_bst
