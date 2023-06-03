#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int count=0;
int queen(int t,int n)
{
  _Bool flag;
  int i,j;
  extern arr[n];
  if(t==n)count++;
  else
      for(i=0;i<n;i++)
      {
      arr[t]=i;//第t行皇后放置在第i+1个
      for(j=0;j<t;j++){
        if(arr[t]==arr[j]){flag=0;break;}
        if((t-j)==abs(arr[t]-arr[j])&&t-j<3){flag=0;break;}
      }
      if(flag==1)queen(t+1,n);
      }
}
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int n;
  scanf("%d",&n);
  int arr[n];
  queen(0,n);
  printf("%d",count);
  return 0;
}
