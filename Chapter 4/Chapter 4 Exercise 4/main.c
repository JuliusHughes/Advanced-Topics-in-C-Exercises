#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} *Node;

Node makeNode(int n);
void freeNodes(Node top);
void printList(Node top);

int main()
{
    int n;
    Node top, np;

    top = NULL;

    printf("Enter a number to put in linked list (enter 0 to quit): ");
    if (scanf("%d", &n) != 1)
        n = 0;

    while (n != 0)
    {
        np = makeNode(n);
        np->next = top;
        top = np;
        printf("Enter a number to put in linked list (enter 0 to quit): ");
        if (scanf("%d", &n) != 1)
            n = 0;
    }

    printList(top);
    freeNodes(top);

    return 0;
}

Node makeNode(int n)
{
    Node np = (Node) malloc(sizeof(Node));
    np->data = n;
    np->next = NULL;
}

void printList(Node top)
{
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
}

void freeNodes(Node top)
{
    Node old;

    while (top != NULL)
    {
        old = top;
        top = top->next;
        free(old);
    }

    printf("\nAll of the nodes have been freed.\n");
}
