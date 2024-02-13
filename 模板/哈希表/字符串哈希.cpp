#include<iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 100005;

int n, m;
ULL h[N], p[N];//h[]为哈希值数组，p[]为P的幂数组
int P = 131;//P进制，P取经验值131或1331
char str[N];

//计算区间[l,r]之间的字符串的哈希值
int get(int l,int r){
	return h[r] - h[l - 1] * p[r - l + 1];//高位对齐
}

//初始化p[]数组和h[]数组
p[0] = 1;
for(int i = 1;i <= N;i++){
	p[i] = p[i - 1] * P;
	h[i] = h[i - 1] * P + str[i];
}




