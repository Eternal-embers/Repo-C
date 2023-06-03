#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i;
  char str[201];
  gets(str);//遇到\n结束输入
  if(str[0]>='a' && str[0]<='z') {
    printf("%c",str[0]-32);//第一个字符是字母则大写 
    if(str[i+1]>='0' && str[i+1]<='9') printf("_");//后面有数字再输出一个_
  }
  else printf("%c",str[0]);//否则直接输出第一个字符
  for(i = 1;i<strlen(str);i++){
    if(str[i]>='a' && str[i]<='z')//如果是字母 
	  {
      if(str[i-1]>='0' && str[i-1]<='9') printf("_");//如果前面有数字先输出_
      if(str[i-1]==' ') printf("%c",str[i]-32);//如果是首字母则大写
        else printf("%c",str[i]);//否则小写
      if(str[i+1]>='0' && str[i+1]<='9') printf("_");//如果后面有数字则再输出一个_
    }
	    else if(str[i]==' ' && str[i-1]==' ')continue;//如果空格前面还是空格，不输出 
        else printf("%c",str[i]);//如果空格或者数字，直接输出
  }

  return 0;
}
