#include<stdio.h>
#include<stdlib.h>
#define LEN 100
int m,n;
char pos[LEN][LEN];
int sx,sy;//起点坐标
int ex[5] = {-1,-1,-1,-1,-1};//终点坐标
int ey[5] = {-1,-1,-1,-1,-1};//终点坐标
_Bool vis[LEN][LEN] = {0};
int dx[4] = {-1,1,0,0};//上下左右
int dy[4] = {0,0,-1,1};//上下左右
int end = 0;

_Bool in(int x,int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

_Bool dfs(int x,int y){
	vis[x][y] = 1;//标记走过的地方
	if(pos[x][y] == 'T') {//到达终点
		ex[end] = x;
		ey[end] = y;
		pos[x][y] = 'T';
		end++;
		return 1;
	}
	else {
		int i;
		for(i = 0;i < 4;i++){
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(!vis[tx][ty] && in(tx,ty) &&  pos[tx][ty]!='*'){
				//!vis[tx][ty]：(tx,ty)位置未访问过
				//in(tx,ty)：(tx,ty)位置可以进入,未越界
				//pos[tx][ty]!='*':(tx,ty)位置不是墙
				if(dfs(tx,ty)) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d%d",&m,&n);
	getchar();
	int i,j;
	for(i = 0;i < n;i++){//行
		for(j = 0;j < m;j++){//列
   			scanf(" %c",&pos[i][j]);
		}
	}
	printf("\n");
	for(i = 0;i < n;i++){//行
		for(j = 0;j < m;j++){//列
   			printf("%c ",pos[i][j]);
		}
		putchar('\n');
	}
    for(i = 0;i < n;++i)
		for(j = 0;j < n;++j){
			if(pos[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	if(dfs(sx,sy)) puts("Yes");
		else puts("No");
    for(i = 0;i < 5;i++)
		if(ex[i] != -1) printf("终点坐标(%d,%d)\n",ex[i],ey[i]);
			else break;
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++)
			printf("%d ",vis[i][j]);
		printf("\n");
	}
	return 0;
}
