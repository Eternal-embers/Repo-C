#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100005;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N];

void add(int a, int b){
	e[idx] = b,ne[idx] = h[a], h[a] = idx++;
}

int bfs(){
	int hh = 0, tt = 0;
	q[0] = 1;//将1号节点入队
	
	memset(d, -1, sizeof d);
	
	d[1] = 0;//设置到一号节点的距离
	
	while(hh <= tt){
		int t = q[hh++];
		
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(d[j] == -1){//更新未计算的节点的最短距离
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	}
	
	return d[n];
}

int main(){
	cin >> n >> m;

	memset(h, -1, sizeof h);
	
	for(int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	
	cout << bfs() << endl;
	
	return 0;
}
