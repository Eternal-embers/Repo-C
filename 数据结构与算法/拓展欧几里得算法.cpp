/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/23 15:42
	Description: ��չŷ������㷨
*/
#include<stdio.h>

int exgcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	int gcd = exgcd(b, a % b, y, x);
	y -= (a/ b) * x;
	return gcd;
}

int main(){
	int x,y;
    exgcd(3,10,x,y);
    printf("%d %d",x,y);
	return 0;
}

