/*
	Name: 乘积最大
	Copyright:劣等生
	Author:劣等生
	Date: 08/28 08:38
	Description: 动态规划
*/
#include<stdio.h>

int dp[50][50] = {0};
int sum[50][50] = {0};//sum[i][j]记录数字串从第i个到第j个组成的数
char s[50];
int N,K;//N为数字串长度，K为乘号数量

int max(int a,int b){
	return a > b ? a : b;
}

int main(){
	int i,j,n,k;
	scanf("%d %d",&N,&K);
	scanf("%s",s + 1);
    for(i = 1;i <= N;i++){
    	for(j = i;j <= N;j++){
    		sum[i][j] = sum[i][j - 1] * 10 + s[j] - '0';
		}
	}
	for(n = 1;n <= N;n++)
		dp[n][0] = sum[1][n];
	/* 动态规划 */
	for(n = 1;n <= N;n++){//区间的长度
		for(k = 1;k < n;k++){//乘号数量，区间n最多n-1个乘号
			for(i = k;i <= n;i++){ //通过i将区间n分段
				/*
					dp[i][k-1]表示将区间i分k-1段，sum[i+1][n]为第k段
					当i + 1 > n时，sum[i + 1][n]为0，此时的区间n无法分成k + 1段，dp[n][k]为0
				*/
				dp[n][k] = max(dp[n][k],dp[i][k - 1] * sum[i + 1][n]);
			}
		}
	}
	printf("%d",dp[N][K]);
    return 0;
}
