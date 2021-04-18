#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} *Node;

Node makeNode(int n);
void printList(Node np);

int main()
{
    int n;
    Node top, prev, last, np, curr;
    top = NULL;
    prev = NULL;


    printf("Enter a number (enter 0 to quit): ");
    if (scanf("%d", &n) != 1)
        n = 0;
    while (n != 0)
    {
        np = makeNode(n);
        if (top == NULL)
            top = np;
        else
            last->next = np;
        last = np;

        printf("Enter a number (enter 0 to quit): ");
        if (scanf("%d", &n) != 1)
            n = 0;
    }

    printf("List in order: ");
    printList(top);

    curr = top;

    while (curr != NULL)
    {
        Node next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    top = prev;
    printf("List in reverse order: ");
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

void printList(Node np)
{
    while (np != NULL)
    {
        printf("%d ", np->data);
        np = np->next;
    }
}
