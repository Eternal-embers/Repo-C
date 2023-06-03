#include<stdio.h>
int main()
{
	float pi=3.141592653;
	float f=-0.0000347821;
	float F=0.000743212;
	float ff=123.768;
	printf("%15f-----右对齐\n",pi);
	printf("%-15f-----左对齐\n",pi);
	printf("%+f-----显示正负号\n",f);
	printf("%+f-----显示正负号\n",F);
	printf("% f-----正数保留空格，负数则添加负号\n",f);
	printf("% f-----正数保留空格，负数则添加负号\n",F);
	printf("%10.6f------最小字符宽度和小数位数\n",pi);
	printf("%015f------前导0\n",ff);
	return 0; 
}
