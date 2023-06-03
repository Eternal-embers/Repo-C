#include<stdio.h>
#include<stdlib.h>
#define N 10000
int main(){
	int i,sum=0;
	//n=1+2+...+k,k为整数,则n为三角数
	for(i=1;i<N;i++) 
	{
		sum+=i;
		printf("%15d",sum);
		if(i%6==0)printf("\n");
	}
	return 0;
} 
