#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int random(int m, int n);

int main()
{
    int roll_count[6];
    int dice_roll;

    srand(time(0));

    for (int i = 0; i < 6; i++)
    {
        roll_count[i] = 0;
    }

    printf("Results of 1000 dice rolls\n\n");

    for (int i = 0; i < 1000; i++)
    {
        dice_roll = random(1,6);
        if (dice_roll == 1)
            ++roll_count[0];
        else if (dice_roll == 2)
            ++roll_count[1];
        else if (dice_roll == 3)
            ++roll_count[2];
        else if (dice_roll == 4)
            ++roll_count[3];
        else if (dice_roll == 5)
            ++roll_count[4];
        else if (dice_roll == 6)
            ++roll_count[5];
    }

    printf("1s: %d\n2s: %d\n3s: %d\n4s: %d\n5s: %d\n6s: %d", roll_count[0], roll_count[1], roll_count[2], roll_count[3], roll_count[4], roll_count[5]);

    return 0;
}

int random(int m, int n)
{
    //returns a random integer from m to n, inclusive

    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
}
