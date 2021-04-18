#include <stdio.h>
#include <stdlib.h>

double interval(int a, int b, double (*fp)(double));
double quadratic(double x);

int main()
{
    int a = 1;
    int b = 2;
    double y;

    y = interval(a, b, quadratic);

    printf("For the equation 5x2 + 3x - 14, f(c) = 0 when c is %f\n", y);

    return 0;
}

double interval(int a, int b, double (*fp)(double))
{
    double c = a;
    double temp;

    while (c < b)
    {
        temp = (*fp)(c);
        if (temp > 0.0)
            break;
        else
            c += .01;
    }

    return c;
}

double quadratic (double x)
{
    return (5 * x * x) + (3 * x) - 14;
}
