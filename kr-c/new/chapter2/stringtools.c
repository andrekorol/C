#include <stdlib.h>
#include <string.h>

#include "stringtools.h"

void swap(char *x, char *y)
{
	char t = *x; *x = *y; *y = t;
}

/* reverse: reverse buffer[i..j] */
char* reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}

/* itoa: convert n to characters in s, following the given base */
char* itoa(int value, char* buffer, int base)
{
	// invalid input
	if (base < 2 || base > 32)
		return buffer;

	// consider absolute value of number
	int n = abs(value);

	int i = 0;
	while (n)
	{
		int r = n % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}

	// if number is 0
	if (i == 0)
		buffer[i++] = '0';

	// If base is 10 and value is negative, the resulting string 
	// is preceded with a minus sign (-)
	// With any other base, value is always considered unsigned
	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0'; // null terminate string

	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}

char* utoa(unsigned value, char* buffer, int base)
{
	// invalid input
	if (base < 2 || base > 32)
		return buffer;

	unsigned i = 0;
	while (value)
	{
		unsigned r = value % base;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		value = value / base;
	}

	// if number is 0
	if (i == 0)
		buffer[i++] = '0';

	buffer[i] = '\0'; // null terminate string

	// reverse the string and return it
	return reverse(buffer, 0, i - 1);
}

/* left_zeropad_string: add zeroes to the left of a string until it reaches a given size */
void left_zeropad_string(char *binary_string, size_t size)
{
	char *zeroes =(char *) malloc(sizeof(char) * (size + 1));
	char *tmp = strdup(binary_string);
	size_t j = 1;



	for (size_t i = strlen(binary_string); i < size; i++)
	{
		strcat(zeroes, "0");
		zeroes = (char *) realloc(zeroes, (sizeof(char) * ++j));
	}
	strcpy(binary_string, zeroes);
	strcat(binary_string, tmp);
}
