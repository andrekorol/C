#include <stdio.h>
#include <locale.h>
#if defined(_WIN64)
setlocale(LC_ALL, "Portuguese");
#endif

int main(void) {
    printf("Ol�, pa�oca!\n");
    return 0;
}
