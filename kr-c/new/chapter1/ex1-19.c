#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */

int c_getline(char s[], int maxline);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    while (c_getline(line, MAXLINE)) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

/* c_getline: read a line into s, return length */
int c_getline(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 2) {
            s[j] = c;       /* line still in boundaries */
            ++j;
        }
    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}

/* reverse: reverse the character string s */
void reverse(char s[])
{
    char temp;
    int i, j;
    
    while (s[i] != '\0')    /* find the end of string s     */
        ++i;
    --i;                    /* back off from '\0'           */
    if (s[i] == '\n')
        --i;                /* leave newline in place       */
    j = 0;                  /* beginning of new string s    */  
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}
