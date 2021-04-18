#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int random(int m, int n);

int main()
{
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
    int dice_roll;

    srand(time(0));

    printf("Results of 1000 dice rolls\n\n");

    for (int i = 0; i < 1000; i++)
    {
        dice_roll = random(1,6);
        if (dice_roll == 1)
            ++count1;
        else if (dice_roll == 2)
            ++count2;
        else if (dice_roll == 3)
            ++count3;
        else if (dice_roll == 4)
            ++count4;
        else if (dice_roll == 5)
            ++count5;
        else if (dice_roll == 6)
            ++count6;
    }

    printf("1s: %d\n2s: %d\n3s: %d\n4s: %d\n5s: %d\n6s: %d", count1, count2, count3, count4, count5, count6);

    return 0;
}

int random(int m, int n)
{
    //returns a random integer from m to n, inclusive

    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
}
