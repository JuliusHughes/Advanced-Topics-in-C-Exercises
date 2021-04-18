/*
Write a recursive function that, given a pointer to the head of a linked list of integers, returns 1 if
the list is in ascending order and 0 if it is not.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} *NodePtr, Node;

NodePtr makeNode(int n);
int in_order(NodePtr top);

int main()
{
    NodePtr top, np, last;
    int n;

    top = NULL;
    last = NULL;
    printf("Enter a number to add to the linked list: ");
    if (scanf("%d", &n) != 1)
        n = 0;
    while (n != 0)
    {
        np = makeNode(n); //create a new node containing n
        if (top == NULL) //set top if first node
            top = np;
        else
            last->next = np; //set last->next for other nodes
        last = np; //update last to new node

        printf("Enter a number to add to the linked list: ");
        if (scanf("%d", &n) != 1)
            n = 0;
    }

    int l = in_order(top);
    if (l == 1)
        printf("This list is sorted in ascending order.\n");
    else
        printf("This list is not sorted in ascending order.\n");

    return 0;
}

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->data = n;
    np->next = NULL;
    return np;
}

static int n = 0, j = 0; //n = the total number of items and j checks if the list in in ascending order
static NodePtr prev = NULL;

int in_order(NodePtr top)
{
    int sorted;

    if (top == NULL)
        return 0;

    sorted = in_order(top->next);

    if (n == 0)
    {
        prev = top;
        ++n;
        ++j;
    }
    else if(n > 0 && top->data < prev->data)
    {
        ++n;
        ++j;
        prev = top;
    }
    else if(n > 0 && top->data > prev->data)
    {
        ++n;
        prev = top;
    }

    if (n == j)
    {
        sorted = 1;
    }
    else if (n != j)
    {
        sorted = 0;
    }

    return sorted;
}
