/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/30 19:15
	Description: ����������
*/
#include<stdio.h>
int N;
int a[100][100];
int dp[100][100] = {0};

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
	/* ��̬�滮���ӵײ���ʼ����������� */
	for(i = 0;i < N;i++)
		dp[N - 1][i] = a[N - 1][i];
	for(i = N-2;i >= 0;i--){
		for(j = 0;j <= i;j++){
			dp[i][j] = max(dp[i+1][j+1],dp[i+1][j]) + a[i][j];
		}
	}
	printf("%d",dp[0][0]);
	return 0;
}

