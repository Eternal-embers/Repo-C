#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
static jmp_buf buf;
void second(void){
	printf("second\n");//打印
	system("pause");
	longjmp(buf,1);//跳回setjmp的调用处，使得setjmp的返回值为1
}
void first(void){
	printf("执行first\n");
	system("pause");
	second();
	printf("first\n");//不可能执行到此行
}
int main(){
	if(!setjmp(buf)){
		first();//进入此行前，setfmp返回0
	}
	else { //当longjmp跳转转回，setjmp返回1，因此进入此行
		printf("main\n");//打印
	}
	return 0;
}
