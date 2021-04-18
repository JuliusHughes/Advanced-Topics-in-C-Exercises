/*
    A length, specified in meters and centimeters, is represented by two integers. For example,
    the length 3m 75c, is represented by 3 75. Using a structure to represent a length, write
    functions to compare, add, and subtract two lengths.

*/

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int meters;
    int centimeters;
} Length;

int compare(Length j1, Length j2);
Length add(Length j1, Length j2);
Length subtract(Length j1, Length j2);

int main()
{
    Length j1;
    j1.meters = 4;
    j1.centimeters = 65;

    Length j2;
    j2.meters = 3;
    j2.centimeters = 75;

    printf("Length 1: %d m %d cm\nLength 2: %d m %d cm\n\n", j1.meters, j1.centimeters, j2.meters, j2.centimeters);

    int cmp = compare(j1, j2);
    if (cmp == 1)
        printf("Length 1 is greater than length 2.\n\n");
    else if (cmp == -1)
        printf("Length 1 is less than length 2.\n\n");
    else
        printf("Both lengths are the same.\n\n");

    Length sum;
    sum = add(j1, j2);
    printf("Sum of both lengths: %d m %d cm\n", sum.meters, sum.centimeters);

    Length diff;
    diff = subtract(j1, j2);
    printf("Difference between both lengths: %d m %d cm\n", diff.meters, diff.centimeters);

    return 0;
}

int compare(Length j1, Length j2)
{
    //function returns 1 if j1 > j2, -1 if j1 < j2, and 0 if j1 ==j2

    if (j1.meters > j2.meters)
        return 1;
    else if (j1.meters < j2.meters)
        return -1;
    else
    {
        if (j1.centimeters > j2.centimeters)
            return 1;
        else if (j1.centimeters < j2.centimeters)
            return -1;
        else
            return 0;
    }
}

Length add(Length j1, Length j2)
{
    //function adds both Lengths and returns the sum

    Length temp; //used to store the sum
    temp.meters = j1.meters + j2.meters;
    temp.centimeters = j2.centimeters + j1.centimeters;
    if (temp.centimeters >= 100) //carry the one to meters, and the remainder is the centimeters
    {
        temp.centimeters = temp.centimeters - 100;
        ++temp.meters;
    }

    return temp;
}

Length subtract(Length j1, Length j2)
{
    //function subtracts both Lengths

    Length temp; //used to store the difference
    if (j1.meters > j2.meters)
    {
        temp.meters = j1.meters - j2.meters;
        if (j1.centimeters < j2.centimeters)
        {
            temp.centimeters = 100 - (j2.centimeters - j1.centimeters);
            --temp.meters;
        }
        else
            temp.centimeters = j1.centimeters - j2.centimeters;
    }
    else if (j1.meters < j2.meters)
    {
        temp.meters = j2.meters - j1.meters;
        if (j2.centimeters < j1.centimeters)
        {
            temp.centimeters = 100 - (j1.centimeters - j2.centimeters);
            --temp.meters;
        }
        else
            temp.centimeters = j2.centimeters - j1.centimeters;
    }
    else
    {
        if (j1.centimeters > j2.centimeters)
        {
            temp.meters = j1.meters - j2.meters;
            temp.centimeters = j1.centimeters - j2.centimeters;
        }
        else
        {
            temp.meters = j1.meters - j2.meters;
            temp.centimeters = j2.centimeters - j1.centimeters;
        }
    }

    return temp;
}
