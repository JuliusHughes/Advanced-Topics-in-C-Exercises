/*
    Write a function that takes three arguments: a pointer to a linked list of integers and two integers, n and j, and inserts
    n after the jth element of the list.  If j is 0, n is inserted at the head of the list.  If j is greater than the number
    of elements in the list, n is inserted after the last one.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} *Node;

Node makeNode(int n);
void insertNode(Node top, int n, int j);
void printList(Node top);

int main()
{
    int n;
    Node top, np;

    top = NULL;

    printf("Enter a number for a node in the linked list (enter 0 to quit): ");
    if (scanf("%d", &n) != 1)
        n = 0;

    while (n != 0)
    {
        np = makeNode(n);
        np->next = top;
        top = np;
        printf("Enter a number for a node in the linked list (enter 0 to quit): ");
        if (scanf("%d", &n) != 1)
            n = 0;
    }

    printf("List: ");
    printList(top);

    int j;
    printf("\nEnter a positive number for j: ");
    if (scanf("%d", &j) != 1)
        j = 0;

    printf("\nEnter a number to enter after %d element: ", j);
    if (scanf("%d", &n) != 1)
        n = 0;

    insertNode(top, n, j);
    printList(top);

    return 0;
}

Node makeNode(int n)
{
    Node np = (Node) malloc(sizeof(Node));
    np->data = n;
    np->next = NULL;
    return np;
}

void insertNode(Node top, int n, int j)
{
    //This function inserts n after the jth element of the list. If j is 0, n is inserted at the head of the list.
    //If j is greater than the number of elements in the list, n is inserted after the last one

    int m = 0; //counter for number of elements in the linked list
    Node np, prev, curr, makeNode(int);
    np = makeNode(n);
    prev = NULL;

    if (j < 0)
        j = 0;

    while (top != NULL)
    {
        if (j == 0) //insert n at the head of the list
        {
            np->next = top;
            top = np;
        }

        prev = top;
        ++m;

        if (m == j) //insert n after the jth element
        {
            np->next = prev->next;
            prev->next = np;
        }

        top = top->next;
    }

    if (j > m) //insert n after the jth element
    {
        np->next = prev->next;
        prev->next = np;
    }
}

void printList(Node top)
{
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
}
