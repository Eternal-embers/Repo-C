#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int arr[26] = {0},i,min = 100,max = 0,ans;
  char ch;
  ch = getchar();
  while(ch!='\n'){
    arr[ch-'a']++;
    ch = getchar();
  }
  for(i = 0;i < 26;i++)
    if(arr[i]!=0){
      if(arr[i] > max) max = arr[i];
      if(arr[i] < min) min = arr[i];
    }
  ans = max - min;
  for(i = 2;i <= sqrt(i);i++)
    if(ans % i == 0) break;
  if(ans==0 || ans==1) printf("No Answer\n0");
  	else if(i > sqrt(i)) printf("Lucky Word\n%d",ans);
   		else printf("No Answer\n0");
  return 0;
}
