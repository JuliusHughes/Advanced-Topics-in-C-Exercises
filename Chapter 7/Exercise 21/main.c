/*
    The Lotto requires people to pick seven numbers from the numbers 1 to 40.  Write a program
    to randomly generate and print five sets of seven numbers each (one set per line).  No number
    is to be repeated in any of the sets; that is, exactly 35 of the 40 numbers must be used.
    If a number (p, say) is generated that has been used already, the first unused number after p is
    used.  (Assume that 1 follows 40.)  For example, if 15 is generated but has been used already,
    16 is tried, but if this has been used, 17 is tried and son on, until an unused number is found.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int n);

int main()
{
    int p;
    int num[35]; //checks which numbers have been picked already
    int lotto[5][7]; // 5 sets of 7 lotto numbers

    srand(time(0));

    //set all lotto numbers to 0
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
            lotto[i][j] = 0;
    }


    //5 sets
    for (int i = 0; i < 5; i++)
    {
        //7 numbers
        for(int j = 0; j < 7; j++)
        {
            p = random(1, 40);
            for (int k = 0; k < 40; k++) // loop for # of times to search for repeated number
            {
                //iterate through lotto array to see if p has been selected already
                for (int x = 0; x < 5; x++)
                {
                    for (int y = 0; y < 7; y++)
                    {
                        if (lotto[x][y] == p) //p has been selected already
                        {
                            if (p == 40) //if p is the max, start from the beginning
                                p = 1;
                            else
                                ++p;
                            break;
                        }
                    } //end for y
                } //end for x
            } //end for k
            lotto[i][j] = p;
        } //end for j
    } //end for i

    //print
    for (int i = 0; i < 5; i++)
    {
        printf("\nLotto set %d:", i + 1);
        for (int j = 0; j < 7; j++)
        {
            printf(" %d", lotto[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int random(int m, int n)
{
    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
}
