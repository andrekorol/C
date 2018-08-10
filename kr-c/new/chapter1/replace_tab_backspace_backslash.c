#include <stdio.h>

/* copy input to output, replacing each tab by \t, each backaspace by \b, and
    each backslash by \\ */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
   }
}
