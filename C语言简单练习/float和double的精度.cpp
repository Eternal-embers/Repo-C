#include<stdio.h>
#include<float.h>
int main()
{
	double d_third=1.0/3.0;
	float f_third=1.0/3.0;
	printf("float of one third(6)=%.6f\n",f_third);
	printf("float of one third(12)=%.12f\n",f_third);//小数点第6位后不准确，可能只会准确一位 
	//编译器在打印float时统一转换为double,但打印时的转换并不能提高float类型数据的精度 
	printf("float of one third(16)=%.16f\n",f_third);
	printf("float of one third(lf)=%.16lf\n",f_third);
	printf("double of one third(6)=%.6lf\n",d_third);
	printf("double of one third(12)=%.12lf\n",d_third);
	printf("double of one third(16)=%.16lf\n",d_third);
	printf("double of ont third(20)=%.20lf\n",d_third);//小数点第15位后数据不准确，可能只会准确一位 
	printf("FLT_DIG in float.h is %d\n",FLT_DIG);//float的精度 
	printf("DBL_DIG in float.h is %d\n",DBL_DIG);//double的精度 
	return 0;
}
