#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char s[1000];
  int i,a[26]={0},min = 1000,max = 0;
  gets(s);
  for(i = 0;i < strlen(s);i++){
    a[s[i]-'a']++;
  }
  for(i = 0;i < 26 ;i++){
    if(a[i]>0 && min>a[i]) min = a[i];
    else if(max < a[i]) max = a[i];
  }
  printf("%d",max-min);
  return 0;
}
