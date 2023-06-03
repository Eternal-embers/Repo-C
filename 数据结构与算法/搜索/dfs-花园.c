#include<stdio.h>
int res = 0;
int N,M;
int dx[4] = {0,0,-1,1};//上下左右
int dy[4] = {-1,1,0,0};//上下左右
char g[10000][10000];

void dfs(int x,int y){
	if(x >= 0 && x < M && y >= 0 && y < N && g[y][x] == 'w'){
		g[y][x] = '.';
		int i;
		for(i = 0;i < 4;i++){
			dfs(x + dx[i],y + dy[i]);
		}
	}
}

void show(int x,int y){
	int i,j;
	for(i = 0;i < N;i++){
		printf("%d ",i);
		for(j = 0;j < M;j++){
			if(i == y && j == x) printf("$ ");
			else printf("%c ",g[i][j]);
		}
		putchar('\n');
	}
	printf("- - - - - - - - -\n");
}

int main(){
	scanf("%d%d",&N,&M);
	int i,j;
	for(i = 0;i < N;i++)
		for(j = 0;j < M;j++)
			scanf(" %c",&g[i][j]);
    for(i = 0;i < N;i++)
		for(j = 0;j < M;j++){
			if(g[i][j] == 'w') {
				res++;
				dfs(j,i);
				show(j,i);
			}
		}
	printf("%d",res);
	return 0;
}

