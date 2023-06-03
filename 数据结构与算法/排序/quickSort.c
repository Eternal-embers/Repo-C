#include<stdio.h>
#define N 15
void format(int *arr,int n,int i,int j,int index){
	int k;
	for(k = 0;k<n;k++){
		if(i==j && k==i) printf(" <%3d> ",arr[k]);
		else if(k==i) printf(" [%3d] ",arr[k]);
		else if(k==j) printf("【%3d】",arr[k]);
		else printf("  %3d  ",arr[k]);
	}
	printf(" index:%3d",index);
	printf("\n");
}

void quickSort(int array[],int low,int high){
	if(low>=high) return;
	int i = low,j = high;
	int index = array[i];//取最左边的数作为基准数
	while(i<j) {
		while(i < j && array[j] >= index)//向左寻找第一个小于index的数
			j--;
		format(array,N,i,j,index);
		if(i < j) array[i++] = array[j];//将array[j]填入array[i]中,并将i向右移动
		while(i < j && array[i] < index)//向右寻找第一个大于index的数
			i++;
		format(array,N,i,j,index);
		if(i < j) array[j--] = array[i];//将array[j]填入array[i]中,并将j向左移动
	}
	array[i] = index;//将基准数填入最后的坑
	format(array,N,i,j,index);
	printf("\n");
	quickSort(array,low,i-1);//递归调用，分治low到i-1
	quickSort(array,i+1,high);//递归调用，分治i+1到high
}

void fillArr(int *arr,int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand()%1000;
}

void showArr(int *arr,int n){
	int i;
	for(i = 0;i<n;i++)
		printf("  %3d  ",arr[i]);
	printf("\n");
}

int main() {
	int array[N];
	fillArr(array,N);
	quickSort(array,0,N-1);
	showArr(array,N);
	return 0;
}
