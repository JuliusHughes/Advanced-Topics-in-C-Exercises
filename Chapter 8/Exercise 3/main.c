/*

Write a program to read a binary file of integers, sort the integers, and write them back to
the same file.  Assume that all numbers can be stored in an array.

*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int list[], int n);

int main()
{
    FILE *file1;
    int size = 10;

    if ((file1 = fopen("num1.bin", "w+")) == NULL)
    {
        printf("Cannot open file\n");
        return -1;
    }

    int list[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter an integer: ");
        scanf("%d", &list[i]);
        fwrite(&list[i], sizeof(int), 1, file1);
    }

    fread(list, sizeof(int), 10, file1);

    insertionSort(list, size);

    fwrite(list, sizeof(int), 10, file1);

    fclose(file1);
    return 0;
}

void insertionSort(int list[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = list[i];
        int k = i - 1;
        while (k >= 0 && key < list[k])
        {
            list[k + 1] = list[k];
            --k;
        }

        list[k + 1] = key;
    }
}
