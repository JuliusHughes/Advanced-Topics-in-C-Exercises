//Write a recursive function to return the largest element in an integer array
#include <stdio.h>
#include <stdlib.h>
#define MaxNumbers 10

int getLargest(int list[], int lo, int hi);

int main()
{
    int num[MaxNumbers];
    printf("Type up to %d numbers followed by 0\n", MaxNumbers);
    int n = 0, v;
    scanf("%d", &v);

    while (v != 0 && n < MaxNumbers)
    {
        num[n++] = v;
        scanf("%d", &v);
    }

    if (v != 0)
    {
        printf("More than %d numbers entered.\n", MaxNumbers);
        printf("First %d used\n", MaxNumbers);
    }

    int largest = getLargest(num, 0, n - 1);

    printf("The largest element in the array is %d \n", largest);

    return 0;
}

int getLargest(int list[], int lo, int hi)
{
    int large; //holds the largest value in the array

    //set the first value in the array as the largest for base case
    if (hi == lo)
    {
        large = list[hi];
        return large;
    }

    large = getLargest(list, lo, hi - 1);
    if (list[hi] > large)
        large = list[hi];

    return large;
}
