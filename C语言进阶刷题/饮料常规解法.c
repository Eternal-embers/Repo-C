#include<stdio.h>
int main(){
	int n,sum;
	scanf("%d",&n);
	sum = n;//sum表示喝了几瓶
	while(n > 2){
		sum += n/3;//兑换
		n = n / 3 + n % 3;//兑换所得加上上次兑换后剩余的
	}
	printf("%d",sum);
	return 0;
}
