/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<math.h>
int max;
int *p;
void dfs(int n,int cost){
	if(n == 0){
		*p = cost;
		return;
	}
	else if(n > 0){
		int i;
		for(i = 0;i < max;i++){
			dfs(n - (int)pow(9,i),cost + 1);
		}
	}
}

int main(){
	int T,i,j;
	scanf("%d",&T);
	int a[T],res[T];
	int temp;
	for(i = 0;i < T;i++){
		scanf("%d",&a[i]);//账
	}
	for(i = 0;i < T;i++){
		for(j = 0;pow(9,j) < a[i];j++);
		max = j;
		res[i] = a[i];
		p = &res[i];
		dfs(a[i],0);
	}
	for(i = 0;i < T;i++){
		printf("%d",res[i]);
	}
	return 0;
}

