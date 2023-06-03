#include<stdio.h>
int main(){
	union u{
		int i;
		double d;
		char c;
	}var;
	var.i = 100;
	printf("%d\n",var);
	var.d = 3.14;
	printf("%lf\n",var);
	var.c = 'c';
	printf("%c\n",var);
	return 0;
}
