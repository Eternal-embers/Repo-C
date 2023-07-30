#include<stdio.h>
#define INF 0x7fffffff

int N,M;
int g[105][105];
int dir[105][105];
int x1,y1,x2,y2;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int res = INF;

void dfs(int x,int y,int step){
	if(x == x2 && y == y2){
		res = res > step ? step : res;
	}
	else {
		int i;
		for(i = 0;i < 4;i++){
			int a = x + dx[i];
			int b = y + dy[i];
			if(a >= 1 && a <= N && b >= 1 && b <= M && g[a][b] == 1 && step + 1 < dir[a][b]){
        		dir[a][b] = step + 1;
				dfs(a,b,step + 1);
			}
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	int i,j;
	for(i = 1;i <= N;i++){
		for(j = 1;j <= M;j++){
			scanf("%d",&g[i][j]);
		}
	}
	for(i = 1;i <= N;i++){
		for(j = 1;j <= M;j++){
			dir[i][j] = INF;
		}
	}
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	dfs(x1,y1,0);
 	printf("%d",res != INF ? res : -1);
	return 0;
}

