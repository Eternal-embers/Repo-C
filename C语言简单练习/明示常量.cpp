#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
	printf("char的位数:%d\n\n",CHAR_BIT);
	printf("The max value of char:%d\n\n",CHAR_MAX);
	printf("The min value of char:%d\n\n",CHAR_MIN);
	printf("The max value of signed char:%d\n\n",SCHAR_MAX);
	printf("The min value of signed char:%d\n\n",SCHAR_MIN);
	printf("The max value of unsigned char:%d\n\n",UCHAR_MAX);
	printf("The max value of short:%d\n\n",SHRT_MAX);
	printf("The min value of short:%d\n\n",SHRT_MIN);
	printf("The max value of unsigned short:%d\n\n",USHRT_MAX);
	printf("The max value of int:%d\n\n",INT_MAX);
	printf("The min value of int:%d\n\n",INT_MIN);
	printf("The max value of unsigned int:%u\n\n",UINT_MAX);
	printf("The max value of long:%ld\n\n",LONG_MAX);
	printf("The min value of long:%ld\n\n",LONG_MIN);
	printf("The max value of unsigned long:%lu\n\n",ULONG_MAX);
	printf("The max value of long long:%lld\n\n",LLONG_MAX);
	printf("The min value of long long:%lld\n\n",LLONG_MIN);
	printf("The max value of unsigned long long:%llu\n\n",ULLONG_MAX);
	printf("float的尾数位数:%d\n\n",FLT_MANT_DIG);
	printf("float类型的最少有效位数:%d\n\n",FLT_DIG);
	printf("带全部有效数字的float类型的最小负指数:%e\n\n",FLT_MIN_10_EXP);
	printf("float类型的最大正指数:%e\n\n",FLT_MAX_10_EXP);
	printf("The max value of float:%e\n\n",FLT_MAX);
	printf("The min value of float:%e\n\n",FLT_MIN);
	printf("double的尾数位数:%d\n\n",DBL_MANT_DIG);
	printf("double类型的最少有效位数:%d\n\n",DBL_DIG);
	printf("The max value of double:%e\n\n",DBL_MAX);
	printf("The min value of double:%e\n\n",DBL_MIN);
	printf("long double的尾数位数:%d\n\n",LDBL_DIG);
	printf("long double类型的最少有效位数:%d\n\n",LDBL_DIG);
	printf("The max value of long double:%e\n\n",LDBL_MAX);
	printf("The min value of long double:%e\n\n",LDBL_MIN);
	printf("1.00和比1.00大的最小float类型值之间的差值:%e\n\n",FLT_EPSILON);
	printf("1.00和比1.00大的最小double类型值之间的差值:%e\n\n",DBL_EPSILON);
	printf("1.00和比1.00大的最小long double类型值之间的差值:%e\n\n",LDBL_EPSILON);
	return 0;
}
