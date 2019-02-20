#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int c_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;            /* current line length */
    int max;            /* maximum length so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];   /* longest line saved here */

    max = 0;
    while ((len = c_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    /* there was a line */
        printf("%s", longest);
    return 0;
}

/* c_getline: read a line into s, return length */
int c_getline(char s[], int lim)
{
    int c, i;
	enum loop { NO, YES };
	enum loop okloop = YES;

	i = 0;
	while (okloop == YES) {
		if (i >= lim - 1)
			okloop = NO;
		else if ((c = getchar()) == '\n')
			okloop = NO;
		else if (c == EOF)
			okloop = NO;
		else {
			s[i] = c;
			++i;
		}
	}
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
