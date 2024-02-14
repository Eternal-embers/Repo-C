#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100005;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//d[]存储各节点的入度

void add(int x, int y){
	e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

bool top_sort(){
	int hh = 0, tt = -1;

	//将初始入度为0的点入队
	for(int i = 1;i <= n;i++)
		if(!d[i]) q[++tt] = i;
		
	while(hh <= tt){
		int t = q[hh++];//出队节点t，已排序的节点
		
		for(int i = h[t];i != -1;i = ne[i]) {
			int j = e[i];
			d[j]--;//j节点的入度减一
			if(d[j] == 0) q[++tt] = j;//将入度为0的节点入队
		}
	}
	
	return (tt == n - 1);//所有点均排序证明存在拓扑序列
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
