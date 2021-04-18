#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxCounters 9

int main() {
   int  random(int, int), smallest(int[], int, int), max(int, int);
   int depart[MaxCounters + 1];
   int totalIdle[MaxCounters + 1];
   int prevDepart[MaxCounters + 1];
   int m, n, numCust, arriveTime, startServe, serveTime, waitTime, idleTime;
   int totalWaitTime = 0;
   int averageWait = 0;

   printf("\nHow many counters? ");
   scanf("%d", &n);
   printf("\nHow many customers? ");
   scanf("%d", &numCust);

   for (int c = 1; c <= n; c++)
   {
       depart[c] = 0;
       totalIdle[c] = 0;
       prevDepart[c] = 0;
   }

   srand(time(0));
   printf("\n                  Start          Service         Wait\n");
   printf("Customer Arrives Service Counter  Time   Departs Time\n\n");
   arriveTime = 0;
   for (int c = 1; c <= numCust; c++) {
      arriveTime += random(1, 5);
      m = smallest(depart, 1, n);
      startServe = max(arriveTime, depart[m]);
      serveTime = random(3, 10);
      depart[m] = startServe + serveTime;
      waitTime = startServe - arriveTime;

      totalWaitTime += waitTime;

      if (c == 1) //code for the first customer
      {
          for (int i = 1; i <= n; i++)
          {
              totalIdle[i] = arriveTime;
          }
      }
      else if (c > 1) //code for all customers after the first one
      {
          if (prevDepart[m] == 0) //There was no previous customer at current counter
          {
              totalIdle[m] = arriveTime;

              for (int i = 1; i <= n; i++)
              {
                  if (i == m) //skip over current counter
                    continue;

                  if (prevDepart[i] == 0) //There was no previous customer at this counter
                    totalIdle[i] = arriveTime;
                  else
                  {
                     if (arriveTime > prevDepart[i])
                     {
                        totalIdle[i] += arriveTime - prevDepart[i]; //time between last customer served and arrival of new customer
                     }
                  }
              } //end for
          } //end prevDepart = 0 if
          else //if there was a customer at this counter before
          {
            idleTime = startServe - prevDepart[m];
            totalIdle[m] += idleTime;

            for (int i = 1; i <= n; i++)
              {
                  if (i == m) //skip over current counter
                    continue;

                  if (prevDepart[i] == 0) //if counter has no previous depart time, assign arrive time to total idle time
                    totalIdle[i] = arriveTime;
                  else
                  {
                     if (arriveTime > prevDepart[i])
                     {
                        totalIdle[i] += arriveTime - prevDepart[i]; //time between last customer served and arrival of new customer
                     }
                  }
              } //end for
          } //end if
      }

      prevDepart[m] = depart[m];

      printf("%5d %8d %7d %6d %7d %8d %5d\n",
         c, arriveTime, startServe, m, serveTime, depart[m], waitTime);
   } //end for

   averageWait = totalWaitTime / numCust;
   printf("\nThe average wait time is %d\n\n", averageWait);

   printf("The total idle time for counters\n\n");
   for (int c = 1; c <= n; c++)
   {
       printf("Counter %d: %d\n", c, totalIdle[c]);
   }

    return 0;
} //end main

int smallest(int list[], int lo, int hi) {
//returns the subscript of the smallest value in list
   int k = lo;
   for (int h = lo + 1; h <= hi; h++)
      if (list[h] < list[k]) k = h;
   return k;
} //end smallest

int max(int a, int b) {
   if (a > b) return a;
   return b;
} //end max

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random

