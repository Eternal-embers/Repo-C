#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i = 47,j,k,t2,t3,a[10],flag;
  while(1)
  {
    t2 = i*i;
    t3 = i*i*i;
    a[0] = t2%10;
    a[1] = t2/10%10;
    a[2] = t2/100%10;
    a[3] = t2/1000;
    a[4] = t3%10;
    a[5] = t3/10%10;
    a[6] = t3/100%10;
    a[7] = t3/1000%10;
    a[8] = t3/10000%10;
    a[9] = t3/100000;
    for(j = 0;j<9;j++){
      flag = 1;
      for(k = j+1;k<10;k++)
        if(a[j] == a[k]) {
          flag = 0;
          break;
        }
    if(flag == 0) break;
    }
    if(j==9) {
      printf("%d",i);
      break;
    }
	i++;
  }
  return 0;
}
