/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
	return a > b ? a : b;
}
int main(int argc, char *argv[])
{
  int N;
  scanf("%d",&N);
  int i,j,a[100][100] = {0};
  /* 输入 */
  for(i = 0;i < N;i++)
  	for(j = 0;j <= i;j++){
    	scanf("%d",&a[i][j]);
  	}
  /* 初始化dp数组 */
  int dp[100][100] = {0};
  dp[0][0] = a[0][0];
  /* 求dp数组 */
  for(i = 1;i < N;i++){
	for(j = 0;j <= i;j++){
		if(j == 0) dp[i][j] = dp[i-1][0] + a[i][j];
            else if(j == i) dp[i][j] = dp[i-1][j-1] + a[i][j];
				else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
	}
  }
  /* 输出 */
  /* 由于向左或右走的步数相等，故最后到达点一定在最后一行最中间的位置 */
  if(N % 2 == 0) printf("%d",max(dp[N-1][N/2],dp[N-1][N/2-1]));//N为偶数，取dp数组第N行中间两个数中最大的
  else printf("%d",dp[N-1][N/2]);//N为奇数
  return 0;
}
