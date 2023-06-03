#include<stdio.h>
int main()
{
	int i=12345;
	float a=0.04;
	float f=0.0003456701;
	float g=0.00012470198;
	int o=100;
	printf("i=%i\n",i);
	printf("a=%a\n",a);
	printf("f=%f\n",f);
	printf("f=%e\n",f);
	printf("f=%E\n",f);
	printf("f=%g\n",f);
	printf("g=%G\n",g);
	printf("o=%o\n",o);
	printf("o=%#o\n",o);
	printf("o=%x\n",o);
	printf("o=%#x\n",o);
	printf("%%=%%\n");
	return 0;
}
