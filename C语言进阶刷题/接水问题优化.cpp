/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 08/02 12:46
	Description: 接水问题优化
*/
#include<stdio.h>

int w[10004];//接水量，w[i]表示第i个同学需要接w[i]的水
int cnt = 0;//记录接完水的人数

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for(i = 0;i < n;i++)
		scanf("%d",&w[i]);
	int k = m < n ? m : n;//k表示用于接水的水龙头数量
	int next = k;//下一个在排队的人的编号
	int t = 0;//计时
	while(cnt < n){
		
	}
	return 0;
}

