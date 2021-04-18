//Write a program to simulate the weather for 60 days using the probabilities in Section 7.7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int n);

int main()
{
    int sun_count = 0, rain_count = 0, overcast_count = 0;
    int r; //random number for weather

    srand(time(0));

    for (int i = 0; i < 60; i++)
    {
        r = random(1, 9);
        if (r <= 4)
            ++sun_count;
        else if (r <= 7)
            ++rain_count;
        else
            ++overcast_count;
    }

    printf("There were %d sunny days, %d rainy days, and %d overcast days\n", sun_count, rain_count, overcast_count);

    return 0;
}

int random(int m, int n)
{
    //retrieves a random number from m to n.
    int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
}
