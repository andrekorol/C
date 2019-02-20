#include <stdio.h>

#define NUMBER 0x45
#define FIFTEEN 0XFULL
#define BELL '\x7'	// ASCII bell character
#define LEAP 1
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];

int main() {
	printf("fifteen = %llu\n", FIFTEEN);
	printf("%d\n", days[0]);
	printf("hello, " "world\n");
	enum digits { ZERO, ONE , TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
				 TEN, NumberOfDigits };
	printf("one = %d\n", ONE);
	printf("number of digits = %d\n", NumberOfDigits);
	char line[10] = "hi baby 4";
	for (int i = 0; i < 10; ++i) {
		printf("%c\n", line[i]);
	}
	line[20] = 'j';
	printf("%c\n", line[20]);

	if (10 % 3)
		printf("10 is not divisible by 3\n");
	if (10 % 4)
		printf("10 is not divisible by 4\n");
	if (!(10 % 5))
		printf("10 is divisible by 5\n");
	printf("%d\n", 10 % 5);
	printf("!10 = %d\n", !10);
	
	/* while (1) { */
	/* 	printf("%d\n", NUMBER); */
	/* 	printf("%c\n", BELL); */
	/* } */

	return 0;
}
