#include<stdio.h>
#include<time.h>
void fillArr(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand()%1000;
}

void showArr(int arr[],int n){
	int i;
	for(i = 0;i<n;i++)
		printf(" %3d ",arr[i]);
	putchar('\n');
}

void mergeSort(int arr[],int reg[],int start,int end){
	if(start >= end) return;//如果分组中只有一个元素那它是有序的，直接返回
	int len = end - start,mid = (len >> 1) + start;
	int start1 = start,end1 = mid;
	int start2 = mid + 1,end2 = end;
	mergeSort(arr,reg,start1,end1);
	mergeSort(arr,reg,start2,end2);
	int k = start;
	while(start1 <= end1 && start2 <= end2)
		reg[k++] = (arr[start1] < arr[start2]) ? arr[start1++] : arr[start2++];
	/* [start1,end1]和[start2,end2]两部分可能有一部分未并入reg中 */
	while(start1 <= end1)//将[start1,end1]的剩余部分并入arr中
		reg[k++] = arr[start1++];
	while(start2 <= end2)//将[start2,end2]的剩余部分并入arr中
		reg[k++] = arr[start2++];
	/* 复制已排序好的部分到arr中 */
	for(k = start;k <= end;k++)
		arr[k] = reg[k];
}

int main(){
	int n;
	printf("n = ");
	scanf("%d",&n);
	int arr[n],reg[n];
	fillArr(arr,n);
	showArr(arr,n);
	mergeSort(arr,reg,0,n-1);
	showArr(arr,n);
	return 0;
}
