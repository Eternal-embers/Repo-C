#include<iostream>
#include<cstring>

const int N = 100003;//取大于最大值的第一个质数

//e[]存储所有链上的节点，ne[]为各节点上的next数组
int h[N], e[N], ne[N], idx;

void init(){
	memset(h, -1, sizeof h);
}

//链式存储
void insert(int x){
	int k = (x % N + N) % N;//保证k为正数
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

bool find(int x){
	int k = (x % N + N) % N;
	
	for(int i = h[k],i != -1;i = ne[i])
		if(e[i] == x) return true;
		
	return false;
}


