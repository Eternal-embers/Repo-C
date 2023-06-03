#include <stdio.h>
#include <stdlib.h>
int sum(int n){
 int s = 0;
 while(n>0){
 s+=n%10;
 n/=10;
}
return s;
}

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int n,m,i,j,k = 0;
  scanf("%d%d",&n,&m);
  int arr[n];
  for(i = 1;i<54;i++)
    for(j = 1;j < n+1;j++)
      if(sum(j)==i) arr[k++] = j;
  printf("%d",arr[m-1]);
  return 0;
}
