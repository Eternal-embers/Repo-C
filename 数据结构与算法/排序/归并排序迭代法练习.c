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

void merge_sort(int arr[],int len){/* 自底向上 */
	int *a = arr;
	int *b = (int *)malloc(len*sizeof(int));//申请和arr数组相同的空间
	int seg,start;//seg用于分段
	for(seg = 1;seg < len;seg+=seg){
		for(start = 0;start < len;start+=seg+seg){
			int low = start,mid = min(start + seg,len),high = min(start + seg + seg,len);
			int k = low;
			int start1 = low,end1 = mid;
			int start2 = mid,end2 = high;
			while(start1 < end1 && start2 < end2)//归并
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			//[start1,end1]和[start2,end2]可能有一个区间未完全并入arr数组中
			while(start1 < end1)//将[start1,end1]未并入的有序序列并入arr数组中
				b[k++] = a[start1++];
			while(start2 < end2)//将[start2,end2]未并入的有序序列并入arr数组中
				b[k++] = a[start2++];
		}
		//将以分段为seg的各段有序的数组作为下一个归并排序的arr数组,所以交换a、b指针的地址
		int *temp = a;
		a = b;
		b = temp;
	}
	if(a!=arr){ //如果a不指向arr则将a所指的已排序数组复制到arr数组中
		int i;
		for(i = 0;i < len;i++)
			b[i] = a[i];
		b = a;//将b指向申请的空间
	}
	free(b);//释放申请的空间
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
