#include <stdio.h>
#include<math.h>
#include <memory.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int i,i3,i4;
  int arr[10] = {0};
  for(i = 12;;i++){
    i3 = pow(i,3);
    i4 = pow(i,4);
    memset(arr,0,sizeof(arr));
    while(i3>0){
      if(arr[i3%10]==0) arr[i3%10] = 1;
        else break;
      i3/=10;
    }
    while(i4>0){
      if(arr[i4%10]==0) arr[i4%10] = 1;
        else break;
        i4/=10;
    }
    if(i3==0 && i4==0) {
      printf("%d\n",i);
      return 0;
    }
  }
}
