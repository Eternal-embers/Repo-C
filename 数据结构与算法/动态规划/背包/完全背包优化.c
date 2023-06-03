#include<stdio.h>
int main()
{
	int n,N,i,j;
	scanf("%d%d",&n,&N);
	int w[n+1],v[N+1],dp[N+1];
	w[0] = 0;
	v[0] = 0;
	for(i = 1;i<=n;i++)
	scanf("%d%d",&w[i],&v[i]);
	for(j = 0;j<=N;j++)
	dp[j] = 0;
	for(i = 1;i<=n;i++)
		for(j = 1;j<=N;j++){
			if(w[i]<j && (dp[j-w[i]]+v[i])>dp[j]) dp[j] = dp[j-w[i]]+v[i];
		}
	printf("%d",dp[N]);
	return 0;
}
