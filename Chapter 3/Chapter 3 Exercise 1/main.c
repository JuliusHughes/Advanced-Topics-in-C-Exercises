/*
    In main, there are two int variables, a and b,  Write a function that, when called, interchanges the values
    of a and b so that the change is known in main.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b);

int main()
{
    int num1 = 6;
    int num2 = 8;

    int * a = &num1;
    int * b = &num2;

    printf("Before the swap\n a: %d\n b: %d\n\n", *a, *b);
    swap(a, b);
    printf("After the swap\n a: %d\n b: %d\n\n", *a, *b);

    return 0;
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
