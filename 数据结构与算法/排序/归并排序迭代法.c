#include<stdio.h>
#include<stdlib.h>
void fillArr(int *arr,int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
        arr[i] = rand()%1000;
}

void showArr(const void *arr,int n){
	int i;
	const int *p = (const int *)arr;
	for(i = 0;i<n;i++){
		printf("  %3d  ",p[i]);
	}
	printf("\n");
}

int min(int x,int y){
	return x < y ? x : y;
}

void merge_sort(int arr[],int len){
	int *a = arr;
	int *b = (int *)malloc(len*sizeof(int));//申请和arr数组相同的空间
	int seg,start;//seg段
	for(seg = 1;seg < len;seg<<=1){
		for(start = 0;start < len;start+=seg + seg){
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
	if(a!=arr){
		int i;
		for(i = 0;i < len;i++)
			b[i] = a[i];
		b = a;
	}
	free(b);
}

int main(){
   int n;
   printf("n = ");
   scanf("%d",&n);
   int arr[n];
   fillArr(arr,n);
   showArr(arr,n);
   merge_sort(arr,n);
   showArr(arr,n);
   return 0;
}
