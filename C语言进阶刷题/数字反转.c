#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int num,arr[10],i,j,flag = 1;
  scanf("%d",&num);
  if(num==0) {
    printf("0");
    return;
  }
  if(num < 0){
    num = -num;
    flag = 0;
  }
  i = 0;
  while(num > 0){
    arr[i++] = num % 10;
    num/=10;
  }
  if(flag==0) printf("-");
  j = 0;
  flag = 0;
  while(j < i){
    if(arr[j] > 0) flag = 1;
    if(flag == 1) printf("%d",arr[j]);
    j++;
  }
  return 0;
}
