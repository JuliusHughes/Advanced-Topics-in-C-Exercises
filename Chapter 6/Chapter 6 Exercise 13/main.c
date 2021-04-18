#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} *NodePtr, Node;

NodePtr makeNode(int n);
int sum(NodePtr top);

int main()
{
    NodePtr top, np, last;
    int n;

    top = NULL;
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

    int num = sum(top);
    printf("The sum of the items in the list is %d\n", num);

    return 0;
}

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->data = n;
    np->next = NULL;
    return np;
}

int sum(NodePtr top)
{
    int total = 0;

    if (top == NULL)
        return total;

    total = sum(top->next);
    total += top->data;

    return total;
}

