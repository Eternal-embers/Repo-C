#include <stdio.h>
#include <stdlib.h>
int count = 0;
int n,m;
void Hanoi(int n,char A,char B,char C){
  if(n==1) {
    count++;
    if(count==m) printf("#%d: %c->%c\n",n,A,C);//如果步数等于m输出此时的动作
    return;//当只有一个盘子时，只需从A盘移动到C盘
  }
  Hanoi(n-1,A,C,B);//第1~n-1个盘子从A移动到B盘
  count++;//第n个盘子从A盘移动到C盘
  if(count==m) printf("#%d: %c->%c\n",n,A,C);//如果步数等于m输出此时的动作
  Hanoi(n-1,B,A,C);//第1~n-1个盘子从B盘移动到C盘
}
int main(int argc, char *argv[])
{
  int N;
  scanf("%d%d",&n,&m);
  Hanoi(n,'A','B','C');
  printf("%d",count);
  return 0;
}
