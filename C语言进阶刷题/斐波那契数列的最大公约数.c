#include <stdio.h>
#include <stdlib.h>
int fn(int n)
{
  int pre,cur,sum,i;
  pre = cur = 1;
  for(i = 3;i<=n;i++){
  sum = pre + cur;
  pre = cur;
  cur = sum;
  }
  return sum;
}

int gcd(int a,int b)
{
  int r;
  while(b>0){
    r = a %b;
    a = b;
    b = r;
  }
  return a;
}

int main(int argc, char *argv[])
{
  printf("%d",fn(gcd(2020,520)));//斐波那契数列最大公约数定理：gcd(Fn, Fm) = F(gcd(n, m))
}
