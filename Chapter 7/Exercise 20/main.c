#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSim 50
#define MaxLetters 4

int doOneSim();

int main()
{
    int capsThisSim, totalCaps = 0;

    srand(time(0));

    printf("\nSimulation caps collected\n\n");
    for (int sim = 1; sim <= MaxSim; sim++)
    {
        capsThisSim = doOneSim();
        printf("%6d %13d\n", sim, capsThisSim);
        totalCaps += capsThisSim;
    }

    printf("\nAverage caps per simulation: %d\n", totalCaps/MaxSim);

    return 0;
}

int doOneSim()
{
    int cap[MaxLetters], numCaps = 0, apple(int []), random(int m, int n);

    for (int i = 0; i < MaxLetters; i++)
        cap[i] = 0;

    while(!apple(cap))
    {
        int c = random(1, 10);
        if (c <= 4)
            cap[0] = 1; // A
        else if (c <= 8)
            cap[1] = 1; // E
        else if (c == 9)
            cap[2] = 1; // P
        else
            cap[3] = 1; // L

        ++numCaps;
    }

    return numCaps;
}

int apple(int cap[])
{
    for (int i = 0; i < MaxLetters; i++)
        if (cap[i] == 0)
            return 0;
    return 1;
}

int random(int m, int n)
{
    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
} //end random
