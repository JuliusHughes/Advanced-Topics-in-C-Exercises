//Write a program to read a positive integer n and estimate the square root of n

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maxCount, amountLess;
    double r;
    int n, m = 0;

    printf("\nHow many numbers to use? ");
    scanf("%d", &maxCount);

    printf("\nEnter a number to find the square root of: ");
    scanf("%d", &n);

    //find the integer that's the same or near the square root of n
    while (m * m < n)
    {
        int temp = m;
        ++m;

        if (m * m > n)
        {
            m = temp;
            break;
        }
    }


    amountLess = 0;

    if (m * m == n)
        printf("%d is the square root of %d.\n\n", m, n);
    else
    {
        for (int i = 1; i <= maxCount; i++)
        {
            r = m + rand()/(RAND_MAX + 1.0);
            if (r * r < n)
                ++amountLess;
        }
    }

    printf("\nAn approximation to the square root of  is %5.3f\n", m + (double) amountLess/maxCount);

    return 0;
}
