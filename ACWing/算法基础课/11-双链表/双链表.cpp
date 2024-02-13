#include<iostream>

using namespace std;

const int N = 100005;

int m;

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

int main(){
	cin >> m;
	
	init();
	
	while(m--){
		int k, x;
		string op;
		
		cin >> op;
		if(op == "L"){
			cin >> x;
			add(0, x);
		}
		else if(op == "R"){
			cin >> x;
			add(l[1], x);
		}
		else if(op == "D"){
			cin >> k;
			remove(k + 1);
		}
		else if(op == "IL"){
			cin >> k >> x;
			add(l[k + 1], x);
		}
		else {
			cin >> k >> x;
			add(k + 1, x);
		}
	}
	
	for(int i = r[0];i != 1; i = r[i]) cout << e[i] << ' ';
	cout << endl;
	
	return 0;
}
