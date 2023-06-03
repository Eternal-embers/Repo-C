#include<stdio.h>
#include<float.h>
#include<limits.h>
int main(void){
	int big_int=2147483647;//有符号整型数据最大值一般为2^31-1； 
	float big_float=3.4e38;//浮点数最大值一般为3.4E38 
	float small_float=10.0/3;//浮点型数据的有效位数为六位 
	printf("The big int data is %d\n",big_int+1);//整型数据最大值加1会造成越界，结果为-2147483648； 
	printf("The big float data is %f\n",big_float*10);//浮点数最大数据乘10造成越界，输出inf。
	/*如果浮点数据只加1个小数据，由于其精确度限制不会造成越界*/
	printf("The big float data is %f\n",small_float);//打印3.333333，损失精度
	printf("The MAX float data is %f\n",FLT_MAX);//打印340282346638528859811704183484516925440.000000 
	printf("The max int data is %ld\n",INT_MAX);//打印2147483647 
	return 0; 
}
