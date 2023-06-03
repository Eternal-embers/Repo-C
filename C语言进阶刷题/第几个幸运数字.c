#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  long long n = 59084709587505;
  long long i,j,k;
  int ans = 0;
  for(i=1;i<n;i*=3)//记录所有只含3的数中小于n的个数
    for(j=1;i*j<n;j*=5)//统计只含3，5的数中小于n的个数
      for(k=1;i*j*k<=n;k*=7)//统计只含3，5，7的数中小于n的个数
      ans++;
  printf("%d",ans-1);//由于把1统计进去了，所以个数需减一
  return 0;
}
