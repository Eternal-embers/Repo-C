#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,a,b;
	//如何快速验证回文数
	 while(1){
	 printf("n=");
	 scanf("%d",&n);
	 b=n;
	 a=0;
	 //将数倒序存储到变量a中 
	 while(b>0){
	 	a=a*10+b%10; 
	 	b/=10;
	 }
	 if(n==a)printf("%d是回文数\n",n);
	 else printf("%d不是回文数\n",n);
	}	
	 
} 
