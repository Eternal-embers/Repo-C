/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:回文日期
*/
/* 给定一个八位数表示初始日期，例如20200202，求下一个回文日期和下一个ABABBABA的回文日期 */
#include <stdio.h>
#include <stdlib.h>
//判断是否回文
int y[4],m[2],d[2];
_Bool check(int Y,int M,int D){
  y[0] = Y / 1000;
  y[1] = Y % 1000 / 100;
  y[2] = Y % 100 / 10;
  y[3] = Y % 10;
  m[0] = M / 10;
  m[1] = M % 10;
  d[0] = D / 10;
  d[1] = D % 10;
  if(y[0] == d[1] && y[1] == d[0] && y[2] == m[1] && y[3] == m[0])
  	return 1;
  else
    return 0;
}

int main(int argc, char *argv[])
{
  int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
  int Y,M,D,N,days,first = 0;
  scanf("%d",&N);
  Y = N / 10000;
  M = N / 100;
  D = N % 100;
  while(1){
    while(M <= 12){
      /* 判断此月最多多少天 */
      if(M == 2){
        if(Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) days = 28;
          else days = 29;
      }
        else days = month[M];
      /* 遍历这个月 */
      while(D <= days){
        if(check(Y,M,D)){
          if(first && y[0] == y[2] && y[1] == y[3]){
            printf("%d",Y * 10000 + M * 100 + D);//第二个回文日期且ABABBABA的回文日期
            return 0;
          }
          if(first == 0){
            printf("%d\n",Y * 10000 + M * 100 + D);//第一个回文日期
            first = 1;
          }
        }
        D++;
      }
      M++;
      D = 1;
   }
   Y++;
   M = 1;
 }
}
