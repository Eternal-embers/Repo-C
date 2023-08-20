/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 08/02 12:06
	Description: 接水问题
*/
#include<stdio.h>

int w[10004];//接水量，w[i]表示第i个同学需要接w[i]的水
int u[10004];//水龙头，u[i]表示第i个水龙头需要接u[i]的水
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
	/* 1~k号的同学去接水，1~k号水龙头分别分配w[0]...w[k-1]的接水量 */
	for(i = 0;i < k;i++)
		u[i] = w[i];
	while(cnt < n){
		/* 对一秒后的水龙头逐一处理 */
        for(i = 0;i < m;i++){
			u[i]--;//接水一秒
			if(u[i] == 0){
				cnt++;//完成人数加1
				if(next < n)
					u[i] = w[next++];//给空出来的第i-1号水龙头立即分配下一个排队同学的接水量
				else u[i] = -1;//第i-1个水龙头不再接水
			}
		}
		t++;//计时加1
	}
	printf("%d",t);
	return 0;
}

