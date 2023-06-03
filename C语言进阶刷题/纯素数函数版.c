#include <stdio.h>
#include <math.h>

int prime(int n){
int i;
for(i = 2;i<sqrt(n);i++) if(n%i==0) return 0;
return 1;
}

int pure(int t){
while(t>0){
  if(t%10==2||t%10==3||t%10==5||t%10==7)t/=10;
  else return 0;
  }
  return 1;
}

int main(int argc, char *argv[])
{
  int i,sum = 6,t;
  for(i = 53;i<20210605;i++) 
  if(pure(i) && prime(i))sum++;
  printf("%d",sum);
  return 0;
}
