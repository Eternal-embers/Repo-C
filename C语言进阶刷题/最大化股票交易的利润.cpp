/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/31 22:46
	Description: ��󻯹�Ʊ���׵�����
*/
#include<stdio.h>

int  a[10004];
int main(){
	int N;
	scanf("%d",&N);
	int i,j;
	for(i = 0;i < N;i++)
		scanf("%d",&a[i]);
	int res = -1e4;
	for(i = 0;i < N - 1;i++){//��i + 1������
		for(j = i + 1;j < N;j++){
			int profit = a[j] - a[i];
			if(profit > res) res = profit;
		}
	}
	printf("%d",res);
	return 0;
}

