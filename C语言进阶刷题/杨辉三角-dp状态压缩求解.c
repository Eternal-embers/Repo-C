/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:23/03/23 14:41
	Description:通过状态压缩求解杨辉三角
*/
#include<stdio.h>
long long f(int rows,int cols){
	if(cols == 0 || cols == rows) return 1;
	else if(cols == 1) return rows;
	int dp[1024],p,q;//行和列从0开始计数
	dp[0] = 1;
	dp[1] = 1;
	p = 2;//从第三行开始
	while(p <= rows){
		for(q = p;q > 0;q--){
			dp[q] = dp[q] + dp[q-1];//由于每次计算只需要上一层的值，故可以进行状态压缩
		}
		p++;
	}
	return dp[cols];
}
int main(){
	int rows,cols;
	printf("rows = ");
	scanf("%d",&rows);
	printf("cols = ");
	scanf("%d",&cols);
	printf("f(%d,%d) = %lld",rows,cols,f(rows,cols));
	return 0;
}

