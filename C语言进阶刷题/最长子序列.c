#include<stdio.h>
#include<string.h>
int main()
{
  char S[1000],T[1000];
  int i,j,lens,lent,ans = 0;
  gets(S);
  gets(T);
  lens = strlen(S);
  lent = strlen(T);
  //题目意思是说在S中按从左到右的顺序能包含的T的最大长度
  //T的下一个字符应该到上一个与S匹配的位置的下一个字符去寻找
    for(i = 0,j = 0;j<lens && i<lent;j++)//双指针
	{
      if(T[i]==S[j]) {
        ans++;//T[i]被匹配
        i++;//匹配下一个
      }
  }
  printf("%d",ans);
  return 0;
}

