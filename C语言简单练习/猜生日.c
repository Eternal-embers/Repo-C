#include <stdio.h>
#include<stdlib.h>
int main()
{
  // 请在此输入您的代码
  int year,day,num;
  for(year=1992;year>=1950;year--)
  for(day=1;day<=30;day++)
  {
    num=year*10000+600+day;
    if(num%2012==0&&num%3==0&&num%12==0)
    {
      printf("%d",num);
      system("pause");
      return 0;
    }
  }
}
