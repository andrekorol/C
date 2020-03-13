#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 255

// xor_encrypt: encrypt a string using the XOR operator
char  *xor_encrypt(char *, int);

int main(int argc, char const *argv[])
{
    char input[MAX_LEN];
    int key;

    fprintf(stdout, "Enter the string to be encrypted:\n");
    fgets(input, MAX_LEN, stdin);

    fprintf(stdout, "Enter an integer to be used as the encryption key:\n");
    scanf("%d", &key);

    char *encrypted_str = xor_encrypt(input, key);

    fprintf(stdout, "The resulting encrypted string is:\n%s\n", encrypted_str);

    return 0;
}

char *xor_encrypt(char *str, int key)
{
    char *tmp_str = malloc(sizeof(str));
    char *encrypted_str = tmp_str;      // point to the initial position

    for ( ; *str != '\0'; str++)
        *tmp_str++ = *str ^ key;

    return encrypted_str;
}
