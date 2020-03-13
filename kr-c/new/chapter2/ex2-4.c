#include <stdio.h>

// squeeze: delete each char in s1 which is in s2
void squeeze(char [], char []);

int main(int argc, char const *argv[])
{
    char s1[] = "some vocals here";
    char vocals[] = "aeiou";

    printf("not squeezed = %s\n", s1);

    squeeze(s1, vocals);
    printf("squeezed = %s\n", s1);
    
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = k = 0; s1[i] !='\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if (s2[j] == '\0')      // end of string - no match
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
