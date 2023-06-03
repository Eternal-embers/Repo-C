#include <stdio.h>
#include <stdlib.h>
int check(int n)
{
  int r;
  while(n)
  {
  	r=n%10;
    if(r!=2&&r!=0&&r!=1&&r!=9)return 0;
    n/=10;
  }
  return 1;
}
int main()
{
  // 请在此输入您的代码
  int i,count=0;
  long sum=0;
  for(i=1;i<=2019;i++)
  if(check(i))
  {
  sum=sum+i*i;
  printf(" %5d",i);
  count++;
  if(count%10==0)printf("\n");
  }   
  printf("\n  sum=%ld",sum);
  return 0;
}
