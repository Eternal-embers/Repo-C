#include <stdio.h>
#include <math.h>

int prime(int n){
int i;
for(i = 2;i<sqrt(n);i++) if(n%i==0) return 0;
return 1;
}

int main(int argc, char *argv[])
{
  int i,sum = 6,t,r;
  for(i = 53;i<20210605;i++){
    if(prime(i)){
    t = i;
      while(t>0){
      r = t%10;
      if(r==2||r==3||r==5||r==7)t/=10;
      else break;
      }
      if(t == 0) sum++;
    }
  }
  printf("%d",sum);
  return 0;
}
