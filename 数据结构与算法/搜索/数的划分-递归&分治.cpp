/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date:07/29 12:39
	Description:���Ļ���-�ݹ�&����
*/
#include <stdio.h>
#include <stdlib.h>
int f(int n,int m){
  if(m==0||n==0||n<m)
    return 0;
  if(m==1||m==n)
      return 1;
  else
    return f(n-m,m) + f(n-1,m-1);
}

int main(int argc, char *argv[])
{
  int n,m;
  scanf("%d%d",&n,&m);
  printf("%d",f(n,m));
  return 0;
}
