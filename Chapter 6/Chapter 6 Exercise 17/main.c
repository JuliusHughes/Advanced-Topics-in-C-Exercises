//Write a recursive function that takes an integer argument and prints the integer with one space after each digit.
//For example, given 7583, it prints 7 5 8 3
#include <stdio.h>
#include <stdlib.h>

void print_space_int(int n);

int main()
{
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    print_space_int(n);

    return 0;
}

void print_space_int(int n)
{
    if (n < 10)
    {
        printf("%d ", n);
        return;
    }

    print_space_int(n/10);
    printf("%d ", n % 10);
}
