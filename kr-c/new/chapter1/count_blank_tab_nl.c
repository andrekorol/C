#include <stdio.h>

/* count blanks, tabs and newlines */
main()
{
    int c, blanks, tabs, nl;

    for (blanks = 0, tabs = 0, nl = 0;(c = getchar()) != EOF;) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++nl;
    }
    printf ("blanks = %d\ntabs = %d\nnewlines = %d\n", blanks, tabs, nl);
}