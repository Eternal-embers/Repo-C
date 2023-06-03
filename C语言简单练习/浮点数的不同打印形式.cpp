#include<stdio.h>
int main()
{
	float input;
	printf("Enter a floating-point value:");
	scanf("%f",&input);
	printf("fixed-point notation:%f\n",input);//普通小数形式
	printf("exponential notatino:%e\n",input);//指数形式
	printf("p notation:%a\n",input);
	return 0; 
}
