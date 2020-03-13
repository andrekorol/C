#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h>

#include "wordlength.h"
#include "stringtools.h"

// rightrot: rotate x to the right by n positions
unsigned rightrot(unsigned x, int n);

int main()
{
    unsigned x, r;
    int n;
    char *x_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    char *r_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    int max_uint_digits = floor(log10(UINT_MAX)) + 1;

    printf("Enter x:\n");
    scanf("%u", &x);
    printf("Enter n:\n");
    scanf("%d", &n);

    utoa(x, x_binary, 2);
    left_zeropad_string(x_binary, (size_t) wordlength());
    printf("x = %*u (%s)\n", max_uint_digits, x, x_binary);

    r = rightrot(x, n);
    utoa(r, r_binary, 2);
    left_zeropad_string(r_binary, (size_t) wordlength());
    printf("r = %*u (%s)\n", max_uint_digits, r, r_binary);

    free(x_binary);
    free(r_binary);

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int wordlength(void);
    int rbit;                   // rightmost bit

    while (n-- > 0) {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;             // shift left one position right
        x = x | rbit;           // complete one rotation
    }
    return x;
}
