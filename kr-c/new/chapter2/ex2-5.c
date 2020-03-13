#include <stdio.h>

//any: return first location in s1 where any char from s2 occurs
int any(char [], char[]);

int main(int argc, char const *argv[])
{
    char s1[] = "somecharactershere";
    char s2[] = "qweadhjflmczwx";

    int first_match = any(s1, s2);

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    if (first_match != -1) {    // there was a match found
        printf("first character of s2 found in s1 = %c\n", s1[first_match]);
        printf("character position = %d\n", first_match);
    } else {
        printf("There are no characters found both in s1 and s2\n");
    }
    
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])        // match found?
                return i;              // location of first match     
        }
    }
    return -1;                         // otherwise, no match
}
