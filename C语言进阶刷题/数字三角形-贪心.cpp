/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:07/30 19:56
	Description:数字三角形
*/
#include<stdio.h>
int N;
int a[104][104] = {0};

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
	for(i = 1;i < N;i++){
		for(j = 0;j <= i;j++){
			a[i][j] += max(a[i-1][j], a[i-1][j-1]);
		}
	}
	int res = 0;
	for(i = 0;i < N;i++){
		res = max(res,a[N-1][i]);
	}
	printf("%d",res);
	return 0;
}
