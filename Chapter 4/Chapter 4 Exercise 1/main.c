/*
    Write a function that, given a pointer to a linked list of integers, returns 1 if the list is sorted
    in ascending order and returns 0 otherwise

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} *Node;

Node makeNode(int n);
Node addInPlace(Node top, int n);
void printList(Node np);
int isSorted(Node top);

int main()
{
    Node top1, top2, np, last;
    int n = 0;

    top1 = NULL;
    top2 = NULL;

    printf("Enter a number for a node in list 1 (enter 0 to exit): ");
    if (scanf("%d", &n) != 1)
        n = 0;

    while (n != 0)
    {
        top1 = addInPlace(top1, n);
        printf("Enter a number for a node in list 1 (enter 0 to exit): ");
        if (scanf("%d", &n) != 1)
            n = 0;
    }

    printf("Enter a number for a node in list 2 (enter 0 to exit): ");
    if (scanf("%d", &n) != 1)
        n = 0;

    while (n != 0)
    {
        np = makeNode(n);
        if (top2 == NULL)
            top2 = np;
        else
            last->next = np;
        last = np;
        printf("Enter a number for a node in list 1 (enter 0 to exit): ");
        if (scanf("%d", &n) != 1)
            n = 0;
    }

    printf("\nList 1: ");
    printList(top1);
    printf("\nList 2: ");
    printList(top2);

    if (isSorted(top1) == 1)
        printf("\nList 1 is sorted.\n");
    else
        printf("List 1 isn't sorted.\n");

    if (isSorted(top2) == 1)
        printf("List 2 is sorted.\n");
    else
        printf("List 2 isn't sorted.\n");


    return 0;
}

Node makeNode(int n)
{
    Node np = (Node) malloc(sizeof(Node));
    np->data = n;
    np->next = NULL;
    return np;
}

Node addInPlace(Node top, int n)
{
    //Sorts linked list in ascending order
    //places item in its proper position
    Node np, prev, curr, makeNode(int);

    np = makeNode(n);
    prev = NULL;
    curr = top;

    while (curr != NULL && n > curr->data)
    {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL)
    {
        np->next = top;
        return np; //the top has changed to the new node
    }

    //insert the new node between the previous node and the current one
    np->next = curr;
    prev->next = np;
    return top; //the top didn't change changed
}

int isSorted(Node top)
{
    //function returns 1 if the list is sorted in ascending order and returns 0 otherwise

    Node prev, curr;
    prev = NULL;
    curr = top;

    while (curr != NULL)
    {
        if (prev == NULL)
        {
            prev = curr;
            curr = curr->next;
            continue;
        }

        if (prev->data > curr->data)
            return 0;

        prev = curr;
        curr = curr->next;
    }

    return 1;
}

void printList(Node np)
{
    while (np != NULL)
    {
        printf("%d ", np->data);
        np = np->next;
    }
}
