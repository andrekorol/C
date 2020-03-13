#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include <errno.h>
#include<math.h>

#include "wordlength.h"
#include "stringtools.h"

// rightrot: rotate x to the right by n positions
unsigned rightrot(unsigned x, int n);

int main(int argc, char const *argv[])
{
    char *p;
    unsigned long long arg;
    unsigned x, r;
    char *x_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    char *r_binary = (char *) malloc(sizeof(char) * (wordlength() + 1));
    int max_uint_digits = floor(log10(UINT_MAX)) + 1;
    errno = 0;  // not 'int errno', because the '#include' already defined it

    if (argc < 2) {
        printf("Please pass an unsigned int as argument when calling the script.\n"); 
        return 1;
    }
    arg = strtoull(argv[1], &p, 10);
    if (*p != '\0' || errno != 0)
        return 1;
    if (arg > UINT_MAX)
        return 1;

    x = arg;
    utoa(x, x_binary, 2);
    left_zeropad_string(x_binary, (size_t) wordlength());
    printf("x = %*u (%s)\n", max_uint_digits, x, x_binary);

    for (unsigned short i = 0; i < USHRT_MAX; i++)
        r = rightrot(x, INT_MAX);
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
    unsigned rbits, all_ones = ~0;

    if ((n = n % wordlength()) > 0) {
        rbits = ~(all_ones << n) & x;           // n rightmost bits of x
        rbits = rbits << (wordlength() - n);    // n rightmost bits to left
        x = x >> n;                             // x shifted n positions right
        x = x | rbits;                          // rotation completed
    }
    return x;
}
