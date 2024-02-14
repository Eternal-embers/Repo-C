#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 505;

int n, m;
int g[N][N];//邻接矩阵
int dist[N];
bool st[N];

int dijkstra(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for(int i = 1;i <= n;i++){
		int t = -1;
		//获取一个与已选节点距离最近的点
		for(int j = 1;j <= n;j++){
			if(!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}
		
		st[t] = true;
		
		//更新起点到其他点的距离，(1->j) vs (1->t->j)
		for(int j = 1;j <= n;j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	
	if(dist[n] == 0x3f3f3f3f) return -1;

	return dist[n];
}

int main(){
	scanf("%d%d", &n, &m);

	memset(g, 0x3f, sizeof g);
	
	for(int i = 0;i < m;i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if(z < g[x][y]) g[x][y] = z;
	}
	
	printf("%d", dijkstra());
	
	return 0;
}
