/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 07/23 17:12
	Description: 费马小定理求逆元
*/
#include<stdio.h>
/* 迭代法 */
int powMod(int a,int p,int mod){
	int res = 1;
	while(p){
		if(p & 1) res = res * a % mod;//奇数
		a = a * a % mod;
		p >>= 1;
	}
	return res;
}

/* 递归法 */
int powmod(int a,int p,int mod){
	if(p == 0)
		return 1;
	int res = powmod(a,p >> 1,mod);
	if(p & 1)
		return res * res * a % mod;
	else
		return res * res % mod;
}

/*
	 测试用例：
	 1.a = 2,p = 7,inv(a) = 4
	 2.a = 3,p = 11,inv(a) = 4
	 3.a = 5,p = 13,inv(a) = 8
	 4.a = 4,p = 17,inv(a) = 13
*/
int main(){
    printf("%d\n",powMod(4,15,17));
    printf("%d",powmod(2,5,7));
	return 0;
}

