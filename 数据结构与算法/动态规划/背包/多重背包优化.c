#include<stdio.h>
int main()
{
	int num,N,i,j,k,t;
	scanf("%d%d",&num,&N);
	int w[num+1],v[num+1],n[num+1],dp[N+1];
	n[0] = 0;
	w[0] = 0;
	v[0] = 0;
	for(i = 1;i<=num;i++)
	scanf("%d%d%d",&w[i],&v[i],&n[i]);
	for(j = 0;j<=N;j++)
	dp[j] = 0;//不放入物品
	for(i = 1;i<=num;i++)
		for(j = N;j>=1;j--){
			if(j/w[i]<n[i]) t = j/w[i];
			else t = n[i];
			k = 1;
			while(k<=t){
			if((dp[j-k*w[i]]+k*v[i])>dp[j]) dp[j] = dp[j-k*w[i]]+k*v[i];
			k++;
			}
		}
	printf("%d",dp[N]);
	return 0;
}
