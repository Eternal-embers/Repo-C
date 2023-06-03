#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int prime[11] = {2,3,5,7,11,13,17,19,23,29,31};//可以筛选1000以内的素数
  _Bool res[1001] = {0};
  int i,j,cnt = 0,n;
  scanf("%d",&n);
  for(i = 0;i < 11;i++){
    res[prime[i]] = 1;
  }
  for(i = 32;i < 1001;i++){
    for(j = 0;j < 11;j++){
      if(i % prime[j] == 0) break;
    }
    if(j == 11) {
      res[i] = 1;
    }
  }
  for(i = 1;i < n;i++){
    if(res[i]) {
		printf("%d ",i);
		cnt++;
	}
  }
  printf("\n%d",cnt);
  return 0;
}
