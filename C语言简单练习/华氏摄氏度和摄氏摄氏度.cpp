#include<stdio.h>
#define adjust 32
int main()
{
	float scale=1.8;
	float F_temperature=32.0;
	float C_temperature;
	printf("F_temperature	C_temperature\n");
	while(C_temperature<100)
	{
	C_temperature=(F_temperature-32)*1.8;
	printf("%8.2fF%16.2fC\n",F_temperature,C_temperature);
	F_temperature+=5;
	}
	return 0;
}
