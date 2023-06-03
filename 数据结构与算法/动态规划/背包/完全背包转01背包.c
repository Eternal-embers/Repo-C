#include<stdio.h>
int main()
{
	int n,N,i,j,k;
	scanf("%d%d",&n,&N);
	int w[n+1],v[n+1],dp[n+1][N+1];
	w[0] = 0;
	v[0] = 0;
	for(i = 1;i<=n;i++)
	scanf("%d%d",&w[i],&v[i]);
	for(i = 0;i<=n;i++)
	dp[i][0] = 0;//限重为0的情况
	for(j = 0;j<=N;j++)
	dp[0][j] = 0;//不放入物品的情况
	for(i = 1;i<=n;i++)
		for(j = 1;j<=N;j++){
			k = 1;
			dp[i][j] = dp[i-1][j];
			while(j-k*w[i]>=0){
				if((dp[i-1][j-k*w[i]]+k*v[i])>dp[i][j]) dp[i][j] = dp[i-1][j-k*w[i]]+k*v[i];
				k++;
			}
		}
	printf("%d",dp[n][N]);
	return 0;
}
