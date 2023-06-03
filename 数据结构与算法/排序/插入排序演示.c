#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define num 10
int main()
{
	int i,j,k,count=0,mark;
	int arr[N],temp;
	srand(time(NULL));
	//获取数据
	arr[0]=rand()%1000;
	for(i=1;i<N;i++) 	
	{
	arr[i]=rand()%1000;
		for(j=i-1;j>=0;j--)//如果有数据重复，重新赋值 
		if(arr[i]==arr[j]){
			i--;
			break;	
		}
	}
	
	system("color 02");
	printf("\n\n\n    【%d】",arr[0]);
	for(i=1;i<N;i++)
	printf("     %d",arr[i]);
	printf("\n    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	
	//插入排序
	for(i=1;i<N;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0;j--)
		if( temp<arr[j] )arr[j+1]=arr[j];
		else break;
		arr[j+1]=temp;
		mark=j+1;
		for(k=0;k<N;k++)
		{
			if(k==i)printf("   【%d】",arr[k]);
			else if(k==mark)printf("    [%d]",arr[k]);
			else printf("     %d",arr[k]); 
		}
		printf("\n    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	}	
	return 0;
} 
