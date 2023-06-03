#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int i;
	int left = 0,right = N-1;
	int arr[N];
	srand(time(NULL));
	//生成数据
	for(i = 0;i < N;i++){
	arr[i]=rand()%1000;
	srand(arr[i]);
	}	
	//原始数据打印
	for(i=0;i<N;i++)
	printf("%d ",arr[i]);
	printf("\n\n"); 
	//排序
	while(left < right)
	{
		int min = left;
		int max = right;
		for( i = left;i <= right;i++)
		{
			if(arr[i]<arr[min])min = i;
			if(arr[i]>arr[max])max = i;
		}
		//交换right和max 
		if(max!=right){
		arr[max]^=arr[right];
		arr[right]^=arr[max];
		arr[max]^=arr[right];
		}
		//交换left和min
		if(min == right)min=max;
		if(min!=left){
		arr[min]^=arr[left];
		arr[left]^=arr[min];
		arr[min]^=arr[left];
		}
		left++;
		right--;
	 } 
	 //打印
	 for(i=0;i<N;i++)
	 printf("%d ",arr[i]);
	 return 0; 
}
