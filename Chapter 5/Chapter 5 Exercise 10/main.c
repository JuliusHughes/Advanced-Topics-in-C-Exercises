//Write declarations/functions to implement a stack of double values

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main()
{
    double n;
    int m = 0; //number of elements in the Stack

    Stack S = initStack();

    printf("Enter a floating point number to add to the stack (enter 0 to quit): ");
    scanf("%lg", &n);

    while (m != 3)
    {
        push(S, n);
        ++m;
        printf("Enter a floating point number to add to the stack (enter 0 to quit): ");
        scanf("%lg", &n);
    }

    printf("\nNumbers in reverse order\n");
    while (!empty(S))
    {
        printf("%lg ", pop(S));
    }

    printf("\n");

    return 0;
}

