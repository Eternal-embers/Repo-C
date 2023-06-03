#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int month,day;
  char str[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  char (*p)[4]=&str[0];
  scanf("%d %d",&month,&day);
  printf("%s%02d",*(p+month-1),day);
  return 0;
}
