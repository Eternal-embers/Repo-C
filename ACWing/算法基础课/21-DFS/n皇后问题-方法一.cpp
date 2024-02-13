#include<iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

//x表示将在第x行放置皇后，前x行的每一行都放置了皇后
void dfs(int x){
	if(x == n){
		for(int i = 0;i < n;i++) puts(g[i]);
		puts("");
	}
	
	for(int y = 0;y < n;y++)
		if(!col[y] && !dg[y + x] && !udg[y - x + n]){
			//标记
			g[x][y] = 'Q';
			col[y] = dg[y + x] = udg[y - x + n] = true;
			
			dfs(x + 1);//在第x + 1行放置下一个皇后
			
			//恢复现场
			col[y] = dg[y + x] = udg[y - x + n] = false;
			g[x][y] = '.';
		}
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			g[i][j] = '.';

	dfs(0);

	return 0;
}
