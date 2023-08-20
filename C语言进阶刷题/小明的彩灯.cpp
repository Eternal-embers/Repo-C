/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/29 13:07
	Description: С���Ĳʵ�
*/
#include<stdio.h>
#define LL long long
int main(){
	int N,Q,i,j;
	scanf("%d %d",&N,&Q);
	LL a[N + 1];
	for(i = 1;i <= N;i++)
		scanf("%lld",&a[i]);
	int l,r,x;
	for(i = 1;i <= Q;i++){
		scanf("%d %d %d",&l,&r,&x);
		for(j = l;j <= r;j++){
			a[j] += x;
		}
	}
	for(i = 1;i <= N;i++){
		if(a[i] > 0) printf("%lld ",a[i]);
		else printf("%lld ",0);
	}
	return 0;
}

