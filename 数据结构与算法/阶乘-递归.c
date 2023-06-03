#include<stdio.h>
unsigned long long f(int n){
	if(n<=2) return n;
	else return n*f(n-1);
}//×î´ó¼ÆËãf(43) 
int main()
{
	printf("%llu",f(43));
	return 0;
}
