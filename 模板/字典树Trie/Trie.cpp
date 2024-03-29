#include<iostream>

using namespace std;

const int N = 100005;

int son[N][26], cnt[N], idx;//下标是0的点，即是根节点，又是空节点

void insert(char str[]){
	int p = 0;
	for(int i = 0;str[i];i++){
		int u = str[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	
	cnt[p]++;
}

int query(char str[]){
	int p = 0;
	for(int i = 0;str[i];i++){
		int u = str[i] - 'a';
		if(!son[p][u]) return 0;
		p = son[p][u];
	}
	
	return cnt[p];
}
