#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h>

#include "wordlength.h"
#include "stringtools.h"

// setbits: set n bits of x at position p with bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned x, y, r;
    int p, n;
    char *x_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    char *y_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    char *r_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    int max_uint_digits = floor(log10(UINT_MAX)) + 1;

    printf("Enter x:\n");
    scanf("%u", &x);
    printf("Enter p:\n");
    scanf("%d", &p);
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Enter y:\n");
    scanf("%u", &y);

    utoa(x, x_binary, 2);
    left_zeropad_string(x_binary, (size_t) wordlength());
    printf("x = %*u (%s)\n", max_uint_digits, x, x_binary);

    utoa(y, y_binary, 2);
    left_zeropad_string(y_binary, (size_t) wordlength());
    printf("y = %*u (%s)\n", max_uint_digits, y, y_binary);

    r = setbits(x, p, n, y);
    utoa(r, r_binary, 2);
    left_zeropad_string(r_binary, (size_t) wordlength());
    printf("r = %*u (%s)\n", max_uint_digits, r, r_binary);

    free(x_binary);
    free(y_binary);
    free(r_binary);

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned all_ones = ~0;

    return (x & ~(~(all_ones << n) << (p + 1 - n))) |
           ((y & ~(all_ones << n)) << (p + 1 - n));
}
