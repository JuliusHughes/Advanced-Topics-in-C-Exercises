//Print an integer with commas separating the thousands
#include <stdio.h>
#include <stdlib.h>

void print_commas(long n);

int main()
{
    long n = 1200001;

    print_commas(n);

    return 0;
}

void print_commas(long n)
{
    if (n < 1000)
    {
        printf("%d", n);
        return;
    }
        print_commas(n/1000);
        printf(",%03d", n % 1000);
}
