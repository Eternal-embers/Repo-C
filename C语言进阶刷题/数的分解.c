#include <stdio.h>
#include <stdlib.h>
/*
把2019 分解成3 个各不相同的正整数之和，并且要求每个正整数都不包含数字2和4，一共有多少种不同的分解方法？
注意交换3 个整数的顺序被视为同一种方法，例如1000+1001+18 和1001+1000+18 被视为同一种。
*/
int check(int n)
{
while(n!=0)
{
  if(n%10==2||n%10==4)return 0;
  n/=10;
}
return 1;
}
int main(int argc, char *argv[])
{
  int a,b,c,sum=0;
  //从大到小排序，a>=b>=c,保证不重复
  for(a=1;a<=672;a++)//a<2019/3
  {
        for(b=a+1;b<1009;b++)//b<2019/2
        {
            c=2019-a-b;
            if(c<=0||c<=b)continue;
            if(check(a)==1&&check(b)==1&&check(c)==1)sum++;
         }
  }
  printf("%d\n",sum);
  return 0;
}
