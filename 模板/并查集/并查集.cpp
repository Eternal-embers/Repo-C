#include<iostream>

using namespace std;

int p[N];//p[i]��ʾ���Ϊi���������ڽڵ�ı��

//��ѯ,�������ڽڵ���p[x] == x
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);//·��ѹ����ԭ����Ϊwhile(p[x] != x) x = p[x];
	return p[x];//����x�����ڽڵ�ı��
}

//�ϲ�
void merge(int a, int b){
	p[find(a)] = find(b);//��b�����ڽڵ�����Ϊa�����ڽڵ���
}
