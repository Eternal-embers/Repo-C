/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int n,i,j,t;
  scanf("%d",&n);
  /* 从n开始找，第一个找到的质因子即为结果 */
  for(i = 2;i < n;i++){
  	/* 如果是因子 */
	if(n % i == 0){
		t = n / i;
    	/* 判断是否是质数 */
    	for(j = 2;j <= sqrt(t);j++){
    	  if(t % j == 0) break;
   		}
   		if(j > sqrt(t)) {
     	 	printf("%d",t);
      		return 0;
    	}
    }
  }
}
