#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int i,j,k,low,high,mid,arr[N],temp;
	srand(time(NULL));
	for(i=0;i<N;i++){
		arr[i] = rand()%1000;
		srand(arr[i]);
	}
	//原始数据 
	for(i=0;i<N;i++){
		printf("  %3d  ",arr[i]);
	}
	printf("\n\n");
	//插入排序 
	for(i=1;i<N;i++){
		temp = arr[i];
		low = 0;
		high = i-1;//采用二分查找法查找插入位置
		while(low<=high){
			mid = (low + high)/2;
			if(temp<arr[mid]) high = mid-1;
			else low = mid + 1;
		}
		for(j=i-1;j>=high+1;--j)//移动挪位 
			arr[j+1]=arr[j];
		arr[high+1] = temp;
		//打印
		for(k=0;k<N;k++){
			if(k==i) printf(" [%3d] ",arr[k]);
			else if(k==low) printf("【%3d】",arr[k]);
			else printf("  %3d  ",arr[k]);
		}
		printf("\n\n");
	}
	return 0;
}
