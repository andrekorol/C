#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h>

#include "wordlength.h"
#include "stringtools.h"

// bitcount: count 1 bits in x
int bitcount(unsigned x);

int main()
{
    unsigned x;
    char *x_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    int b;

    printf("Enter x:\n");
    scanf("%u", &x);

    utoa(x, x_binary, 2);
    printf("x = %u (%s)\n", x, x_binary);

    b = bitcount(x);
    printf("Number of 1-bits in x = %d\n", b);

    free(x_binary);

    return 0;
}

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x - 1))
        b++;

    return b;
}
