#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int remain[2], maxPick, userPick, compPick, choice;
   int bestPick(int, int), min(int, int);
   printf("\nNumber of matches on table 1? ");
   scanf("%d", &remain[0]);
   printf("\nNumber of matches on table 2? ");
   scanf("%d", &remain[1]);
   printf("Maximum pickup per turn? ");
   scanf("%d", &maxPick);
   printf("\nMatches remaining for pile 1: %d\n", remain[0]);
   printf("\nMatches remaining for pile 2: %d\n", remain[1]);

   srand(time(0));
   while (1) { //do forever...well, until the game ends
      do {
         printf("Which card pile (1 or 2)? ");
         scanf("%d", &choice);

         while (choice != 1 && choice != 2)
            scanf("%d", &choice);

         if (choice == 1)
         {
             printf("Your turn: ");
             scanf("%d", &userPick);
            if (userPick > remain[0])
                printf("Cannot pick up more than %d\n", min(remain[0], maxPick));
            else if (userPick < 1 || userPick > maxPick)
                printf("Invalid: must be between 1 and %d\n", maxPick);
         }//end if choice == 1
         else if (choice == 2)
         {
             printf("Your turn: ");
            scanf("%d", &userPick);
            if (userPick > remain[1])
                printf("Cannot pick up more than %d\n", min(remain[1], maxPick));
            else if (userPick < 1 || userPick > maxPick)
                printf("Invalid: must be between 1 and %d\n", maxPick);
         }//end if choice == 2

      } while (userPick > remain[0] || userPick < 1 || userPick > maxPick || userPick > remain[1]);

      if (choice == 1)
      {
          remain[0] = remain[0] - userPick;
          printf("Matches remaining for pile 1: %d\n", remain[0]);
          if (remain[0] == 0) {
             printf("You lose!!\n");
             exit(0);
          }
          if (remain[0] == 1) {
             printf("You win!!\n");
             exit(0);
          }
          compPick = bestPick(remain[0], maxPick);
          printf("I pick up %d\n", compPick);
          remain[0] = remain[0] - compPick;
          printf("Matches remaining for pile 1: %d\n", remain[0]);
          if (remain[0] == 1)
          {
             printf("You win!!\n");  exit(0);
          }
          if (remain[0] == 0)
          {
             printf("I win!!\n");  exit(0);
          }
      }//end if choice == 1
      else if (choice == 2)
      {
          remain[1] = remain[1] - userPick;
          printf("Matches remaining for pile 2: %d\n", remain[1]);
          if (remain[1] == 0) {
             printf("You lose!!\n");
             exit(0);
          }
          if (remain[1] == 1) {
             printf("You win!!\n");
             exit(0);
          }
          compPick = bestPick(remain[1], maxPick);
          printf("I pick up %d\n", compPick);
          remain[1] = remain[1] - compPick;
          printf("Matches remaining for pile 2: %d\n", remain[1]);
          if (remain[1] == 1)
          {
             printf("You win!!\n");  exit(0);
          }
          if (remain[1] == 0)
          {
             printf("I win!!\n");  exit(0);
          }
      }//end if choice == 2
   } //end while(1)
} //end main


int bestPick(int remain, int maxPick) {
   int random(int, int);
   if (remain <= maxPick) return remain - 1; //put user in losing position
   int r = remain % (maxPick + 1);
   if (r == 0) return maxPick; //put user in losing position
   if (r == 1) return random(1, maxPick); //computer in losing position
   return r - 1; //put user in losing position
} //end bestPick

int min(int a, int b) {
   if (a < b) return a;
   return b;
} //end min

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random
