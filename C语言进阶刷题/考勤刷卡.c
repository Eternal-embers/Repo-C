#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int i,j,k,n,num[10000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%*d:%*d:%*d %d",&num[i]);
  }
  //选择排序
  for(i=0;i<n-1;i++){
    k=i;
    for(j=i+1;j<n;j++){
      if(num[k]>num[j])k=j;
    }
    if(k!=i){
    num[i]^=num[k];
    num[k]^=num[i];
    num[i]^=num[k];
	}
  }
  //输出
  printf("%d\n",num[0]);
  if(n==1)return 0;
  for(i=1;i<n;i++)
  if(num[i]!=num[i-1])printf("%d\n",num[i]);
  return 0;
}
