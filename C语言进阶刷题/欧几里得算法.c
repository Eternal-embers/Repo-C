#include<stdio.h>
int gcd(int a,int b){
	int r;
	if(a < b){
		a ^= b;
		b ^= a;
		a ^= b;
	}
	do{
		r = a % b;
		a = b;
		b = r;
	}while(r > 0);
	return a;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",gcd(a,b));
	return 0;
}
