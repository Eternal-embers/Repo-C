/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>

int GCD(int a,int b){
	return gcd(a,a%b);
}

int gcd(int a,int b){
	int r = a % b;
	while(r){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main(){
	printf("%d\n",GCD(108,72));
	printf("%d\n",gcd(72,108));
	return 0;
}

