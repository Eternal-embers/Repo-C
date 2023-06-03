#include<stdio.h>
unsigned long long f(int n){
	if(n<=2) return n;
	int i;
	unsigned long long dp[n];
	dp[0] = 1;
	dp[1] = 2;
	for( i = 2;i<n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n-1];
}//最大求到91 
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",f(n));
	return 0;
}
