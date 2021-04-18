/*
One-zero is a game that can be played among several players using a six-sided die.  On his turn, a player can throw
the die as many times as he wants.  His score for that turn is the sum of the numbers he throws provided he does not throw a
1.  If he throws a 1, his score is 0.  Suppose a player decides to adopt the strategy of ending his turn after seven throws.
(Of course, if he throws a 1 before the seventh throw, he must end his turn.) Write a program to play ten turns using this
strategy.  For each turn, print the score obtained.  Also, print the average score for the ten turns.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int n);

int main()
{
    int dice_roll, totalScore = 0, sum = 0;
    double average = 0;

    srand(time(0));

    printf("Let's play a game of one-zero\n\n");

    for (int i = 0; i < 10; i++) //10 turns
    {
        for (int j = 0; j < 7; j++) //7 throws per turn
        {
            dice_roll = random(1, 6);
            if (dice_roll == 1)
            {
                totalScore = 0; //set score to 0 if dice roll is 1
                break;
            }
            else
            {
                totalScore += dice_roll;
            }
        }

        sum += totalScore; //sum of all scores

        printf("\nThe total score for turn %d is %d\n", i + 1, totalScore);
    }

    average = sum/10;

    printf("The average score for the ten turns is %f\n\n", average);

    return 0;
}

int random(int m, int n)
{
    //returns a random integer from m to n, inclusive
    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
} //end random
