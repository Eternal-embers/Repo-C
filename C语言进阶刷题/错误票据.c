#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int i,n,temp,count = 0;
  int arr[100001] = {0},repeat,empty,max = 0,min = 100001;
  char ch = '#';
  scanf("%d",&n);
  while(count<n){
        scanf("%d%c",&temp,&ch);
        if(ch=='\n')count++;
        if(temp > max) max = temp;
        if(temp < min) min = temp;
        if(arr[temp]==0) arr[temp] = 1;
        else repeat = temp;
  }
  for(i = min+1;i < max;i++)
  if(arr[i]==0){
  empty = i;
  break;
  }
  printf("%d %d",empty,repeat);
  return 0;
}
