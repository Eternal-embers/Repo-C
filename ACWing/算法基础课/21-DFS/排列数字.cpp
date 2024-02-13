#include<iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N];//st[i]标识数字i是否被排列

void dfs(int u){
	if(u == n){
		for(int i = 0;i < n;i++)
			printf("%d ", path[i]);
		puts("");
		return;
	}

	for(int i = 1;i <= n;i++)
		if(!st[i]) {
			path[u] = i;
			st[i] = true;
			dfs(u + 1);
			st[i] = false;//恢复现场
		}
}

int main(){
	scanf("%d", &n);
	
	dfs(0);
	
	return 0;
}
