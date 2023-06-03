#include<stdio.h>
void mergeSort(int arr[],int reg[],int start,int end){
	if(start >= end) return;
	int len = end - start,mid = start + (len >> 1);
	int start1 = start,end1 = mid;
	int start2 = mid + 1,end2 = end;
	mergeSort(arr,reg,start1,end1);
	mergeSort(arr,reg,start2,end2);
	int k = start;
	while(start1 <= end1 && start2 <= end2)
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	while(start1 <= end1)
		reg[k++] = arr[start1++];
	while(start2 <= end2)
		reg[k++] = arr[start2++];
	for(k = start;k <= end;k++)
		arr[k] = reg[k];
}
int main(){
    int N,i;
    scanf("%d",&N);
    int arr[N],reg[N];
    for(i = 0;i < N;i++)
        scanf("%d",&arr[i]);
    mergeSort(arr,reg,0,N-1);
    for(i = 0;i < N;i++)
        printf("%d ",arr[i]);
    putchar('\n');
    for(i = N-1;i >= 0;i--)
        printf("%d ",arr[i]);
    return 0;
}
