#include<iostream>

using namespace std;

const int N = 100005;

//headΪͷ�ڵ��������idxΪ��һ������������
int head, idx;

//e[] �洢�ڵ��ֵ�� ne[] �洢�ڵ��nextָ��
int e[N], ne[N];

//��ʼ��
void init(){
    head = -1;
    idx = 0;
}

//�� x ���뵽ͷ�ڵ�ĺ���
void add_to_head(int x){
	e[idx] = x, ne[idx] = ne[head], ne[head] = idx++;
}

//�� x ���뵽�� k ������Ľڵ�ĺ���
void add(int k, int x){
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

//���� k ������Ľڵ�ĺ���Ľڵ�ɾ��
void remove(int k){
	ne[k] = ne[ne[k]];
}

