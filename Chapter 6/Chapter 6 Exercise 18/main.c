/*
Consider points (m, n) in the usual Cartesian coordinate system where m and n positive integers.  In a north-east path from
point A to point B, one can move only up and only right (no down or left movements are allowed). Write a function that,
given the coordinates of any two points A and B, returns the number of north-east paths from A to B

*/
#include <stdio.h>
#include <stdlib.h>

int north_east(int i, int j, int m, int n);

int main()
{
    int i, j, m, n;
    int sum = 0;

    printf("Enter a positive integer for x-coordinate for A: ");
    scanf("%d", &i);

    printf("Enter a positive integer for y-coordinate for A: ");
    scanf("%d", &j);

    printf("Enter a positive integer for x-coordinate for B (Must be larger than A): ");
    scanf("%d", &m);

    printf("Enter a positive integer for y-coordinate for B(Must be larger than A): ");
    scanf("%d", &n);

    if (i > m)
        m = i + 1;

    if (j > n)
        n = j + 1;

    sum = north_east(i, j, m, n);
    printf("Number of north east paths from A to B is %d\n", sum);

    return 0;
}

static int total = 0;
int north_east(int i, int j, int m, int n)
{

    if (i == m || j == n)
        return 1;

    if (i < m)
        north_east(i + 1, j, m, n);

    if (j < n)
        north_east(i, j + 1, m, n);

    ++total;

    return total + 1;
}
