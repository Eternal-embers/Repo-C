#include<stdio.h>
int main()
{
	int n,N,i,j;
	scanf("%d%d",&n,&N);//n件物品放入限重为N的背包中
	int w[n+1],v[n+1],dp[n+1][N+1];//将前i件物品装入限重为j的背包中可获得的最大价值
	w[0] = 0;//为了让w[i]表示为第i件物品的质量
	v[0] = 0;//为了让v[i]表示为第i件物品的价值
	for(i = 1;i<=n;i++)
	scanf("%d%d",&w[i],&v[i]);//输入各物品的质量和价值
	for(i = 0;i<n;i++){
	dp[i][0] = 0;//将前i件物品放入限重为0的背包中则最大价值为0
	}
	for(j = 0;j<=N;j++){
	dp[0][j] = 0;//往限重为j的背包中什么都不放则最大价值为0
	}
	for(i = 1;i<=n;i++)
		for(j = 1;j<=N;j++)
		{
		//如果将前i件放入背包，装入第i件获得的最大价值大于不装入第i件获得的最大价值
		if(j>=w[i] && (dp[i-1][j-w[i]]+v[i])>dp[i-1][j]) dp[i][j] = dp[i-1][j-w[i]]+v[i];
		else dp[i][j] = dp[i-1][j];
		}
	printf("%d",dp[n][N]);
	return 0;
}
