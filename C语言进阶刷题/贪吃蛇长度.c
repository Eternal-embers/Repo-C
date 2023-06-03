#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int count = 0,i;
  char str[] = "##################################@#####################@#######@#############################################################################@#########################################"; 
  for(i = 0;i<strlen(str);i++){
  if(str[i]=='#') count++;
  else if(str[i]=='@') count+=2;
  }
  printf("i=%d\n",i);
  printf("%d",count+2);
  return 0;
}
