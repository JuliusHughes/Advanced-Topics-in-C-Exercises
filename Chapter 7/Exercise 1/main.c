//Write a program to request two numbers, m and n, and print 25 random numbers from m to n

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int n);

int main()
{
    int m, n,num;

    srand(time(0));

    printf("Enter a number for m: ");
    scanf("%d", &m);

    printf("Enter a number for n (must be larger than m): ");
    scanf("%d", &n);

    if (m > n)
        n += 5;

    for (int i = 0; i < 25; i++)
    {
        num = random(m, n);
        printf("%d ", num);
    }

    return 0;
}

int random(int m, int n)
{
    //retrieves a random number between m and n

    int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
    return m + offset;
}
