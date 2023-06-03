#include<stdio.h>
#include<stdlib.h>
#define N 11
int main()
{
	int arr[N][N],i,j,k;
	for(i=1;i<N;i++)
	for(j=1;j<=i;j++)
	{
	 if(j==1||i==j)arr[i][j]=1;
	 else arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
	}
	for(i=1;i<N;i++)
	for(j=1;j<=i;j++)
	{
	if(j==1)
	for(k=0;k<=N-i;k++)printf(" ");
	printf("%4d",arr[i][j]);
	if(i==j)printf("\n");
	}
	system("pause"); 
	return 0;
}
