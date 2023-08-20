/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:07/30 20:08
	Description: 数字三角形-进阶难度
*/
#include<stdio.h>

int max(int a,int b){
	return a > b ? a : b;
}
int N;
int a[104][104] = {0};
int dp[104][104] = {0};

int main(){
	freopen("数字三角形3.txt","r",stdin);
	scanf("%d",&N);
	int i,j;
	for(i = 1;i <= N;i++){
		for(j = 1;j <= i;j++){
			scanf("%d",&a[i][j]);
		}
	}
	/*
        自底向下，动态规划
        由于路径上的每一步只能从一个数走到下一层和它最近的左边的那个数或者右边的那个数。
		此外，向左下走的次数与向右下走的次数相差不能超过 1。
		我们找规律可以发现如果要是实现上面的要求，那么最终到达一定是到达底层的中间位置
		即中位数的位置，对于第N层，如果N为奇数，那么最终只能到(N + 1)/2和N/2的位置
		如果N为奇数，那么最终只能到达N/2 + 1的位置
	*/
	dp[1][1] = a[1][1];
	for(i = 1;i <= N;i++){
		for(j = 1;j <= i;j++){
			dp[i][j] = max(dp[i - 1][j - 1],dp[i - 1][j]) + a[i][j];
		}
	}
	if(N % 2 == 1) printf("%d",dp[N][N/2 + 1]);
	else printf("%d",max(dp[N][N/2],dp[N][N/2 + 1]));
	return 0;
}

