#include <stdio.h>

/* print input one word per line */
main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || c != '\n' || c != '\t')
            putchar(c);
        else
            putchar('\n');
    }
}