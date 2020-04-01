#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void reverseArrayInPlace(int *array, size_t length)
{
    int tmp;
    size_t half_length = (size_t)round(length / 2);
    for (size_t i = 0; i <= half_length; i++)
    {
        tmp = array[i];
        array[i] = array[length - 1 - i];
        array[length - 1 - i] = tmp;
    }
}

int main()
{
    size_t length = 6;
    int *array = (int *)malloc(sizeof(int) * length);
    size_t i;
    for (i = 0; i < length; i++)
    {
        array[i] = i;
    }

    printf("array = [");
    for (i = 0; i < length; i++)
    {
        i != length - 1 ? printf("%d, ", array[i]) : printf("%d]\n", array[i]);
    }

    reverseArrayInPlace(array, length);
    printf("reversed array = [");
    for (i = 0; i < length; i++)
    {
        i != length - 1 ? printf("%d, ", array[i]) : printf("%d]\n", array[i]);
    }

    free(array);

    return 0;
}