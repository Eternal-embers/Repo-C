#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>
#define N 2000000
_Bool is_prime(int n){
	int i=2;
	int m = sqrt(n);
	while(i<=m){
		if(n % i == 0)return 0;
		i++;
	}
	return 1;
}
//埃氏筛选法 
int main(){
	int i,j,count = 0;
	_Bool prime[N+1];
	int m = sqrt(N);
	memset(prime,1,sizeof(prime));//初始化prime数组元素全部为1 
	//找出sqrt(N)以内的全部素数 
	for(i = 2;i <= m;i++){
		if(is_prime(i) == 0)
		prime[i] = 0;
	} 

	//筛选 
	printf("\t");
	for(i = 2;i <= m;i++){
		//用sqrt(N)以内的素数来筛选N*N以内的素数 
		if(prime[i])	
		for(j = m+1;j <= N;j++)
		if( j%i == 0)prime[j]=0;
	}
	
	//打印素数 
	for(i=2;i<=N;i++) 
	if(prime[i]){
		printf("%d\t",i);
		count++; 
	}
	printf("\n2000000以内总共%d个素数",count); 
	return 0;
}

