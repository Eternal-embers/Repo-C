#include <stdio.h>
#include <stdlib.h>
int fun(int m)
{
  while(m!=0)
  {
  if(m%10==2||m%10==0||m%10==1||m%10==9)return 1;
  m/=10;
  }
  return 0;
}
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int n,i,sum=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  if(fun(i)==1)sum+=i;
  }
  printf("%d",sum);
  system("pause"); 
  return 0;
}
