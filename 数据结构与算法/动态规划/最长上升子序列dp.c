#include<stdio.h>
int main(){
	int i,j,n,ans = 0;
	scanf("%d",&n);
	int dp[n],a[n];
	for(i = 0;i<n;i++)
	scanf("%d",&a[i]),dp[i] = 1;
	for(i = 1;i<n;i++)//以a[i]结尾的最长子序列长度
	{
		for(j = 0;j<i;j++)
		if(a[i]>a[j] && dp[i]<dp[j]+1) dp[i] = dp[j]+1;
	}
	for(i=1;i<=n;i++)
	if(dp[i]>ans) ans = dp[i];
	printf("%d\n",ans);
	return 0;
}
