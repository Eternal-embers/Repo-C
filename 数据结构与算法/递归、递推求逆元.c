/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
typedef long long LL;
LL inv(LL a,LL b){
	if(a == 1) return 1;
	return (b / a) * inv( b % a) % b;
}

int main(){
	printf("%d",inv(3,11));
	return 0;
}

