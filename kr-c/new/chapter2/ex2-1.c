#include <stdio.h>
#include <limits.h>
#include <float.h>

// determine ranges of types
int main() {
	// limits.h
	printf("bits in a char(number of bits in a byte) = %d\n", CHAR_BIT);
	printf("maximum number of bytes in a multibyte character = %d\n", MB_LEN_MAX);
	printf("maximum value of char = %d\n", CHAR_MAX);
	printf("minimum value of char = %d\n", CHAR_MIN);
	printf("maximum value of int = %d\n", INT_MAX);
	printf("minimum value of int = %d\n", INT_MIN);
	printf("maximum value of long = %ld\n", LONG_MAX);
	printf("minimum value of long = %ld\n", LONG_MIN);
	printf("maximum value of signed char = %d\n", SCHAR_MAX);
	printf("minimum value of signed char = %d\n", SCHAR_MIN);
	printf("maximum value of short = %d\n", SHRT_MAX);
	printf("minimum value of short = %d\n", SHRT_MIN);
	printf("maximum value of unsigned char = %u\n", UCHAR_MAX);
	printf("maximum value of unsigned int = %u\n", UINT_MAX);
	printf("maximum value of unsigned long = %lu\n", ULONG_MAX);
	printf("maximum value of unsigned short = %u\n", USHRT_MAX);
	printf("maximum value of long long = %lld\n", LLONG_MAX);
	printf("minimum value of long long = %lld\n", LLONG_MIN);
	printf("maximum value of unsigned long long = %llu\n", ULLONG_MAX);

	//floats.h
	printf("RADIX = %d\n", FLT_RADIX);
	printf("float mantissa digits = %d\n", FLT_MANT_DIG);
	printf("double mantissa digits = %d\n", DBL_MANT_DIG);
	printf("long double mantissa digits = %d\n", LDBL_MANT_DIG);
	printf("float digits = %d\n", FLT_DIG);
	printf("double digits = %d\n", DBL_DIG);
	printf("long double digits = %d\n", LDBL_DIG);
	printf("float minimum exponent = %d\n", FLT_MIN_EXP);
	printf("double minimum exponent = %d\n", DBL_MIN_EXP);
	printf("long double minimum exponent = %d\n", LDBL_MIN_EXP);
	printf("float maximum exponent = %d\n", FLT_MAX_EXP);
	printf("double maximum exponent = %d\n", DBL_MAX_EXP);
	printf("long double maximum exponent = %d\n", LDBL_MAX_EXP);
	printf("float maximum base-10 exponent = %d\n", FLT_MAX_10_EXP);
	printf("double maximum base-10 exponent = %d\n", DBL_MAX_10_EXP);
	printf("long double maximum base-10 exponent = %d\n", LDBL_MAX_10_EXP);
	printf("maximum finite representable float = %f\n", FLT_MAX);
	printf("maximum finite representable double = %lf\n", DBL_MAX);
	printf("maximum finite representable long double = %Lf\n", LDBL_MAX);
	printf("float epsilon = %f\n", FLT_EPSILON);
	printf("double epsilon = %lf\n", DBL_EPSILON);
	printf("long double epsilon = %Lf\n", LDBL_EPSILON);
	printf("minimum representable positive float = %f\n", FLT_MIN);
	printf("minimum representable positive double = %lf\n", DBL_MIN);
	printf("minimum representable positive long double = %Lf\n", LDBL_MIN);
	printf("ROUND = %d\n", FLT_ROUNDS);
	printf("evaluation method = %d\n", FLT_EVAL_METHOD);
	printf("decimal digits = %d\n", DECIMAL_DIG);

	return 0;
}
