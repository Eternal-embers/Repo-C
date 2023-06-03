#include<stdio.h>
unsigned long long fib(int n){
	int i;
	unsigned long long pre,cur,sum = 0;
	if(n==1 || n==2)return 1;
	pre = cur = 1;
	for(i=3;i<=n;i++){
		sum = pre + cur;
		pre = cur;
		cur = sum;
	}
	return sum;
} 

int main(){
	int n;
	while(1){
	printf("n=");
	scanf("%d",&n);
	if(n == -1)return 0;
	printf("fib(%d)=%llu\n",n,fib(n));
	}
}
