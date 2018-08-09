#include <stdio.h>

#define NONBLANK 'a'    /* this could be any character other than ' '

/* copy input to output, replacing each string of
    one or more blanks by a single blank */
main()
{
    int c, previous_char = NONBLANK;

    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        if (c == ' ')
            if (previous_char != ' ')
                putchar(c);
        previous_char = c;
    }
}