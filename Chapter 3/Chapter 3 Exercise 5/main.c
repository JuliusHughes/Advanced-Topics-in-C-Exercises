#include <stdio.h>
#include <stdlib.h>

void sum(int a, int b, int * c);

int main()
{
    int a = 7;
    int b = 10;
    int * c;

    sum(a, b, c);

    printf("%d + %d = %d\n", a, b, *c);

    return 0;
}

void sum(int a, int b, int * c)
{
    *c = a + b;
}
