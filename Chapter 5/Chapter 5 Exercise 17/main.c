//Show how to implement a stack using two queues
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int n;
    Stack S = initStack();

    printf("Enter an integer to add to the stack: ");
    scanf("%d", &n);
    while (n != 0)
    {
        push(S, n);
        printf("Enter an integer to add to the stack: ");
        scanf("%d", &n);
    }

    printf("\nNumbers in reverse order\n");
    while (!emptyStack(S))
        printf("%d ", pop(S));
    printf("\n");


    return 0;
}
