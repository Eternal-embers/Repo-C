#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  char arr[10],temp;
  int n,k,i,j,t,count=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
    {
      k=i*j;
      count=0; 
      while(k!=0){
      if(k%n<10)arr[count]='0'+k%n;
      else arr[count]='A'+k%n-10;
      count++;
      k/=n;
      }
      t=0;
      while(t<count-t-1)
      {
      	 temp=arr[t];
      	 arr[t]=arr[count-t-1];
      	 arr[count-t-1]=temp; 
      	t++;
	  }
      printf("%d*%d=%s",i,j,&arr);
      printf("\n");
    }
  return 0;
}
