//Advanced Topics in C: Chapter 2 Exercise 5
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int month;
    int day;
    int year;
} Date;

int validMonth(Date d);
int validDay(Date d);
int validYear(Date d);
int whenDate(Date d1, Date d2); //function determines when d1 occurs in comparison to d2

int main()
{
    Date d1;
    d1.month = 2;
    d1.day = 28;
    d1.year = 2014;

    Date d2;
    d2.month = 10;
    d2.day = 31;
    d2.year = 2014;

    printf("Date 1: %d/%d/%d\n", d1.month, d1.day, d1.year);
    printf("Date 2: %d/%d/%d\n\n", d2.month, d2.day, d2.year);

    int when = whenDate(d1, d2);
    if (when == -1)
        printf("Date 1 comes before Date 2.\n");
    else if (when == 1)
        printf("Date 1 comes after Date 2.\n");
    else if (when == 0)
        printf("Date 1 and Date 2 are the same.\n");
    else if (when == -2)
        printf("One of the dates is invalid.\n");

    return 0;
}

int validMonth(Date d)
{
    if (d.month > 0 && d.month <= 12)
        return 1;
    else
        return -1;
}

int validDay(Date d)
{
    if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12)
    {
        if (d.day > 0 && d.day <= 31)
            return 1;
        else
            return -1;
    }
    else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
    {
        if (d.day > 0 && d.day <= 30)
            return 1;
        else
            return -1;
    }
    else if (d.month == 2)
    {
        if (d.day > 0 && d.day <= 28)
            return 1;
        else
            return -1;
    }
    else
        return -1;
}

int validYear(Date d)
{
    if (d.year >= 1900 && d.year <= 2025)
        return 1;
    else
        return -1;
}

int whenDate(Date d1, Date d2)
{
    if (validMonth(d1) == -1 || validDay(d1) == -1 || validYear(d1) == -1)
        return -2; //returns -2 if one of the dates are invalid

    if (validMonth(d2) == -1 || validDay(d2) == -1 || validYear(d2) == -1)
        return -2;

    if (d1.year > d2.year)
        return 1;
    else if (d1.year < d2.year)
        return -1;
    else if (d1.year == d2.year)
    {
        if (d1.month > d2.month)
            return 1;
        else if (d1.month < d2.month)
            return -1;
        else if (d1.month == d2.month)
        {
            if (d1.day > d2.day)
                return 1;
            else if (d1.day < d2.day)
                return -1;
            else if (d1.day == d2.day)
                return 0;
        }
    }
}
