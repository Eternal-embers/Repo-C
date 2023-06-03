#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int ans[26]={0},max = 0,i;
  char ch;
  while(1){
    ch = getchar();
    if(ch=='\n')break;
    else ans[ch-'A']++;
  }
  for(i = 0;i<26;i++)
  if(ans[i]>max) max = ans[i];
  for(i = 0;i<26;i++)
  if(ans[i]==max) printf("%c",'A'+i);
  return 0;
}
