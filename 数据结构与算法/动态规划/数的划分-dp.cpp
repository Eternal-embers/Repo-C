/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:
	Description: ���Ļ���-��̬�滮
*/
#include<stdio.h>

int main(){
	int dp[200][200] = {0};
	int n,k;
	scanf("%d %d",&n,&k);
	int i,j;
	dp[1][1] = 1;
	for(i = 2;i <= n;i++){
		for(j = 1;j <= k;j++){
			dp[i][j] = dp[i - 1][j - 1];//ѡ1
			if(i > j) dp[i][j] += dp[i - j][j];//��ѡ1
		}
	}
	printf("%d",dp[n][k]);
	return 0;
}

