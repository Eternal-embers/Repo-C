#include<stdio.h>
int main()
{
	int num,N,i,j,k,t;
	scanf("%d%d",&num,&N);
	int w[num+1],v[num+1],n[num+1],dp[num+1][N+1];
	n[0] = 0;
	w[0] = 0;
	v[0] = 0;
	for(i = 1;i<=num;i++)
	scanf("%d%d%d",&w[i],&v[i],&n[i]);
	for(i = 0;i<=num;i++)
	dp[i][0] = 0;//限重为0
	for(j = 0;j<=N;j++)
	dp[0][j] = 0;//不放入物品
	for(i = 1;i<=num;i++)
		for(j = 1;j<=N;j++){
			if(j/w[i]<n[i]) t = j/w[i];
			else t = n[i];
			k = 1;
			dp[i][j] = dp[i-1][j];
			while(k<=t){
			if((dp[i-1][j-k*w[i]]+k*v[i])>dp[i][j]) dp[i][j] = dp[i-1][j-k*w[i]]+k*v[i];
			k++;
			}
		}
	printf("%d",dp[num][N]);
	return 0;
}
