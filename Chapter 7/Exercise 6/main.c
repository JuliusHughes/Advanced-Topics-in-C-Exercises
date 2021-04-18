#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int try_1, maxTries, numProblems, answer, response;
   int num1, num2, random(int, int);

   printf("\nWelcome to Problems in Addition\n\n");
   printf("How many problems would you like? ");
   scanf("%d", &numProblems);
   printf("Maximum tries per problem? ");
   scanf("%d", &maxTries);

   srand(time(0));

   for (int h = 1; h <= numProblems; h++) {
      num1 = random(10, 99);
      num2 = random(10, 99);
      answer = num1 * num2;
      for (try_1 = 1; try_1 <= maxTries; try_1++) {
         printf("\nProblem %d, try_1 %d of %d\n", h, try_1, maxTries);
         printf("%5d * %2d = ", num1, num2);
         scanf("%d", &response);
         if (response == answer) {
            printf("Correct, well done!\n");
            break;
         }
         if (try_1 < maxTries) printf("Incorrect, try_1 again\n");
         else printf("Sorry, answer is %d\n", answer);
      } //end for try_1
   } //end for h
   printf("\nThank you for playing. Bye...\n");
} //end main

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random
