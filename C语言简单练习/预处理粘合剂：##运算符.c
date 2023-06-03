#include<stdio.h>
#define XNAME(n) x ## n
#define PRINT_X(n) printf("x" #n " = %d\n",x ## n);

/* ##运算符可以用于类函数宏的替换部分，##还可以用于对象宏的替换部分，##运算符把两个记号组合成一个记号 */
int main(){
	int XNAME(1) = 14;//变成x1 = 14;
	int XNAME(2) = 20;//变成x2 = 20;
	int x3 = 40;
	PRINT_X(1);//变成printf("x1 = %d\n",x1);
	PRINT_X(2);//变成printf("x2 = %d\n",x2);
	PRINT_X(3);//变成printf("x3 = %d\n",x3);
	return 0;
}

