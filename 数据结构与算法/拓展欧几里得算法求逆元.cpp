/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
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
	if(exgcd(a, p, x, y)!= 1)//�޽�����
		return -1;
	return (x % p + p) % p;//ȷ����Ԫ��[0,p-1]֮�䣬���⸺��
}

int main(){
	printf("%d",inv(3,11));
	return 0;
}

