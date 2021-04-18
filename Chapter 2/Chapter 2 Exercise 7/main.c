#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int hour;
    int min;
} Time; //24-hour clock format

int validHour(Time t);
int validMin(Time t);
int numOfMins(Time t1, Time t2);

int main()
{
    Time t1;
    t1.hour = 23;
    t1.min = 50;

    Time t2;
    t2.hour = 23;
    t2.min = 56;
    printf("Time 1: %d:%d\nTime 2: %d:%d\n", t1.hour, t1.min, t2.hour, t2.min);

    int num = numOfMins(t1, t2);

    if (num == -2)
        printf("One of the times is invalid.\n");
    else if (num == 0)
        printf("Both times are the same.\n");
    else
        printf("The number of mins between time 1 and time 2 is %d", num);

    return 0;
}

int validHour(Time t)
{
    if (t.hour >= 0 && t.hour <= 23)
        return 1;
    else
        return -1;
}

int validMin(Time t)
{
    if (t.min >= 0 && t.min <= 59)
        return 1;
    else
        return -1;
}

int numOfMins(Time t1, Time t2)
{
    int minutes = 0; //counter for total mins between t1 and t2
    if ((validHour(t1) == -1) || (validMin(t1) == -1))
        return -2; //if time is invalid, return -2
    if (validHour(t2) == -1 || validMin(t2) == -1)
        return -2; //if time is invalid, return -2

    if (t1.hour > t2.hour)
    {
        Time temp; //assign lower time to temp for while loop
        temp.hour = t2.hour;
        temp.min = t2.min;
        while (temp.hour != t1.hour) //increment temp's time by 1 until the hour is the same as t1
        {
            ++minutes;
            ++temp.min;
            if (validMin(temp) == -1) //if the time is invalid, increment the hour and assign 0 to the min
            {
                ++temp.hour;
                temp.min = 0;
            }
        }

        while (temp.min != t1.min) //increment temp's time by 1 until the min is the same as t1
        {
            ++minutes;
            ++temp.min;
        }
    }
    else if (t1.hour == t2.hour)
    {
        if (t1.min > t2.min)
        {
            Time temp; //assign lower time to temp for while loop
            temp.min = t2.min;
            temp.hour = t2.hour;

            while (temp.min != t1.min) //increment temp's time by 1 until the min is the same as t1
            {
                ++minutes;
                ++temp.min;
            }
        }
        else if (t1.min < t2.min)
        {
            Time temp; //assign lower time to temp for while loop
            temp.hour = t1.hour;
            temp.min = t1.min;

            while (temp.min != t2.min) //increment temp's time by 1 until the min is the same as t2
            {
                ++minutes;
                ++temp.min;
            }
        }
        else
            return 0;
    }
    else
    {
        Time temp;
        temp.hour = t1.hour;
        temp.min = t1.min;

        while (temp.hour != t2.hour) //increment temp's time by 1 until the hour is the same as t2
        {
            ++minutes;
            ++temp.min;
            if (validMin(temp) == -1) //if the time is invalid, increment the hour and assign 0 to the min
            {
                ++temp.hour;
                temp.min = 0;
            }
        }

        while (temp.min != t2.min) //increment temp's time by 1 until the min is the same as t2
        {
            ++minutes;
            ++temp.min;
        }
    }

    return minutes;
}
