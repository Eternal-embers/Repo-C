#include<iostream>

using namespace std;

const int N = 100005;

/*
    e[] 数组存储节点的值， n[] 数组存储节点的next指针
	head 为头节点在 e[] 和 n[]  中的索引
	idx 为下一个要插入的节点索引
*/
int head, idx;
int e[N], ne[N];

/* 初始化 */
void init(){
	head = -1;
	idx = 0;
}

/* 将 x 插入到头节点 */
void add_to_head(int x){
	e[idx] = x, ne[idx] = head, head = idx++;
}

/* 将 x 插入到下标是 k 的节点后面 */
void add(int k, int x){
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

/* 将下标是 k 的节点后面的节点删除 */
void remove(int k){
	ne[k] = ne[ne[k]];
}

int main(){
	int m;
	cin >> m;
	
	init();

	while(m--){
		int k, x;
		char op;
		cin >> op;
		if(op == 'H'){
			cin >> x;
			add_to_head(x);
		}
		else if(op == 'D'){
			cin >> k;
			if(!k) head = ne[head];
			remove(k - 1);
		}
		else if(op == 'I'){
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	
	for(int i = head;i != -1;i = ne[i])
		cout << e[i] << ' ';
	cout << endl;

	return 0;
}
