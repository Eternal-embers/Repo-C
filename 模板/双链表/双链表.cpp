int e[N], l[N], r[N], idx;

//头节点在索引0位置，尾节点在索引1位置
void init(){
	r[0] = 1, l[1] = 0;
	idx = 2;
}

//将x 插入到第 k 个插入的节点的后面
void add(int k, int x){
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	l[r[k]] = idx;
	r[k] = idx;
	idx++;
}

//移除第 k 个插入的节点
void remove(int k){
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
