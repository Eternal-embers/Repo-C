#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100005;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//d[]�洢���ڵ�����

void add(int x, int y){
	e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

bool top_sort(){
	int hh = 0, tt = -1;

	//����ʼ���Ϊ0�ĵ����
	for(int i = 1;i <= n;i++)
		if(!d[i]) q[++tt] = i;
		
	while(hh <= tt){
		int t = q[hh++];//���ӽڵ�t��������Ľڵ�
		
		for(int i = h[t];i != -1;i = ne[i]) {
			int j = e[i];
			d[j]--;//j�ڵ����ȼ�һ
			if(d[j] == 0) q[++tt] = j;//�����Ϊ0�Ľڵ����
		}
	}
	
	return (tt == n - 1);//���е������֤��������������
}

int main(){
	cin >> n >> m;
	
	memset(h, -1, sizeof h);
	
	for(int i = 0;i < m;i++){
		int x, y;
		cin >> x >> y;
		add(x, y);
		d[y]++;
	}
	
	if(top_sort())
		for(int i = 0;i < n;i++) cout << q[i] << " ";
	else puts("-1");
}
