#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a,b,c;
  scanf("%d%d",&a,&b);
  if(a < b){
    c = a;
    a = b;
    b = c;
  }
  while(a!=b){
  	c = a - b;
  	if(c > b) a = c;
  	else {
	   a = b;
	   b = c;
	}
  }
  printf("%d",a);
  return 0;
}
