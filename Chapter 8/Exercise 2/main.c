#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *file1, *file2;
    int diff_byte = 0;
    int bin_num1, bin_num2;
    int flag = 1;

    if ((file1 = fopen("num1.bin", "wb+")) == NULL)
    {
        printf("Cannot open the file\n");
        return -1;
    }

    if ((file2 = fopen("num2.bin", "wb+")) == NULL)
    {
        printf("Cannot open the file\n");
        return -1;
    }

    int hi[6];
    printf("\nYou will be asked to enter data for the first binary file\n\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Enter a number to save to the binary file (enter a letter to exit): ");
        scanf("%d", &bin_num1);
        fwrite(&bin_num1, sizeof(int), 1, file1);
        hi[i] = bin_num1;
    }

    for (int i = 0; i < 6; i++)
    {
        fwrite(&hi[i], sizeof(int), 1, file2);
    }

    /*
    printf("\nYou will be asked to enter data for the second binary file\n\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Enter a number to save to the binary file (enter a letter to exit): ");
        scanf("%d", &bin_num2);
        fwrite(&bin_num2, sizeof(int), 1, file2);
    }
    */


    while (ferror(file1) != 1 || ferror(file2) != 1)
    {
        fread(&bin_num1, sizeof(int), 1, file1);
        fread(&bin_num2, sizeof(int), 1, file2);
        ++diff_byte;

        if (bin_num1 != bin_num2)
        {
            flag = 0;
            break;
        }//end if
    } //end while

    if (flag == 1)
        printf("Both files are identical\n\n");
    else if (flag == 0)
    {
        printf("The byte at which these two files differ is byte %d\n\n", diff_byte);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}
