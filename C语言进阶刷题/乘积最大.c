/*
	Name:乘积最大
	Copyright:劣等生
	Author:劣等生
	Date:08/27 17:50
	Description: 高精度+dfs
*/
#include<stdio.h>
#include<string.h>
#define LEN 45

int N,K;
int s[LEN],a[LEN],c[LEN],t[LEN],res[LEN];
int lastPos = 0;//上一个乘号位置的后一个数的索引

void clear(int a[]){
	int i;
	for(i = 0;i < LEN;i++)
		a[i] = 0;
}

void print(int a[]){
	int i;
	for(i = LEN - 1;i >= 1;i--)
		if(a[i] != 0) break;
	while(i >= 0)
		putchar(a[i--] + '0');
	putchar('\n');
}

/* 高精度乘高精度 */
void mult(int a[],int b[],int c[]) {
	clear(c);
	int i,j;
	for(i = 0;i < LEN - 1;++i){//计算第i位
		for(j = 0;j <= i;++j)
			c[i] += a[j] * b[i - j];//求出c[i]中第i位的数
		if(c[i] >= 10){//进位
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
}

//pos表示放置乘号的后一个数的索引，k记录已放置乘号的数量,c存储最终结果，t存储每次的暂时结果
void dfs(int s[],int pos,int k){
	if(k == N + 2){
		int i,len1,len2,flag = 0;
		for(i = LEN;i > 0;i--)
			if(c[i] != 0) {
				len1 = i + 1;
				break;
			}
		for(i = LEN;i >= 0;i--)
			if(res[i] != 0) {
				len2 = i + 1;
				break;
			}
  		/* 判断是否需要交换 */
		if(len1 > len2) flag = 1;//需要交换
		else if(len1 == len2){
			for(i = len1;i >= 0;i--)
				if(c[i] > res[i]) {
					flag = 1;
					break;
				}
				else break;
		}
		if(flag){
			//将更大的结果覆盖原先结果
			for(i = 0;i < LEN;i++)
				res[i] = c[i];
		}
		clear(c);
    		c[0] = 1;
		return;
	}
	else{
		print(a);
		print(c);
		print(res);
		putchar('\n');
		int i,j;
		/* 选择放乘号的位置，从pos后一位开始选 */
		for(i = pos + 1;i < N - K + k;i++){
			if(N + 2 - i > 0){
				int lastPos_t = lastPos;
				/* 将此次乘号与上次乘号之间的数赋给a */
				int len = pos - lastPos;
				clear(a);
				for(j = 0;j <= len;j++)
					a[j] = s[lastPos + j];
				/* 将a与上一次的结果相乘,计算结果放在t */
				mult(a,c,t);
				/* 将新的计算结果放在c */
				for(i = 0;i < LEN;i++)
			    	c[i] = t[i];
				dfs(s,i,k + 1);//继续放乘号
				lastPos = lastPos_t;//恢复这一次中上个乘号的位置
			}
		}
	}
}

int main(){
	int i;
	scanf("%d %d",&N,&K);
	char str[N + 1];
	scanf("%s",str);
	clear(s);
	for(i = 0;i < N;i++)
		s[N - i - 1] = str[i] - '0';
    clear(res);
    dfs(s,0,0);
    print(res);
	return 0;
}

