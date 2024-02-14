#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100005, M = N * 2;//无向图，边数乘二

int n;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N;//删除重心后剩余连通块中点数的最大值

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//返回以u为根的子树中的节点数
int dfs(int u){
	st[u] = true;//标记u节点
	
	int sum = 1, res = 0;// sum为节点总数(初始量为u节点)
	
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!st[j]){
			int s = dfs(j);//s为以j为根的子树的节点数
			res = max(res, s);//res为枚举所有删除父节点后剩余连通块中点数的最大值
			sum += s;
		}
	}

 	//res为以u的各子树中的点数的最大值，n-sum为u的父节点所在连通块的最大值
	res = max(res, n - sum);
	
	ans = min(ans, res);//找出删除某节点后，剩余各个连通块中点数的最大值最小
	
	return sum;
}

int main(){
	cin >> n;

	memset(h, -1, sizeof h);
	
	for(int i = 0;i < n - 1;i++){
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	dfs(1);//节点为1-n
	
	cout << ans << endl;
	
	return 0;
}
