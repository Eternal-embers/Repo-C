#include <stdio.h>
//计算2的11213次方减一的后一百位
int main()
{
    int add=0;
    int ans[100]={0},i,j;
    ans[0]=1;
    for(i=0;i<11213;i++)//对每已经计算出来的结果进行循环乘2
	{
        add=0;
        for(j=0;j<100;j++){
              ans[j]=2*ans[j]+add;//第j位数字乘2加上前一位的进位
              add=ans[j]/10;//下一位的进位
              ans[j]%=10;//求出第j位结果
        }
      }
      ans[0] -= 1;
      for(j=99;j>=0;j--){
        printf("%d",ans[j]);
      }
      return 0;
}
