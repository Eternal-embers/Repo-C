#include <stdio.h>
#include <memory.h>

int main(int argc, char *argv[])
{
  int n,m,i,j,k;
  scanf("%d%d",&n,&m);
  int a[n+1][m+1],dp[n+1][m+1];//dp[i][j]表示从第一行第一列走到第i行第j列所取得的最大权
  int row[9] = {0,0,0,-1,-2,-3,-1,-1,-2};
  int col[9] = {-1,-2,-3,0,0,0,-1,-2,-1};
  memset(dp,1e-10,sizeof(dp));
  for(i = 1;i<=n;i++)
    for(j = 1;j<=m;j++)
      scanf("%d",&a[i][j]);
  dp[1][1] = a[1][1];
  for(i = 1;i<=n;i++)
    for(j = 1;j<=m;j++){
      for(k = 0;k<9;k++)
      if(i+row[k]>=1 && j+col[k]>=1) {
        if(dp[i][j]<dp[i+row[k]][j+col[k]]+a[i][j]) dp[i][j] = dp[i+row[k]][j+col[k]]+a[i][j];
      }
    }
  printf("%d",dp[n][m]);
  return 0;
}
