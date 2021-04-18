/*

Write a program to simulate the game of Snakes and Ladders.  The board consists of 100 squares.  Snakes and ladders
are input as ordered pairs of numbers, m and n.  For example, the pair 17 64 means that there is a ladder from 17 64,
and the pair 99 28 means that there is a snake from 99 to 28.

Simulate the playing of 20 games, each game lasting a maximum of 100 moves.  Print the number of games that were completed
in the 100 moves and the average number of moves per game for completed games.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int n);

int main()
{
    int m, n, totalMoves[20], prev_n;
    int total_games = 0; //total number of completed games
    int total = 0; //total number of moves for all games
    double avg_moves = 0.0; //average moves per game

    srand(time(0));

    for (int i = 0; i < 20; i++)
    {
        totalMoves[i] = 0;
    }

    for (int i = 0; i < 20; i++) //20 games
    {
        for (int j = 1; j <= 100; j++) //100 is maximum number of moves per game
        {
            if (j == 1) //if it's the first move
            {
                m = random(1, 100); //first part of pair
                n = random(1, 100); //second part of pair

                while (m == n) //choose different number for n
                    n = random(1, 100);
                prev_n = n;
            }
            else //every other move
            {
                m = prev_n; //the previous n is the starting point
                n = random(1, 100);

                while (m == n)
                    n = random(1, 100);
                prev_n = n;
            }

            if (n == 100) //completed a game
            {
                totalMoves[i] = j; //total number of moves for this game
                ++total_games;
                break;
            } //end if
        } //end for j
    } //end for i

    for (int i = 0; i < 20; i++)
    {
        if (totalMoves[i] > 0)
            total += totalMoves[i]; //add total moves for each completed game to overall total
    }

    avg_moves = total/total_games;

    printf("\nThe total # of completed games is %d\n", total_games);
    printf("The average # of moves per game for completed games is %f\n\n", avg_moves);

    return 0;
}

int random(int m, int n)
{
    //returns a random integer from m to n, inclusive
    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
} //end random
