//Advanced Topics in C: Chapter 1 Exercise 2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MaxNameLength 61
#define MaxPhoneLength 12
#define MaxPhoneBuffer MaxPhoneLength + 1

int binarySearch(int lo, int hi, char key[], int max, char [][max]);
void insertionSort(int lo, int hi, int max1, char list1[][max1], int max2, char list2[][max2]); // sort phone numbers by name in alphabetical order

int main()
{
    //int num;

    //printf("Enter the number of phone numbers you want to store: ");
    //scanf("%d", &num);

    int stupid_program_error = 2;

    char names[stupid_program_error][MaxNameLength];
    char phone[stupid_program_error][MaxPhoneBuffer];
    char temp[MaxNameLength]; //used for binary search to look up a phone number


    for (int i = 0; i < stupid_program_error; i++)
    {
        printf("Enter name#%d: ", i);
        scanf("%s", names[i]);
    }

    for (int i = 0; i < stupid_program_error; i++)
    {
        printf("%s phone number\n\n", names[i]);
        for (int j = 0; j < MaxPhoneBuffer; j++)
        {
            if (j == 3 || j == 7) // used dashes to make phone number more readable
                phone[i][j] = '-';
            else if (j == 12)
                phone[i][j] = '\0';
            else
            {
                printf("Enter digit#%d: ", j);
                char ch;
                scanf("%s", &ch);
                if (isdigit(ch))
                    phone[i][j] = ch;
                else
                {
                    printf("Try again: ");
                    scanf("%s", &ch);
                }

            }
        }
    }

    insertionSort(0, stupid_program_error, MaxNameLength, names, MaxPhoneBuffer, phone);

    printf("Enter the name of the person who's phone number you want: ");
    scanf("%s", temp);
    int bs1 = binarySearch(0, stupid_program_error, temp, MaxNameLength, names);

    while (bs1 != -1)
    {
        printf("%s's phone number is %s", names[bs1], phone[bs1]);
        printf("\nEnter the name of the person who's phone number you want: ");
        scanf("%s", temp);
        bs1 = binarySearch(0, stupid_program_error, temp, MaxNameLength, names);
    }

    return 0;
}

int binarySearch(int lo, int hi, char key[], int max, char list[][max])
{
    //search for key from list[lo] to list[hi]
    //if found, return its location;
    //if not found, return the location in which it should be inserted

    while(lo <= hi)
    {
        int mid = (lo + hi)/2;
        int cmp = strcmp(key, list[mid]);
        if (cmp == 0)
            return mid; //found
        if (cmp < 0)
            hi = mid - 1; //search lower half of array
        else
            lo = mid + 1; //search upper half of array
    }
    return -1; //lo and hi have crossed.  Key not found
}

void insertionSort(int lo, int hi, int max1, char list1[][max1], int max2, char list2[][max2])
{
    char key1[max1];
    char key2[max2];

    for (int h = lo + 1; h <= hi; h++)
    {
        strcpy(key1, list1[h]); // store the name as the first key
        strcpy(key2, list2[h]); // store the phone number as the second key
        int k = h - 1;
        while (k >= lo && strcmp(key1, list1[k]) < 0)
        {
            strcpy(list1[k + 1], list1[k]);
            strcpy(list2[k + 1], list2[k]); //move phone number when we move a name
            --k;
        }
        strcpy(list1[k + 1], key1);
        strcpy(list2[k + 1], key2); // store the phone number in the same position as the name
    }
}
