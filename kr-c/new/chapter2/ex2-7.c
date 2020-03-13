#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h>

#include "wordlength.h"
#include "stringtools.h"

// invert: inverts the n bits of x that begin at position p
unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned x, r;
    int p, n;
    char *x_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    char *r_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    int max_uint_digits = floor(log10(UINT_MAX)) + 1;

    printf("Enter x:\n");
    scanf("%u", &x);
    printf("Enter p:\n");
    scanf("%d", &p);
    printf("Enter n:\n");
    scanf("%d", &n);

    utoa(x, x_binary, 2);
    left_zeropad_string(x_binary, (size_t) wordlength());
    printf("x = %*u (%s)\n", max_uint_digits, x, x_binary);

    r = invert(x, p, n);
    utoa(r, r_binary, 2);
    left_zeropad_string(r_binary, (size_t) wordlength());
    printf("r = %*u (%s)\n", max_uint_digits, r, r_binary);

    free(x_binary);
    free(r_binary);

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned all_ones = ~0;

    return x ^ (~(all_ones << n) << (p + 1 -n));
}
