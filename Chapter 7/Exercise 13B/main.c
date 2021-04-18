/*

Generalize the program to request values for numTurns and maxThrowsPerTurn and print the results as shown earlier

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int n);

int main()
{
    int dice_roll, totalScore = 0;
    int * numTurns = malloc(sizeof(int));
    int * maxThrowsPerTurn = malloc(sizeof(int));
    double average = 0;

    srand(time(0));

    printf("Let's play one-zero\n\n");

    printf("Enter the # of turns: ");
    scanf("%d", numTurns);

    printf("Enter the max # of throws per turn: ");
    scanf("%d", maxThrowsPerTurn);

    for (int i = 0; i < *numTurns; i++)
    {
        for (int j = 0; j < *maxThrowsPerTurn; j++)
        {
            dice_roll = random(1, 6);
            if (dice_roll == 1)
            {
                totalScore = 0;
                break;
            }
            else
                totalScore += dice_roll;
        }
    }

    printf("\nThe total score is %d\n", totalScore);
    average = totalScore / *numTurns;
    printf("The average score per turn is %d\n\n", average);

    return 0;
}

int random(int m, int n)
{
    //returns a random integer from m to n, inclusive
    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
} //end random
