#include <stdio.h>
#include <stdlib.h>
#define MaxNumbers 10

int search_num(int list[], int n, int key);

int main()
{
    int num[MaxNumbers];
    printf("Type up to %d numbers followed by 0\n", MaxNumbers);
    int n = 0, v;
    scanf("%d", &v);

    while (v != 0 && n < MaxNumbers)
    {
        num[n++] = v;
        scanf("%d", &v);
    }

    if (v != 0)
    {
        printf("More than %d numbers entered.\n", MaxNumbers);
        printf("First %d used\n", MaxNumbers);
    }

    printf("Enter a number to search for: ");
    int item;
    scanf("%d", &item);
    int j = search_num(num, n - 1, item);

    if (j == -1)
        printf("%d not found.\n", item);
    else
        printf("%d found at location %d. \n", item, j);

    return 0;
}

int search_num(int list[], int n, int key)
{
    int found = -1;

    if (n < 0)
        return found;

    found = search_num(list, n - 1, key);
    if (list[n] == key)
    {
        found = n;
        return found;
    }

    return found; //returns -1 if value not found
}
