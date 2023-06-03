#include <stdio.h>
#include <stdlib.h>
/*今年是 2020 年, 今天是 10 月 18 日。 请问在 1 到 2020 中, 有多少个数与 1018 互质。*/
int gcd(int a,int b){
  int t = 1;
  do{
    t = a % b;
    a = b;
    b = t;
  }while(t != 0);
  return a;
}
int main(int argc, char *argv[])
{
  int i,ans = 0;
  for(i = 1;i < 1018;i++)
    if(gcd(1018,i)==1) ans++;
  for(i = 1019;i <= 2020;i++)
    if(gcd(i,1018) == 1) ans++;
  printf("%d",ans);
  return 0;
}
