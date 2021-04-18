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
int numOfDayAfter(Date d1, Date d2);

int main()
{
    Date d1;
    d1.month = 5;
    d1.day = 31;
    d1.year = 2012;

    Date d2;
    d2.month = 7;
    d2.day = 31;
    d2.year = 2012;

    printf("Date 1: %d/%d/%d\n", d1.month, d1.day, d1.year);
    printf("Date 2: %d/%d/%d\n\n", d2.month, d2.day, d2.year);

    int num = numOfDayAfter(d1, d2);
    if (num == -1)
        printf("Date 1 comes before Date 2.\n");
    else if (num == 0)
        printf("Date 1 and Date 2 are the same.\n");
    else if (num == -2)
        printf("One of the dates is invalid.\n");
    else
        printf("Date 2 is ahead of Date 1 by %d days", num);


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
        if (d.year % 4 == 0 || d.year % 400 == 0) //leap year
        {
            if (d.day > 0 && d.day <= 29)
                return 1;
            else
                return -1;
        }
        else if (d.year % 100 == 0)
        {
            if (d.day > 0 && d.day <= 28)
                return 1;
            else
                return -1;
        }
        else
        {
            if (d.day > 0 && d.day <= 28)
                return 1;
            else
                return -1;
        }
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

int numOfDayAfter(Date d1, Date d2) //returns number of days d2 is ahead of d1, -1 if d1 is after d2, and 0 if the dates are the same
{
    if (validMonth(d1) == -1 || validDay(d1) == -1 || validYear(d1) == -1)
        return -2; //returns -2 if one of the dates are invalid

    if (validMonth(d2) == -1 || validDay(d2) == -1 || validYear(d2) == -1)
        return -2;

    Date temp;
    temp.day = d1.day;
    temp.month = d1.month;
    temp.year = d1.year;
    int days = 0; //counter for number of days d2 is ahead of d1

    if (d1.year > d2.year)
        return -1;
    else if (d1.year < d2.year)
    {
        while (temp.year != d2.year) //loop stops when d1 is the same as d2
        {
            ++temp.day;
            ++days;
            if (temp.day == 32 && temp.month == 12) //change date to new years day
            {
                ++temp.year; //new year
                temp.month = 1;
                temp.day = 1;
            }
            else if (validDay(temp) == -1) //change month when it's the end of the month
            {
                temp.day = 1;
                ++temp.month;
            }
        }

        while (temp.month != d2.month)
        {
            ++temp.day;
            ++days;
            if (validDay(temp) == -1)
                {
                    temp.day = 1;
                    ++temp.month;
                }
        }

        while (temp.day != d2.day)
        {
            ++temp.day;
            ++days;
        }
    }
    else if (d1.year == d2.year)
    {
        if (d1.month > d2.month)
            return -1;
        else if (d1.month == d2.month)
        {
            if (d1.day > d2.day)
                return -1;
            else if (d1.day == d2.day)
                return 0;
            else if (d1.day < d2.day)
            {
                while (temp.day != d2.day)
                {
                    ++days;
                    ++temp.day;
                }
            }
        }
        else if (d1.month < d2.month)
        {
            while (temp.month != d2.month)
            {
                ++temp.day;
                ++days;
                if (validDay(temp) == -1)
                {
                    temp.day = 1;
                    ++temp.month;
                }
            }

            while (temp.day != d2.day)
            {
                ++temp.day;
                ++days;
            }

        }
    }

    return days;
}
