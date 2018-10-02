#include <stdio.h>
#include <math.h>

float celsiusToFahrenheint(float celsius);

/* test celsiusToFahrenheint function to print a Celsius-Fahrenheit table*/
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
        fahr = celsiusToFahrenheint(celsius);
        printf("%10.1f\t%10.0f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}

/* celsiusToFahrenheint: convert celsius to fahrenheit */
float celsiusToFahrenheint(float celsius)
{
    float fahr;
    fahr = (9.0/5.0) * celsius + 32.0;
    if (signbit(fahr))
        fahr *= -1;
    return fahr;
}