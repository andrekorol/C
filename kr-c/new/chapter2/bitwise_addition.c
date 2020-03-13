#include <stdio.h>

// bitwise_addition: use only bitwise operators to perform the addition of two integers
int bitwise_addition(int, int);

int main(int argc, char const *argv[])
{
    int x, y;
    printf("Enter an integer value for x: ");
    scanf("%d", &x);
    printf("\nEnter an integer value for y: ");
    scanf("%d", &y);

    printf("\nx + y = %d + %d = %d\n", x, y, bitwise_addition(x, y));

    return 0;
}

int bitwise_addition(int a, int b)
{
    int carry;
    while (b != 0) {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
