//Write an iterative function to return the nth Fibonacci number
#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main()
{
    int n, result;

    printf("Enter an integer for Fibonacci number: ");
    scanf("%d", &n);

    result = fib(n);

    printf("The %d Fibonacci number is %d\n", n, result);

    return 0;
}

int fib(int n)
{
    int prev1, prev2;
    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            prev1 = 1;
        }
        else if (i == 1)
        {
            prev2 = 1;
        }
        else
        {
            sum = prev1 + prev2;
            prev1 = prev2;
            prev2 = sum;
        }
    }

    return sum;
}
