#include <stdio.h>
#include <memory.h>

int main(int argc, char *argv[])
{
  int n,m;
  scanf("%d%d",&n,&m);
  int a[n+1][m+1],t,r,c,i,j,k,p,ans = 0;
  memset(a,0,sizeof(a));
  scanf("%d",&t);
  for(i = 0;i<t;i++){
    scanf("%d%d",&r,&c);
    a[r][c] = 2;
  }
  scanf("%d",&k);
for(p = 0;p<k;p++)
  for(i = 1;i<=n;i++)
    for(j = 1;j<=m;j++){
        if(a[i][j] == 2){
          if(i-1>=1) a[i-1][j] = 2;//ио
          if(i+1<=n && a[i+1][j]==0) a[i+1][j] = 1;//об
          if(j-1>=1) a[i][j-1] = 2;//вС
          if(j+1<=m && a[i][j+1]==0) a[i][j+1] = 1;//ср
        }
          else if(a[i][j] == 1 ) a[i][j]++;
      }
  for(i = 1;i<=n;i++){
    for(j = 1;j<=m;j++){
	  printf("%d ",a[i][j]);
      if(a[i][j]==2) ans++;
  	}
  printf("\n");
  }
  printf("%d",ans);
  return 0;
}
