#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int n);

int main()
{
    int direction_1 = 0, direction_2 = 0, cars1 = 0, cars2 = 0, leaving_cars1 = 0, leaving_cars2 = 0;
    int traffic_light = 1; //1 = stop, 2 = go

    //30 minute simulation
    for (int i = 0; i < 30; i++)
    {
        cars1 = random(5, 15);
        cars2 = random(10, 30);
        direction_1 += cars1; //add to total amount of cars in direction 1
        direction_2 += cars2; //add to total amount of cars in direction 2

        printf("\nCycle %d\n Red Light: \n", i + 1);
        printf("Direction 1: %d\n", direction_1);
        printf("Direction 2: %d\n\n", direction_2);

        traffic_light = 2; //change traffic light to green after 30 seconds
        leaving_cars1 = random(10, 20); //number of cars to leave direction 1
        leaving_cars2 = random(15, 30); //number of cars to leave direction 2

        if (leaving_cars1 >= direction_1)
            direction_1 = 0;
        else
            direction_1 = direction_1 - leaving_cars1;

        if (leaving_cars2 >= direction_2)
            direction_2 = 0;
        else
            direction_2 = direction_2 - leaving_cars2;

        printf("\n Green Light: \n");
        printf("Direction 1: %d\n", direction_1);
        printf("Direction 2: %d\n\n", direction_2);
        traffic_light = 1; //changes light back to red
    }

    return 0;
}

int random(int m, int n) {
//returns a random integer from m to n, inclusive
   int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
   return m + offset;
} //end random
