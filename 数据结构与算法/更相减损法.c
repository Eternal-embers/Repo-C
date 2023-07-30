/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>

int max(int a,int b){
	return a > b ? a : b;
}

int min(int a,int b){
	return a < b ? a : b;
}

int gcd(int a,int b){
	if(a == b) return a;
	else return gcd(max(a - b,b),min(a - b,b));
}

int main(){
	printf("%d",gcd(72,36));
	return 0;
}

