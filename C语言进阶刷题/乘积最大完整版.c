/*
	Name: 乘积最大完整答案
	Copyright:劣等生
	Author:劣等生
	Date:08/28 12:05
	Description: dp + 高精度
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct BigInt{
	int len;
	int num[50];
}dp[50][50],sum[50][50],c;//dp[n][k]表示区间长度为n，乘号数为k时取得的最大数

int N,K;
char s[50];

void print(struct BigInt *a){
	int i;
 	for(i = a->len;i >= 1;i--)
		putchar(a->num[i] + '0');
	putchar('\n');
}

/* 判断a是否大于b */
int max(struct BigInt *a,struct BigInt *b){
	if(a->len > b->len) return 1;
	else if(a->len < b->len) return 0;
	else{
		int i;
		for(i = a->len;i >= 1;--i){
			if(a->num[i] > b->num[i]) return 1;
			else if(a->num[i] < b->num[i]) return 0;
		}
		return 0;//两数相等
	}
}

void mult(struct BigInt *a,struct BigInt *b){
	memset(c.num,0,sizeof(c));//清空c
	int i,j;
	for(i = 1;i < 50;++i){//计算第i位
		for(j = 1;j <= i;++j){
            c.num[i] += a->num[j] * b->num[i - j + 1];
		}
		if(c.num[i] >= 10){
            c.num[i + 1] += c.num[i] / 10;
            c.num[i] %= 10;
		}
	}
	for(i = 49;i >= 1;--i)
		if(c.num[i] != 0) break;
	c.len = i;
}

int main(){
	scanf("%d %d",&N,&K);
	scanf("%s",s + 1);//索引从1开始
	int i,j,n,k;

	for(i = 1;i <= N;i++){
		//dp[i][0]为字符串前i个组成的数
		dp[i][0].len = i;
		for(j = 1;j <= i;j++)
			dp[i][0].num[i - j + 1] = s[j] - '0';//区间为i，不放乘号
			
		//dp[i][j]设为0
		for(j = 1;j <= N;j++){
			memset(dp[i][j].num,0,sizeof(dp[i][j].num));
			dp[i][j].len = 0;
		}
	}
	
	for(i = 1;i <= N;i++){
		for(j = 1;j <= N;j++){
			memset(sum[i][j].num,0,sizeof(sum[i][j].num));
			for(k = i;k <= j;k++)//将数字串从第i个到第j组成的数字放在sum[i][j]
				sum[i][j].num[j - k + 1] = s[k] - '0';
			sum[i][j].len = j - i + 1;
		}
	}

	for(n = 1;n <= N;n++){//区间长度
		for(k = 1;k < n;k++){//乘号数量
			for(i = k;i <= n;i++){//选择放置位置
				mult(&dp[i][k - 1],&sum[i + 1][n]);//计算结果在c中
				if(max(&c,&dp[n][k]))
					dp[n][k] = c;//更新结果
			}
		}
	}
	print(&dp[N][K]);
	return 0;
}

