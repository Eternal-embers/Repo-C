#include<iostream>
#include<cstring>

const int N = 100003;//ȡ�������ֵ�ĵ�һ������

//e[]�洢�������ϵĽڵ㣬ne[]Ϊ���ڵ��ϵ�next����
int h[N], e[N], ne[N], idx;

void init(){
	memset(h, -1, sizeof h);
}

//��ʽ�洢
void insert(int x){
	int k = (x % N + N) % N;//��֤kΪ����
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


