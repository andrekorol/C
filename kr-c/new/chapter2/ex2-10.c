#include <stdio.h>
#include <string.h>

/* lower: convert c to lower case; ASCII only */
int lower(int c);

int main()
{
    char const *mixed_string = "QwERtYUioP";
    size_t len = strlen(mixed_string);

    for (size_t i = 0; i < len; ++i)
        printf("%c", lower(mixed_string[i]));
    printf("\n");

    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
