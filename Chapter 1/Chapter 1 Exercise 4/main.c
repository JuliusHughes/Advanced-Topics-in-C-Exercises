#include <stdio.h>
#include <stdlib.h>



void insertionSort(int list[], int j);

int main()
{
    int n, mid, mid2, mid3;

    n = rand() % 10; // get number of elements for num array
    int num[n];

    for (int i = 0; i < n; i++)
        num[i] = rand() % 5;

    insertionSort(num, n);
    for (int i = 0; i < n; i++)
        printf("%d", &num[i]);


    if (n % 2 == 1)
    {
        mid = n/2;
        printf("\n\nThe median is %d ", num[mid]);
    }

    if (n % 2 == 0) //takes average of two medium values
    {
        mid = n/2;
        mid2 = mid + 1;
        mid3 = (num[mid] + num[mid2])/2;
        printf("\nThe median is %d ", mid3);
    }

    return 0;
}

void insertionSort(int list[], int j)
{
    int key;
    //sort list[0] to list[j] in ascending order
    for (int i = 1; i < j; i++)
    {
        key = list[i];
        int k = i - 1;
        while (k >= 0 && key < list[k])
        {
            list[k + 1] = list[k];
            --k;
        }
        list[k + 1] = key;
    }
}
