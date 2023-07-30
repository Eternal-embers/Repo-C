/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 7/29 08:59
	Description: 解立方根
*/
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int T;
  scanf("%d",&T);
  int a[T],i;
  double ans[T];
  for(i = 0;i < T;i++)
    scanf("%d",&a[i]);
  for(i = 0;i < T;i++)
    ans[i] = pow(a[i],1.0/3.0);
  for(i = 0;i < T;i++)
    printf("%.3f\n",ans[i]);
  return 0;
}
