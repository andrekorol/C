#include <stdio.h>
#include <stdlib.h>

#include "stringtools.h"

/* getbits: get n bits from position p */
int getbits(int, int, int);

int main()
{
    int x, fields;
    int p, n;
    size_t bits = 8 * sizeof(int *);
    char x_binary[bits + 1];
    char fields_binary[bits + 1];

    printf("Enter an unsigned integer:\n");
    scanf("%d", &x);
    itoa(x, x_binary, 2);

    printf("Enter the number of bit fields that you want to get from %u (%s):\n", x, x_binary);
    scanf("%d", &n);
    printf("Enter the starting position at %d (%s) to get the %d-bit fields from:\n", x, x_binary, n);
    scanf("%d", &p);

    fields = getbits(x, p, n);
    itoa(fields, fields_binary, 2);

    printf("The right adjusted %d-bit field of %d (%s) that begins at position %d is: %u (%s)\n",
            n, x, x_binary, p, fields, fields_binary);
    
    char buffer[bits + 1];
    itoa(fields, buffer, 2);
    printf("%s\n", buffer);
    
    return 0;
}

int getbits(int x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
