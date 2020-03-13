#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(0));

    for (int i = 0; i < 5; i++)
        printf("%d\t", rand());

    printf("\n");

    return 0;
}
