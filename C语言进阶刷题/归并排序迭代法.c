#include<stdio.h>
#include<stdlib.h>
int min(int a,int b) {
	return a < b ? a : b;
}
void merge_sort_recursive(int *arr,int len){
	int *a = arr;
	int *b = (int *)malloc(sizeof(int)*len);
	int seg,start;
	for(seg = 1; seg < len;seg+=seg){
		for(start = 0;start < len;start += seg + seg){
			int low = start,mid = min(start + seg,len),high = min(start + seg + seg,len);
			int k = low;
			int start1 = low,end1 = mid;
			int start2 = mid,end2 = high;
			while(start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while(start1 < end1)
				b[k++] = a[start1++];
			while(start2 < end2)
				b[k++] = a[start2++];
		}
		int *temp = a;
		a = b;
		b = temp;
	}
	if(a != arr){
		int i;
		for(i = 0;i < len;i++)
			b[i] = a[i];
		b = a;
	}
	free(b);
}
int main(){
    int N,i;
    scanf("%d",&N);
    int arr[N];
    for(i = 0;i < N;i++)
        scanf("%d",&arr[i]);
	merge_sort_recursive(arr,N);
    for(i = 0;i < N;i++)
        printf("%d ",arr[i]);
    putchar('\n');
    for(i = N-1;i >= 0;i--)
        printf("%d ",arr[i]);
    return 0;
}
