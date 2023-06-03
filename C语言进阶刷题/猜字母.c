#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  char alp[2015];
  int i,j;
  for(i = 0;i<=106;i++)
    for(j = 1;j<=19;j++)
    alp[19*i+j] = 'a'+j-1;
  for(i = 0;i<106;i++){
    for(j = 1;j<=19;j++)
    	printf("%c ",alp[19*i+j]); 
  printf("\n");
 }
  return 0;
}
