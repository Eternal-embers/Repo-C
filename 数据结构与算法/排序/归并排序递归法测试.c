#include<stdio.h>
void fillArr(int *arr,int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
        arr[i] = rand()%1000;
}

void showArr(const int *arr,int n){
	int i;
	for(i = 0;i<n;i++){
		printf("  %3d  ",arr[i]);
	}
	printf("\n");
}

void print(const int *arr,int start,int end){
	int i;
	printf("start:%d end:%d\n",start,end);
	for(i = start;i<=end;i++)
		printf("  %3d  ",arr[i]);
	putchar('\n');
}

void merge_sort_recursive(int arr[],int reg[],int start,int end){
	if(start >= end) return;//若拆解至只剩一个数组元素，返回
	int len = end - start,mid = (len >>1 ) + start;//获取数组长度以及中间索引
	int start1 = start,end1 = mid;//分组左边start到mid
	int start2 = mid + 1,end2 = end;//分组mid+1到end
	merge_sort_recursive(arr,reg,start1,end1);//对左半部分进行归并排序
	merge_sort_recursive(arr,reg,start2,end2);//对右半部分进行归并排序
	print(arr,start1,end1);
	print(arr,start2,end2);
	putchar('\n');
	int k = start;//从数组起点开始
	while(start1 <= end1 && start2 <= end2)//进行归并
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];//将左半部分和右半部分归并为一个有序的序列
 	//[start1,end1]和[start2,end2]两部分可能有一部分未并入arr中
	while(start1 <= end1)//如果[start1,end1]未全部并入
		reg[k++] = arr[start1++];//将左部分的剩余有序序列并入reg
	while(start2 <= end2)//如果[start2,end2】未全部并入
		reg[k++] = arr[start2++];//将右部分的剩余有序序列并入reg
	for(k = start;k <= end;k++)//将排序好的数组复制到arr中
		arr[k] = reg[k];
}
int main(){
	int n;
  	printf("n = ");
  	scanf("%d",&n);
   	int arr[n+1];
   	int reg[n+1];
   	fillArr(arr,n);
   	showArr(arr,n);
   	merge_sort_recursive(arr,reg,0,n-1);
   	showArr(reg,n);
   	return 0;
}
