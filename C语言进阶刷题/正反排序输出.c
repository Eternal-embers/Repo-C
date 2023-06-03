#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int comp(const void *a1,const void *a2){
  const int *p1 = (const int *)a1;
  const int *p2 = (const int *)a2;
  return *p1 - *p2;
}
int main()
{
  int N,i;
  scanf("%d",&N);
  int arr[N];
  for(i = 0;i < N;i++)
    scanf("%d",&arr[i]);
  qsort(arr,N,sizeof(int),comp);
  for(i = 0;i < N;i++)
    printf("%d ",arr[i]);
  putchar('\n');
  for(i = N-1;i >= 0;i--)
    printf("%d ",arr[i]);
  putchar('\n');
  return 0;
}
