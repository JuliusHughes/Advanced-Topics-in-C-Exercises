#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *in, *out;
    int limit = 100;
    int limit2 = 0;
    char temp[limit];
    char temp2[limit];
    char ch;


    if ((in == fopen("file1.txt", "r")) == NULL)
    {
        printf("Cannot open file\n");
        return -1;
    }

    if ((out == fopen("file2.txt", "w+")) == NULL)
    {
        printf("Cannot create file\n");
        return -1;
    }

    while (fscanf(in, "%c", ch) == 1)
    {
        for (int i = 0; i <= limit; i++)
        {
            if ((limit2 > 0 && limit2 <= i) || (limit2 == 0))
            {
                temp[i] = ch;
                if ((i == limit) && ((!(isspace(temp[i])) || (!(ispunct(temp[i]))))))
                {
                    for (int j = limit; j >= 0; j--)
                    {
                        if (!(isspace(temp[j])) && !(ispunct(temp[j])))
                        {
                            temp2[count] = temp[j];
                            ++count;
                        } //end if
                    } //end for j
                }
                else
                {
                    limit2 = count;
                    fwrite(temp, sizeof(char), limit, fp);
                    strcpy(temp, temp2);
                } //end else
            } //end if
        }//end for i
    } //end while

    return 0;
}
