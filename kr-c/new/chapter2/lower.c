#include <stdio.h>
#include <string.h>
/* lower: convert c to lower case; ASCII only */
int lower(int);

int main(int argc, char const *argv[])
{
    char const *mixed_string = "QwERtYUioP";
    size_t len = strlen(mixed_string);
    // printf("len = %zu\n", len);

    for (size_t i = 0; i < len; ++i)
        printf("%c", lower(mixed_string[i]));
    printf("\n");

    return 0;
}

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
