//Modify Program 7.1 to play several games in one run.  After each game, ask the user if he wants to play another

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int random(int m, int n);

int main()
{
    int answer, guess;
    int play;

    srand(time(0));

   printf("Do you want to play a guessing game? (enter 1 to play or 2 to quit): ");
   scanf("%d", &play);
//   toupper(play);

       while(play == 1)
       {
           printf("\nI have thought of a number from 1 to 100.\n");
           printf("Try to guess what it is.\n\n");

           answer = random(1, 100);

           printf("Your guess? ");
           scanf("%d", &guess);
           while (guess != answer && guess != 0)
            {
                if (guess < answer)
                    printf("Too low\n");
                else
                    printf("Too high\n");
                printf("Your guess? ");
                scanf("%d", &guess);
            }
            if (guess == 0)
                printf("Sorry, answer is %d\n", answer);
            else
                printf("Congratulations, you've got it!\n");

            printf("Do you want to play another game? (enter 1 to play or 2 to quit): ");
            scanf("%d", &play);
//            toupper(play);
       }


    return 0;
}

int random(int m, int n)
{
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
}
