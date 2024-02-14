int n, m;
int g[N][N];//邻接矩阵
int dist[N];//各点到启动的距离
bool st[N];//标识某点是否被选取过

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
	else return dist[n];
}
