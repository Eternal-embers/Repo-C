int n, m;
int g[N][N];//�ڽӾ���
int dist[N];//���㵽�����ľ���
bool st[N];//��ʶĳ���Ƿ�ѡȡ��

int dijkstra(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for(int i = 1;i <= n;i++){
		int t = -1;
		//��ȡһ������ѡ�ڵ��������ĵ�
		for(int j = 1;j <= n;j++){
			if(!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}

		st[t] = true;

		//������㵽������ľ��룬(1->j) vs (1->t->j)
		for(int j = 1;j <= n;j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}

	if(dist[n] == 0x3f3f3f3f) return -1;
	else return dist[n];
}
