#include <stdio.h>
#include <stdlib.h>

int random(int m, int n);

int main()
{
    int defective = 0;
    int r;

    srand(time(0));

    for (int i = 0; i < 5000; i++)
    {
        r = random(1, 100);

        if (r <= 1)
           ++defective;
    }

    printf("There are %d defective bulbs out of 5,000\n", defective);

    return 0;
}

int random(int m, int n)
{
    //retrieves random number between m and n

    int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
}
