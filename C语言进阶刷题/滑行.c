#include <stdio.h>
#include <stdlib.h>
int n,m;
int a[105][105];
int step = 0,max = 0;
/* 上下左右 */
int dx[4] = {0,0,-1,1};//列
int dy[4] = {-1,1,0,0};//行

void dfs(int x,int y){
    step++;//滑向一个位置，步数加一
    int i;
    //从(x,y)向上下左右依次搜索
    for(i = 0;i < 4;i++){
      //因为只能从高处滑向低处所以不需要判断是否走过，因为无法走之前的路
      int X = x + dx[i],Y = y + dy[i];
      if(X >= 0 && X < m && Y >= 0 && Y < n && a[Y][X] < a[y][x]){
        dfs(X,Y);
        step--;//回溯到原来的位置，步数还原
      }
      else if(step > max) max = step;//更新最大距离
    }
}

int main(int argc, char *argv[])
{
	int i,j;
  	scanf("%d %d",&n,&m);
  	for(i = 0;i < n;i++){
  	  	for(j = 0;j < m;j++){
      		scanf("%d",&a[i][j]);
      	}
	}
  	//对所有位置搜索穷举最大距离
  	for(i = 0;i < n;i++){
   	 	for(j = 0;j < m;j++){
   	 		step = 0;
     		dfs(j,i);
    	}
  	}
  	printf("%d",max);
  	return 0;
}
