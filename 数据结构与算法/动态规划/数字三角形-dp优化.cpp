/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:07/30 19:41
	Description: ����������-dp�Ż�
*/
#include<stdio.h>
int N;
int a[100][100];
int dp[100];//dp�Ż�Ϊһά����

int max(int a,int b){
	return a > b ? a : b;
}

int main(){
	scanf("%d",&N);
	int i,j;
	for(i = 0;i < N;i++){
		for(j = 0;j <= i;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i = 0;i < N;i++)
		dp[i] = a[N-1][i];
	for(i = N - 2;i >= 0;i--){
		for(j = 0;j <= i;j++){
			dp[j] = max(dp[j],dp[j + 1]) + a[i][j];
		}
	}
	printf("%d",dp[0]);
	return 0;
}

