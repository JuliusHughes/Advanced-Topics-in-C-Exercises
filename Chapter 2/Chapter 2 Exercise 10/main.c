/*
    A file contains the names and distances jumped by athletes in a long-jump competition. Using a structure to hold
    a name and distance (which is itself a structure as in 8), write a program to read the data and print a list of
    names and distance jumped in order of merit (best jumper first).

*/

#include <stdio.h>
#include <stdlib.h>

#define MaxAthletes 7
#define MaxNameBuffer 90

typedef struct
{
    int meters;
    int centimeters;
} Length;

typedef struct
{
    char name[MaxNameBuffer];
    Length distance;
} Jumper;

void sortByDistance(Jumper athletes[], int max, char list[][max], int lo, int hi);
void printResults(Jumper athletes[], int max1, int max2, char list[][max2]);

int main()
{
    FILE * in = fopen("jumpers.txt", "r");
    if (in == NULL)
    {
        printf("Cannot find file.\n");
        exit(1);
    }

    Jumper athletes[MaxAthletes];
    char names[MaxAthletes][MaxNameBuffer];

    for (int i = 0; i < MaxAthletes; i++)
        fscanf(in, "%s", names[i]); //storing the names of athletes in the names array

    for (int i = 0; i < MaxAthletes; i++) //storing the distance in the athletes array
    {
        fscanf(in, "%d", &athletes[i].distance.meters);
        fscanf(in, "%d", &athletes[i].distance.centimeters);
    }

    sortByDistance(athletes, MaxNameBuffer, names, 0, MaxAthletes);
    printResults(athletes, MaxAthletes, MaxNameBuffer, names);

    fclose(in);

    return 0;
}

void sortByDistance(Jumper athletes[], int max, char list[][max], int lo, int hi)
{
    //sort the distances in athletes[lo] to athletes[hi] descending order

    char key2[MaxNameBuffer];
    for (int i = lo + 1; i < hi; i++)
    {
        Jumper key1 = athletes[i];
        strcpy(key2, list[i]);
        int k = i - 1;
        while (k >= lo && (key1.distance.meters > athletes[k].distance.meters))
        {
            athletes[k + 1] = athletes[k];
            strcpy(list[k + 1], list[k]);
            --k;
        }
        athletes[k + 1] = key1;
        strcpy(list[k + 1], key2);
    }
}

void printResults(Jumper athletes[], int max1, int max2, char list[][max2])
{
    printf("\nJumper        Distance\n\n");

    for (int i = 0; i < max1; i++)
    {
        printf("%-15s %3d m  %d cm", list[i], athletes[i].distance.meters, athletes[i].distance.centimeters);
    }
}
