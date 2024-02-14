typedef pair<int, int> PII;

const int N = 150005;

int n, m;
int h[N], w[N], e[N], ne[N], idx;//w[]�洢�ߵ�Ȩֵ
int dist[N];//�洢��㵽���ڵ����̾���
bool st[N];

//��¼��a->b��ȨֵΪc
void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);

 	priority_queue<PII, vector<PII>, greater<PII>> heap;//Ĭ�϶�PII��first�ֶ���������greaterΪС����
	heap.push({0, 1});//pair��first�ֶδ洢���룬second�ֶδ洢�ڵ�����
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
