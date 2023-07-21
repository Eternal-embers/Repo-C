#include<stdio.h>
#include<stdlib.h>
#define N 20
void fillArray(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand()%1000;
}

void showArray(int arr[],int n){
	int i;
	for(i = 0;i<n;i++)
		printf("  %3d  ",arr[i]);
	printf("\n");
}

//快速排序挖坑法
void quickSort(int arr[],int low,int high){
	if(low>=high) return;
	int i,j,index;
	i = low;
	j = high;
	index = arr[low];
	while(i<j){
		while(i<j && arr[j]>=index)//向左寻找第一个小于index的数
			j--;
		if(i<j) arr[i++] = arr[j];//填入左边的坑中
		while(i<j && arr[i]<index)//向右寻找第一个大于index的数
			i++;
		if(i<j) arr[j--] = arr[i];//填入右边的坑中
	}
	arr[j] = index;//i和j相遇时将index填入arr[j]中
	quickSort(arr,low,j-1);//对index左边进行快速排序
	quickSort(arr,j+1,high);//对index右边进行快速排序
}

int main()
{
	int arr[N];
	fillArray(arr,N);
	showArray(arr,N);
	quickSort(arr,0,N);
	showArray(arr,N);
	return 0;
}
