#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char s[100];
  int i;
  gets(s);
  for(i = 0;i<strlen(s);i++){
    if(s[i]>='a' && s[i]<='z') printf("%c",s[i]-32);
    else printf("%c",s[i]);
  }
  return 0;
}
