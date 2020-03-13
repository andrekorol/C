/* swap: swap two numbers */
void swap(char *x, char *y);

/* reverse: reverse buffer[i..j] */
char* reverse(char *buffer, int i, int j);

/* itoa: convert int value to characters in buffer, following the given base */
char* itoa(int value, char* buffer, int base);

/* utoa: convert unsigned value to characters in buffer, following the given base */
char * utoa(unsigned value, char* buffer, int base);

/* left_zeropad_string: add zeroes to the left of a string until it reaches a given size */
void left_zeropad_string(char *binary_string, size_t size);
