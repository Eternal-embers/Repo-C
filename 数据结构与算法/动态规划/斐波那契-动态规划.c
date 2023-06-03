#include<stdio.h>
#include<stdlib.h>
//自底向上，动态规划循环求斐波那契数列的某一项 
long long fib(int N){
long long dp[N+1];
int i; 
dp[1] = dp[2]= 1;
for( i = 3; i <= N; i++)
	dp[i] = dp[i-1] +dp[i-2];
return dp[N];
}
int main()
{
	int n;
	while(1){
		printf("n=");
		scanf("%d",&n);
		if(n == -1)return 0;
		else printf("fib(%d)=%lld\n",n,fib(n));
	}
}
