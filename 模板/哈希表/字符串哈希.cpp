#include<iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 100005;

int n, m;
ULL h[N], p[N];//h[]Ϊ��ϣֵ���飬p[]ΪP��������
int P = 131;//P���ƣ�Pȡ����ֵ131��1331
char str[N];

//��������[l,r]֮����ַ����Ĺ�ϣֵ
int get(int l,int r){
	return h[r] - h[l - 1] * p[r - l + 1];//��λ����
}

//��ʼ��p[]�����h[]����
p[0] = 1;
for(int i = 1;i <= N;i++){
	p[i] = p[i - 1] * P;
	h[i] = h[i - 1] * P + str[i];
}




