#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define num 10
int main()
{
	int i,j,k,count;
	int arr[N];
	start:
	system("color 02");
	srand(time(NULL));
	count=0;
	while(count<num)
	{
	arr[0]=rand()%1000;
	for(i=1;i<N;i++)//获取数据 	
	{
	arr[i]=rand()%1000;
		for(j=i-1;j>=0;j--)//如果有数据重复，重新赋值 
		if(arr[i]==arr[j]){
			i--;
			break;	
		}
	}
	
	for(i=0;i<N;i++)
	printf("%5d",arr[i]);
	printf("\n");
	
	//选择排序,从大到小排序 
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++) 
		if(arr[i]>arr[j])//选出该组最大数据的下标 
		{
			arr[i]=arr[i]^arr[j];
			arr[j]=arr[i]^arr[j];
			arr[i]=arr[i]^arr[j];
		}
	}
	//输出排序后数据 
	for(i=0;i<N;i++)printf("%5d",arr[i]);
	srand(arr[10]);
	count++;
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	sleep(1);
	}
	system("cls");
	goto start;
	return 0;
} 
