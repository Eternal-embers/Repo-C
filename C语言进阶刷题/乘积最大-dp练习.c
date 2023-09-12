/*
	Name: �˻����
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 08/28 08:38
	Description: ��̬�滮
*/
#include<stdio.h>

int dp[50][50] = {0};
int sum[50][50] = {0};//sum[i][j]��¼���ִ��ӵ�i������j����ɵ���
char s[50];
int N,K;//NΪ���ִ����ȣ�KΪ�˺�����

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
	/* ��̬�滮 */
	for(n = 1;n <= N;n++){//����ĳ���
		for(k = 1;k < n;k++){//�˺�����������n���n-1���˺�
			for(i = k;i <= n;i++){ //ͨ��i������n�ֶ�
				/*
					dp[i][k-1]��ʾ������i��k-1�Σ�sum[i+1][n]Ϊ��k��
					��i + 1 > nʱ��sum[i + 1][n]Ϊ0����ʱ������n�޷��ֳ�k + 1�Σ�dp[n][k]Ϊ0
				*/
				dp[n][k] = max(dp[n][k],dp[i][k - 1] * sum[i + 1][n]);
			}
		}
	}
	printf("%d",dp[N][K]);
    return 0;
}
