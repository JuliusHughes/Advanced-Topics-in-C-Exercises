#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char ch;
    struct node * next;
} *Node;

int isAnagram(Node w1, Node w2);
Node makeNode(char ch);

int main()
{
    char w1[90];
    char w2[90];

    Node top1, top2, last1, last2, np;

    top1 = NULL;
    top2 = NULL;


    printf("Enter two words to see it if they're anagrams.\n\n");

    printf("Enter word 1: ");
    scanf("%s", w1);

    printf("Enter word 2: ");
    scanf("%s", w2);

    for(int i = 0; i < strlen(w1); i++)
    {
        np = makeNode(w1[i]);
        if (top1 == NULL)
            top1 = np;
        else
            last1->next = np;
        last1 = np;
    }

    for(int i = 0; i < strlen(w2); i++)
    {
        np = makeNode(w2[i]);
        if (top2 == NULL)
            top2 = np;
        else
            last2->next = np;
        last2 = np;
    }

    int j = isAnagram(top1, top2);

    if (j == 0)
        printf("These words aren't anagrams.\n");
    else
        printf("These words are anagrams.\n");

    return 0;
}

int isAnagram(Node w1, Node w2)
{
    //This function returns 1 if the words are anagrams and 0 if they're not
    //For each letter in w1, search w2 for it; if found, delete it and continue.  Otherwise return 0.

    Node prev = NULL;
    int n = 0; //counter for number of characters in w2
    int j = 0; //counter for number of characters in w1
    int h; //keeps track of which node in w2 we're in
    Node old; //used to free space occupied by top node

    while (w1 != NULL)
    {
        ++j;
        w1 = w1->next;
    }

    while (w2 != NULL)
    {
        ++n;
        w2 = w2->next;
    }

    if (j != n)
        return 0; //can't be anagram if length isn't the same

    while (w1 != NULL)
    {
        h = 0;
        while (w2 != NULL)
        {
            prev = w2;
            if (w1->ch == w2->ch)
            {
                if (h == 0) //delete the head of w2 list
                {
                    old = w2;
                    w2 = w2->next;
                    free(old);
                    --n;
                    break;
                }
                else
                {
                    prev->next = w2->next;
                    free(w2);
                    --n;
                    break;
                }
            }

            w2 = w2->next;
        }

        w1 = w1->next;
    }

    if (n != 0)
        return 0;
    else
        return 1;
}

Node makeNode(char ch)
{
    Node np = (Node) malloc(sizeof(ch));
    np->ch = ch;
    np->next = NULL;
    return np;
}
