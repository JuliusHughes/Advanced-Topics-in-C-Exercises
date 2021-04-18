//Advanced Topics in C Chapter 1 Exercise 1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MaxWords 10
#define MaxLength 61

int getName(FILE *, char[]);
void printResults(FILE *, int max, char[][max], int[], int);
void insertionSort1(int lo, int hi, int max, char list[][max], int v[]);
void insertionSort2(int lo, int hi, int max, char list[][max], int v[]);

int main()
{
    char artists[MaxWords][MaxLength]; //array of strings to store artists
    char name[MaxLength]; //string used for getName()
    int votes[MaxWords]; //holds number of votes for each artist

    for (int i = 0; i < MaxWords; i++)
        votes[i] = 0;

    FILE * in = fopen("votes.txt", "r");
    if (in == NULL)
    {
        printf("Cannot find file.\n");
        exit(1);
    }

    int count = 0; //used for copying the artist from file to artists array
    int choice = 0; //used to determine which artist the user voted for

    while (getName(in, name) != 0)
    {
        strcpy(artists[count], name);
        ++count;
    }

        printf("\nChoose which artist to vote for\n");
        printf("1: Deftones     2: Lupe     3: Skyzoo       4: Eminem       5: elZhi\n");
        printf("6: Eyedea       7: Nas      8: illmind      9: Rashad       10: Joe Budden\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

    while (choice > 0 && choice <= 10)
    {
        --choice;
        ++votes[choice];

        printf("\nChoose which artist to vote for\n");
        printf("1: Deftones     2: Lupe     3: Skyzoo       4: Eminem       5: elZhi\n");
        printf("6: Eyedea       7: Nas      8: illmind      9: Rashad       10: Joe Budden\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
    }

    FILE * out = fopen("results.txt", "w");
    if (out == NULL)
    {
        printf("Cannot create output file\n");
        exit(2);
    }


    insertionSort1(0, MaxWords - 1, MaxLength, artists, votes);
    printResults(out, MaxLength, artists, votes, MaxWords);

    insertionSort2(0, MaxWords - 1, MaxLength, artists, votes);
    printResults(out, MaxLength, artists, votes, MaxWords);

    return 0;
}

int getName(FILE * in, char str[])
{
    // stores the next artist, if any, in str
    //returns 1 if a name is found.  0 otherwise
    char ch;
    int n = 0;
    while(!isalpha(ch = getc(in)) && ch != EOF); //read over white space
    if (ch == EOF)
        return 0;
    str[n++] = ch;
    while (isalpha(ch = getc(in)) && ch != EOF)
    {
        if (n < MaxLength)
            str[n++] = ch;
    }
    str[n] = '\0';
    return 1;
}

void insertionSort1(int lo, int hi, int max, char list[][max], int v[])
{
    //sort the names in order by number of votes in descending order
    int key1;
    char key2[max];
    for (int h = lo + 1; h < hi; h++)
    {
        key1 = v[h];
        strcpy(key2, list[h]);
        int k = h - 1;
        while (k >= lo && key1 > v[k])
        {
            v[k + 1] = v[k];
            strcpy(list[k + 1], list[k]);
            --k;
        }
        v[k + 1] = key1;
        strcpy(list[k + 1], key2);
    }
}

void insertionSort2(int lo, int hi, int max, char list[][max], int v[])
{
    //sort the names in alphabetical order
    int key1;
    char key2[max];
    for (int h = lo + 1; h < hi; h++)
    {
        key1 = v[h];
        strcpy(key2, list[h]);
        int k = h - 1;
        while (k >= lo && strcmp(key2, list[k]) < 0)
        {
            strcpy(list[k + 1], list[k]);
            v[k + 1] = v[k];
            --k;
        }
        strcpy(list[k + 1], key2);
        v[k + 1] = key1;
    }
}

void printResults(FILE * out, int max, char list[][max], int v[], int n)
{
    fprintf(out, "\nArtists         Votes\n\n");
    for (int h = 0; h < n; h++)
        fprintf(out, "%-15s %2d\n", list[h], v[h]);
}
