#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int arr[10] = {0},i,j,sum = 0;
  char s[14];
  scanf("%s",s);
  for(i = 0,j = 0;j<14;j++)
    if(s[j]!='-') arr[i++] = s[j]-48;
  for(i = 0;i<9;i++)
    sum += arr[i]*(i+1);
  if(sum % 11==10){
    if(s[12]=='X') printf("Right");
    else printf("%d-%d%d%d-%d%d%d%d%d-X",
    arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8]);
  }
  else {
    if(sum % 11==arr[9]) printf("Right");
    else {
      arr[9] = sum % 11;
      printf("%d-%d%d%d-%d%d%d%d%d-%d",
      arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9]);
    }
  }
  return 0;
}
