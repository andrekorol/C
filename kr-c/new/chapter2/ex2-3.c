#include <stdio.h>

#define YES 1
#define NO  0

/* htoi: convert hexadecimal string s to integer */
unsigned long long htoi(char []);

int main(int argc, char const *argv[])
{
    char *hex_strings[6] = {"0xBEEFBABE", "CAFEBABE", "0Xdeadbeef", "0xFEEDC0DE", "0Xfeedc0de","deadd00d"};
    size_t number_of_strings = sizeof(hex_strings) / sizeof(char const *);
    // printf("number of strings = %zu\n", number_of_strings);

    for (size_t i = 0; i < number_of_strings; ++i)
        printf("%s = %llu\n", hex_strings[i], htoi(hex_strings[i]));

    return 0;
}

unsigned long long htoi(char s[])
{
    int hexdigit, i, inhex;
    unsigned long long n;

    i = 0;
    if (s[i] == '0') {  // skip optional 0x or 0X
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;              // value to be returned
    inhex = YES;        // assume valid hexadecimal digit
    for ( ; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' +10;
        else
            inhex = NO; // not a valid hexadecimal digit
        if (inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
}
