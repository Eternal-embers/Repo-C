#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define num 10
int main()
{
	int i,j,count;
	int arr[N];
	start:
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
	
	//冒泡排序,从大到小排序 
	for(i=0;i<N;i++)
		for(j=0;j<N-1-i;j++) 
			if(arr[j]>arr[j+1])
			{
			arr[j]=arr[j]^arr[j+1];
			arr[j+1]=arr[j]^arr[j+1];
			arr[j]=arr[j]^arr[j+1];
			}
	//输出排序后数据 
	for(i=0;i<N;i++)printf("%5d",arr[i]);
	srand(arr[10]);
	count++;
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	}
	system("pause");
	system("cls");
	goto start;
	return 0;
} 
