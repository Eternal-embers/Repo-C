#include <stdio.h>
#include <stdlib.h>
int cnt,ans = 0;
int ax,ay,bx,by,n;
char a[100][100];
int  g[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int min(int a,int b){
  return a < b ? a : b;
}
void dfs(int x,int y,int flag){
  if(g[x][y]==0) {
    ans = min(cnt,ans);
    cnt = 0;
    g[ax][ay] = 0;
    return;
  }
  if(g[x][y] == 0) g[x][y]==2;
  if(x >= 0 && x < n && y > 0 && y < n && flag > -2 && flag < 2){
    cnt++;
    int i;
    for(i = 0;i < 4;i++)
      dfs(x + dx[i],y + dy[i],flag + g[x + dx[i]][y + dy[i]]);
  }
  else {
    cnt = 0;
    flag = 0;
	g[ax][ay] = 0;
  }
}
int main(int argc, char *argv[])
{
  int i,j;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++)
      scanf(" %c",&a[i][j]);
  }
  
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      if(a[i][j]=='A') {
        ax = i;
        ay = j;
        g[i][j] = 0;
      }
      else if(a[i][j]=='B'){
        bx = i;
        by = j;
        g[i][j] = 0;
      }
      else if(a[i][j]=='-') g[i][j] = -1;
      else g[i][j] = 1;
    }
  }
  /*
  for(i = 0;i < n;i++){
  	for(j = 0;j < n;j++)
		printf("%d ",g[i][j]);
	putchar('\n');
  }
  */
  for(i = 0;i < 4;i++)
      dfs(ax + dx[i],ay + dy[i],0 + g[ax + dx[i]][ay + dy[i]]);
  if(ans == 0) printf("-1");
  else printf("%d",ans);
  return 0;
}
