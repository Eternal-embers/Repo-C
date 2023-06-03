#include <stdio.h>
char p[10];

int main(int argc, char *argv[])
{
  long long int m;
  scanf("%lld",&m);
  int i=0;
  while(m>0)
  {
     p[i++]=(m-1)%26+'A';
     m=m-(m-1)%26+1;
     m/=26;
  }
  p[i]='\0';
  for(i=i-1;i>=0;i--)
  	printf("%c",p[i]);
  return 0;
}
