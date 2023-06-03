#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,m,t,ans = 0;
  scanf("%d%d%d",&n,&m,&t);
  int g[n+1][m+1],i,j,k,r[t+1][2],c[t+1][2];
  for(i = 0;i <= n;i++)
    for(j = 0;j <= m;j++)
      g[i][j] = 0;
  for(i = 1;i <= t;i++){
    scanf("%d%d%d%d",&r[i][0],&c[i][0],&r[i][1],&c[i][1]);
  }
  for(i = 1;i <= t;i++){
    for(j = r[i][0];j <= r[i][1];j++)
      for(k = c[i][0];k <= c[i][1];k++){
        g[j][k] = 1;
      }
  }
  for(i = 1;i <= n;i++)
    for(j = 1;j <= m;j++)
      if(g[i][j] == 0) ans++;
  printf("%d",ans);
  return 0;
}
