#include <stdio.h>
#include <stdlib.h>
/*
小蓝特别喜欢2，今年是公元2020 年，他特别高兴，因为每天日历上都可以看到2
如果日历中只显示年月日，请问从公元1900 年1 月1 日到公元9999 年
12 月31 日，一共有多少天日历上包含2。即有多少天中年月日的数位中包含数字2。
*/
int main(int argc, char *argv[])
{
  int year,days = 0,temp,flag;
  for(year = 1900;year < 10000;year++){
  temp = year;
  flag = 0;
  while(temp){
  if(temp%10==2){
    flag = 1;
    break;
  }
  temp/=10;
  }
  if(flag==1){
  if(year%4==0 && year%100!=0 || year%400==0) days+=366;
  else days+=365;
  }
    else if(year%4==0 && year%100!=0 || year%400==0)  days+=180;
      else days+=179;
  }
  printf("%d",days);
  return 0;
}
