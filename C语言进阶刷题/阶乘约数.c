#include <stdio.h>
#include <stdlib.h>
//利用约数个数定理，1到100每个数可以找出它们的质因数
//再统计其中1-100的质因数作为因子出现的次数，每个加一在相乘即可得出约数个数
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
 int prime[25] ={ 2,3, 5,7, 11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
 int num[25] = {0};
 int i,j,temp;
 long long count = 1;
 for(i = 2;i<=100;i++){
   temp = i;
   j = 0;//遍历100以内素数统计100以内的素数作为因子出现的次数
   while(temp > 1 && temp>=prime[j]){
   if(temp%prime[j]==0){
   temp/=prime[j];
   num[j]++;
   }
   else j++;
   }
 }
 for(i = 0;i<25;i++)
 if(num[i]>0) count*=(num[i]+1);
 printf("%lld",count);
 return 0;
}
