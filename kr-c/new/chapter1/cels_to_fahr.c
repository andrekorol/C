#include <stdio.h>
#include <math.h>

/* print Celsius-Fahrenheit table */
main()
{
    float celsius, fahr;
    float lower, upper, step;

    lower = -17.8;      /* lower limit of temperature table */
    upper = 148.9;      /* upper limit */
    step = 11.1;        /* step size */

    celsius = lower;
    printf("%10s\t%10s\n", "Celsius", "Fahrenheit");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        if (signbit(fahr))
            fahr = fahr * -1;
        printf("%10.1f\t%10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}