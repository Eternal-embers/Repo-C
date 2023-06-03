#include<stdio.h>
unsigned long long f(int m,int n,int arr[][n]){
	unsigned long long dp[m][n];
	int i,j;
	dp[0][0] = arr[0][0];
	for(i = 1;i<m;i++) {
		dp[i][0] = dp[i-1][0]+arr[i][0];
	}
	for(i = 1;i<n;i++){
		dp[0][i] = dp[0][i-1]+arr[0][i];
	}
	for(i = 1;i<m;i++)
		for(j = 1;j<n;j++){
			if(dp[i-1][j]<dp[i][j-1]) dp[i][j] = dp[i-1][j]+arr[i][j];
				else dp[i][j] = dp[i][j-1]+arr[i][j];
		}
	return dp[m-1][n-1];
}
int main()
{
	int m,n,i,j;
	scanf("%d%d",&m,&n);
	int arr[m][n];
	for(i = 0;i<m;i++)
		for(j = 0;j<n;j++)
			scanf("%d",&arr[i][j]);
	printf("%llu",f(m,n,arr));
	return 0;
}
