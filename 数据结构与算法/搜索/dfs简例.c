#include <stdio.h>
#include <stdlib.h>
int dfs(int x,int y){
  if(x==3 && y==4) {
    return 1;
  }
  else if(x>3 || y>4) return 0;
  else return dfs(x+1,y)+dfs(x,y+1);
}
int main(int argc, char *argv[])
{
  printf("%d",dfs(0,0));
  return 0;
}
