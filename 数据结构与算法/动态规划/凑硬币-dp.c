#include<stdio.h>
int min(int a,int b){
	if(a>b) return b;
	else return a;
}
int f(int n){
	int f[1000],i,cost;
	f[0] = 0;//³õÊ¼»¯ 
	for(i = 1;i<=n;i++){
		cost = 1000;
		if(i-1>=0) cost = min(cost,f[i-1]+1);
		if(i-5>=0) cost = min(cost,f[i-5]+1);
		if(i-11>=0) cost = min(cost,f[i-11]+1);
		f[i] = cost;
	}
	return f[n];
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
	return 0;
}
