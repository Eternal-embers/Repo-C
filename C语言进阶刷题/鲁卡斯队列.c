#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
  float mem = 29,deno = 47,t1,t2;
  while(fabs(mem/deno-0.618034)>1e-6){
  t1 = mem;
  t2 = deno;
  mem = deno;
  deno = t1 + t2;
  }
  printf("%.0f/%.0f",mem,deno);
  return 0;
}
