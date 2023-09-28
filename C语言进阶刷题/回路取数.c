/*
	Name: 回形取数
	Copyright:劣等生
	Author:劣等生
	Date: 09/17 13:48
	Description:
*/
#include<stdio.h>

int M[205][205] = {0};//矩阵
int vis[205][205] = {0};//访问记录
//下右上左方向的坐标变换
int dx[4] = {0,1,0,-1};//水平方向
int dy[4] = {1,0,-1,0};//竖直方向

int main(){
	int m,n;//m,n小于200,m为行数，n为列数
	int i,j;
	scanf("%d %d",&m,&n);
	for(i = 0;i < m;i++){
		for(j = 0;j < n;j++){
			scanf("%d",&M[i][j]);
		}
	}
	i = 0,j = 0;//从左上角开始
	int dir = 0;//初始方向向下，下右上左分别对应索引0、1、2、3
	int sum = m * n;
	printf("%d",M[i][j]);
	vis[i][j] = 1;
	i += dy[dir],j += dx[dir];//循环从左上角下一个开始
	int cnt = 1;
	while(cnt < sum){
		//调整到合法位置
		while(i < 0 || i >= m || j < 0 || j >= n){
				//回退到上一个位置
				i -= dy[dir];
				j -= dx[dir];
				//左转
				dir += 1;
            	dir %= 4;
				//进入下一个位置
				i += dy[dir];
				j += dx[dir];
		}
		//判断是否访问过
		if(!vis[i][j]){
			printf(" %d",M[i][j]);
			cnt++;//计数
			vis[i][j] = 1;//记录访问
			i += dy[dir];
			j += dx[dir];
		}
        else{
        	//回退到上一个位置
			i -= dy[dir];
			j -= dx[dir];
			//左转
			dir += 1;
            dir %= 4;
			//进入下一个位置
			i += dy[dir];
			j += dx[dir];
		}
	}
	return 0;
}

/*
	测试1,输出1~25
	5 5
	1 16 15 14 13
	2 17 24 23 12
	3 18 25 22 11
	4 19 20 21 10
	5  6  7  8  9
 */

