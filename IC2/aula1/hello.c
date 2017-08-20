#include <stdio.h>
#include <locale.h>
#if defined(_WIN64)
setlocale(LC_ALL, "Portuguese");
#endif

int main(void) {
    printf("Olá, paçoca!\n");
    return 0;
}
