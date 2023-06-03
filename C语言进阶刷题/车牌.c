#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*
A 市的车牌由六位组成, 其中前三位可能为数字 0 至 9 , 或者字母A 至F, 每位有 16 种可能。
后三位只能是数字 0 至 9。为了减少攀比, 车牌中不能有连 续三位是相同的字符。
例如, 202020 是合法的车牌, AAA202 不是合法的车牌, 因为前三个字 母相同。请问, A 市有多少个合法的车牌?
*/
_Bool check(char *p)
{
  int i; 
  for(i=0;i<4;i++)
  {
  if(*(p+i)==*(p+i+1)&&*(p+i)==*(p+i+2))return 0;
  }
  return 1;
}
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  char str[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  char arr[6];
  char *p=&str[0];
  short i,j,k,m,n,r;
  long count=0;
  for(i=0;i<16;i++){
    arr[0]=*(p+i);
    for(j=0;j<16;j++){
      arr[1]=*(p+j);
      for(k=0;k<16;k++){
        arr[2]=*(p+k);
        for(m=0;m<10;m++){
          arr[3]=*(p+m);
          for(n=0;n<10;n++){
            arr[4]=*(p+n);
            for(r=0;r<10;r++){
              arr[5]=*(p+r);
              if(check(&arr[0]))count++;
            }
          }
        }
      }
    }
  }
  printf("%ld",count);
  return 0;
}
