/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/23 11:07
	Description: ������
*/
#include<stdio.h>

/* �ݹ鷨*/
long long binpow(long long a,long long b){
	if(b == 0) return 1;
	long long res = binpow(a,b / 2);
	if(b % 2)
		return res * res * a;
	else
		return res * res;
}

/* ������ */
long long pow(long long a,long long b){
	long long res = 1;
	while(b > 0){
		if(b & 1) res = res * a;//bΪ����
		a = a * a;
		b >>= 1;//b����2
	}
	return res;
}

int main(){
    printf("%d %d",binpow(3,15),pow(3,15));
	return 0;
}

