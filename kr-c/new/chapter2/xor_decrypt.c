#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 255

// xor_decrypt: decrypt a string using the XOR operator
char  *xor_decrypt(char *, int);

int main(int argc, char const *argv[])
{
    char input[MAX_LEN];
    int key;

    fprintf(stdout, "Enter the encrypted string:\n");
    fgets(input, MAX_LEN, stdin);

    fprintf(stdout, "Enter the integer used as the encryption key:\n");
    scanf("%d", &key);

    char *decrypted_str = xor_decrypt(input, key);

    fprintf(stdout, "The resulting decrypted string is:\n%s\n", decrypted_str);

    return 0;
}

char *xor_decrypt(char *str, int key)
{
    char *tmp_str = malloc(sizeof(str));
    char *decrypted_str = tmp_str;      // point to the initial position

    for ( ; *str != '\0'; str++)
        *tmp_str++ = *str ^ key;

    return decrypted_str;
}
