#include<stdio.h>
int main()
{
	int n,N,i,j,k;
	scanf("%d%d",&n,&N);
	int w[n+1],v[n+1],dp[N+1];
	w[0] = 0;
	v[0] = 0;
	for(i = 1;i<=n;i++)
	scanf("%d%d",&w[i],&v[i]);
	for(j = 0;j<=N;j++)
	dp[j] = 0;//不放入物品的情况
	for(i = 1;i<=n;i++)
		for(j = N;j>=1;j--){
			k = 1;
			while(j-k*w[i]>=0){
				if((dp[j-k*w[i]]+k*v[i])>dp[j]) dp[j] = dp[j-k*w[i]]+k*v[i];
				k++;
			}
		}
	printf("%d",dp[N]);
	return 0;
}

