#include<stdio.h>
#include<string.h>
int main()
{
  char S[1000],T[1000];
  int i,j,k,lens,lent,len,count,max = 0;
  gets(S);
  gets(T);
  lens = strlen(S);
  lent = strlen(T);
  len = lens - lent;
  for(i = 0;i<=len;i++){
    k = i;
    count = 0;
    for(j = 0;j<lent;j++,k++){
    if(S[k]==T[j]) count++;
    else break;
    }
    if(count>max) max = count;
  }
  printf("%d",max);
  return 0;
}

