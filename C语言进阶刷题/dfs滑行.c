#include<stdio.h>
#include<stdlib.h>
int h[100][100] = {0};
_Bool f[100][100] = {0};
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dfs(int x,int y){
	int res = 0,i;
	for(i = 0;i < 4;i++){
		//a,b为循环内的临时变量
		int a = x + dx[i];
		int b = y + dy[i];
		if(a>=0 && a<n && b>=0 && b<m && !f[a][b] && h[x][y]>h[a][b]){
			f[a][b] = 1;//已经走过
			res = max(res,dfs(a,b)+1);
			//还原现场
			f[a][b] = 0;
		}
	}
	return res;
}
int max(int a,int b){
	return a > b ? a : b;
}
int main()
{
	int i,j,ans = 0;
	scanf("%d%d",&n,&m);
	for(i = 0;i < n;i++)
		for(j = 0;j < m;j++)
			scanf("%d",&h[i][j]);
	for(i = 0;i < n;i++)
		for(j = 0;j < m;j++){
			f[i][j] = 1;
			ans = max(ans,dfs(i,j));
			f[i][j] = 0;
		}
	printf("%d",ans+1);
	return 0;
}
