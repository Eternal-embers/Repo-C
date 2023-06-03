#include<stdio.h>
#include<malloc.h>
#include<math.h>
#define N 8
int queen[N];
int sum=0;
int result[100][N];

int place(int t)
{
 int k;
 for(k=0;k<t;k++)
    if(queen[k]==queen[t]||abs(k-t)==abs(queen[k]-queen[t]))
    return 0;
 return 1;
}

void backtrack(int t)//t代表第t行 
{
 if(t==N)
 {
 sum++;
 for(int m=0;m<N;m++)
 result[sum][m]=queen[m];
 }
 else 
 	  for(int i=0;i<N;i++)//对每一行的所有位置进行搜索 
      {
	  queen[t]=i;
	  if(place(t))//如果放置成功，搜索下一个位置 
	  backtrack(t+1);
      }
}
int main()
{
backtrack(0);
printf("sum=%d\n",sum);
for(int i=1;i<=sum;i++)
{
printf(">>%d\n",i);
for(int t=0;t<N;t++)
{
printf("\t");
for(int j=0;j<N;j++)
   if(j==result[i][t])
   printf("Q ");
     else
     printf(". ");
printf("\n");
}
printf("- - - - - - - - - - - - - - - - - - -\n");
}
return 0;	
}
