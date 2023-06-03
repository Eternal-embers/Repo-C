#include<stdio.h>
int step(int n,int num){
    if(n==39){
		if(num%2==0) return 1;//右脚达到终点
		else return 0;//到达终点,非右脚落地
	}
	if(n>39) return 0;//超过终点
	return step(n+1,num+1)+step(n+2,num+1);//当前走一步或两步能到达终点的情况数
}
int main()
{
	 printf("%d",step(0,0));
	 return 0;
}
