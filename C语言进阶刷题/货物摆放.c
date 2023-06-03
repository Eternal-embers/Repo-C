#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  long long i,cnt = 0;
  int n = (int)sqrt(2021041820210418);;
  for(i = 0;i < n;i++)
	if(2021041820210418 % i == 0) cnt++;
  printf("%d",cnt);
  return 0;
}
