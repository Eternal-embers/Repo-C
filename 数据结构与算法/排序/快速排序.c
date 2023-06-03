#include<stdio.h>
#include<stdlib.h>
#define N 30

void fillArray(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand() % 1000 + 1;
}

void showArray(int arr[],int n){
	int i;
	for(i = 0;i<n;i++){
		printf("  %4d  ",arr[i]);
		if((i+1)%10==0) putchar('\n');
	}
	printf("\n");
}

void quickSort(int array[],int low,int high){
	if(low >= high) return;
	int i = low,j = high;
	int index = array[i];//取最左边的数作为基准数
	while(i<j) {
		while(i < j && array[j] >= index)//向左寻找第一个小于index的数
			j--;
		if(i < j) array[i++] = array[j];//将array[j]填入array[i]中,并将i向右移动
		while(i < j && array[i] < index)//向右寻找第一个大于index的数
			i++;
		if(i < j) array[j--] = array[i];//将array[j]填入array[i]中,并将j向左移动
	}
	array[i] = index;//将基准数填入最后的坑
	quickSort(array,low,i-1);//递归调用，分治low到i-1
	quickSort(array,i+1,high);//递归调用，分治i+1到high
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
