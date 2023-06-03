#include<stdio.h>
#include<time.h>
#define N 20

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
		printf(" %3d ",p[i]);
	}
	printf("\n");
}

//首先设定一个分界值，通过该分界值将数组分成左右两部分
//将大于或等于分界值的数据集中到数组右边，小于分界值的数据集中到数组左边
//对左边和右边的数据重复快速排序
void quickSort(int arr[],int left,int right){
	if(left<right) {
		int i,j,pivot,temp;
		i = left,j = right,pivot = left;
		while(i<j){
			while(arr[i]<=arr[pivot] && i<right)//向右寻找第一个大于等于基准值的数
				i++;
			while(arr[j]>arr[pivot])//向左寻找第一个小于基准值的数
				j--;
  			if(i<j){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}//将左边找到的第一个大于基准值的数与右边找到的第一个大于基准值的数交换
		}
		/* 将基准值和arr[j]交换 */
		if(pivot!=j){
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = temp;
		}
		quickSort(arr,left,j-1);
		quickSort(arr,j+1,right);
	}//如果左边界小于右边界则执行快速排序
}

int main(){
	int arr[N];
	fillArr(arr,N);
	showArr(arr,N);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	quickSort(arr,0,N-1);
	showArr(arr,N);
	return 0;
}
