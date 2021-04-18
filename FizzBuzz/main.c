#include <stdio.h>
#include <stdlib.h>

int main()
{
    int limit = 100;

    for (int i = 1; i<100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            printf("\nFizzBuzz");
        else if (i % 3 == 0)
            printf("\nFizz");
        else if (i % 5 == 0)
            printf("\nBuzz");
        else
            printf("\n %d", i);
    }


    return 0;
}
