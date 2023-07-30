/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
int N,V;
int w[104],v[104],dp[1004] = {0};

int max(int a,int b){
	return a > b ? a : b;
}

int main(){
	scanf("%d %d",&N,&V);
	int i,j;
	for(i = 1;i <= N;i++){
		scanf("%d %d",&w[i],&v[i]);
	}
	/*
        穷举所有情况，当背包体积为j时，我们从第1件到第N件逐一开始试探：
        如果放入物品能获得更高的价值，则用dp[i][j]记录下此时放入i物品获得的最大价值
        否则我们用上一次试探第i-1件时获得最大价值作为当前的最大价值
        对于体积为j的背包，当试探完所有物品时记录下的dp[N][j]就是背包体积为j时所能获得的最大价值
        当背包体积为V，试探完所有物品，此时记录下的最大价值dp[N][V]就是背包体积为V时能获得的最大价值
	*/
	//dp[i][j]表示放第i件时，体积为j的背包所能获得的最大价值
	for(i = 1;i <= N;i++){
		for(j = V;j >= 1;j--){
			if(j >= w[i])
				dp[j] = max(dp[j],dp[j - w[i]] + v[i]);//当背包体积为j时，放第i件和不放第i件之间的最大价值
			/*
            else dp[j] = dp[j];//dp[j]表示背包体积为j时，我们不放第i件之前所能获得的最大价值
			*/
		}
	}
	printf("%d",dp[V]);
}

