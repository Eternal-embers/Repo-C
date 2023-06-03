#include <stdio.h>
#include <stdlib.h>
int count = 0;
void fun(int a,int b,int wine){
  if(a==0 && b==0 && wine==0) count++;
    else if(wine <= 0 || a < 0 || b < 0) return;
  fun(a-1,b,wine*2);//Óöµ½µê
  fun(a,b-1,wine-1);//Óöµ½»¨
}

int main(int argc, char *argv[])
{
  fun(5,10,2);
  printf("%d",count);
  return 0;
}
