#include <stdio.h>
#include <memory.h>

int main(int argc, char *argv[])
{
  int n,i,max = 0;
  scanf("%d",&n);
  int a[n],dp[n];//dp[i]表示以a[i]为结尾的最长递增序列
  memset(dp,0,sizeof(dp));
  for(i = 0;i<n;i++)
  scanf("%d",&a[i]);
  dp[0] = 0;
  for(i = 1;i<n;i++)
	if(a[i-1]<a[i]) dp[i] = dp[i-1]+1;
  for(i = 0;i<n;i++)
	if(dp[i]>max) max = dp[i];
  printf("%d",max+1);
  return 0;
}
