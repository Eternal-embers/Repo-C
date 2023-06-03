#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int i,j;
  long n;
  scanf("%ld",&n);
  long arr[n];
  for(i=0;i<n;i++)
  scanf("%ld",&arr[i]);
  for(i=0;i<n;i++)
  for(j=n-1-i;j>0;j--)
  if(arr[j]<arr[j-1])
  {
    arr[j]=arr[j]^arr[j-1];
    arr[j-1]=arr[j]^arr[j-1];
    arr[j]=arr[j]^arr[j-1];
  }
  for(i=0;i<n;i++)
  printf("%d ",arr[i]);
  printf("\n");
  for(i=n-1;i>=0;i--)
  printf("%d ",arr[i]);
  return 0;
}
