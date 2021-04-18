#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int maxCount, amountLess;
    double r = 0;

    printf("\nHow many numbers to use? ");
    scanf("%d", &maxCount);
    srand(time(0));
    amountLess = 0;

    for (int i = 1; i <= maxCount; i++)
    {
        r = 7 + rand()/(RAND_MAX + 1.0);
        if (r * r < 59)
            ++amountLess;
    }

    printf("\nEstimated square root for 59: %f", r);


    return 0;
}
