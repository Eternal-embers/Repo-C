/*
	Name: 合唱队形
	Copyright:劣等生
	Author:劣等生
	Date: 08/29 12:18
	Description: 动态规划
*/
#include<stdio.h>

int up[100] ={0};
int down[100] = {0};

int main(){
	int n;
	scanf("%d",&n);
	int T[n];
	int i,j,k;
	for(i = 0;i < n;i++)
		scanf("%d",&T[i]);
		
	for(i = 0;i < n;i++)
		up[i] = down[i] = 1;

	for(i = 1;i < n;i++){
		for(j = 0;j < i;j++)
			if(T[i] > T[j] && up[i] < up[j] + 1)
				up[i] = up[j] + 1;
	}
	printf("%d",up[n - 1]);
	return 0;
}

