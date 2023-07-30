/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
typedef long long LL;
LL exgcd(LL a, LL b, LL &x, LL &y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	LL gcd = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return gcd;
}

LL inv(LL a,LL p){
	LL x,y;
	if(exgcd(a, p, x, y)!= 1)//无解的情况
		return -1;
	return (x % p + p) % p;//确保逆元在[0,p-1]之间，避免负数
}

int main(){
	printf("%d",inv(3,11));
	return 0;
}

