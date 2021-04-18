/*
    A gambler pays $5 to play the following game.  He throws two six-sided dice. If the sum of the two
    numbers thrown is even, he loses the bet.  If the sum is odd, he draws a card from a standard
    pack of 52 playing cards.  If he draws an ace, 3, 5, 7, or 9, he is paid the value of the card
    plus $5 (an ace counts as 1).  If he draws any other card, he loses.  Write a program to simulate
    the playing of 20 games and print the average amount won by the gambler per game.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int n);

int main()
{
    int dice1 = 0;
    int dice2 = 0;
    int sum = 0; //sum of two dice
    int card = 0;
    double avg = 0; //average amount won by the gambler
    int total = 0; //total money earned while playing the game
    int money = 0;

    srand(time(0));

    for (int i = 0; i < 20; i++)
    {
        dice1 = random(1, 6);
        dice2 = random(1, 6);
        sum = dice1 + dice2;

        if (sum % 2 == 1)
        {
            card = random(1, 10);
            if (card == 1 || card == 3 || card == 5 || card == 7 || card == 9)
            {
                money = 5 + card;
                total += money;
            }
        }
    }

    avg = total / 20;

    printf("\nThe gambler won an average amount of $%.2f per game.\n", avg);

    return 0;
}

int random(int m, int n)
{
    //returns a random integer from m to n, inclusive
    int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
} //end random
