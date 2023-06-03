#include<stdio.h>
#include<stdlib.h>
#define N 100
long long helper[N+1]={0};//long long只能计算到fib(92); 
//带备忘录的递归写法 
long long fib(long long n){
	if(n==1)return 1;
	else if(helper[n-1] == 0)helper[n-1] = fib(n-1);
	if(n==2)return 1;
	else if(helper[n-2] == 0)helper[n-2] = fib(n-2);
	return helper[n-1] + helper[n-2];
}
int main()
{
	int n,i;
	printf("n=");
	scanf("%d",&n);
	printf("fib[%d]=%lld\n",n,fib(n));
	return 0;
}
