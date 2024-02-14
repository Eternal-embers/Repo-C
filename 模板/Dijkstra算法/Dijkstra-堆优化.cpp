typedef pair<int, int> PII;

const int N = 150005;

int n, m;
int h[N], w[N], e[N], ne[N], idx;//w[]存储边的权值
int dist[N];//存储起点到各节点的最短距离
bool st[N];

//记录边a->b，权值为c
void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);

 	priority_queue<PII, vector<PII>, greater<PII>> heap;//默认对PII的first字段排序，排序greater为小根堆
	heap.push({0, 1});//pair的first字段存储距离，second字段存储节点索引
	dist[1] = 0;

	while(heap.size()){
		PII t = heap.top();
		heap.pop();

		int ver = t.second, d = t.first;
		if(st[ver]) continue;
		st[ver] = true;

		for(int i = h[ver]; i != -1; i = ne[i]){
			int j = e[i];

			if(d + w[i] < dist[j]) {
				dist[j] = d + w[i];
				heap.push({dist[j], j});
			}
		}
	}

	if(dist[n] == 0x3f3f3f3f) return -1;

	return dist[n];
}
