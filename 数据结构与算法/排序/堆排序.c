#include <stdio.h>
#include <stdlib.h>
#define N 20

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

void max_heapify(int arr[], int start, int end) {
    //建立父节点指标和子节点指标
	int root = start;
    int child = root * 2 + 1;
    while (child <= end) { //若子节点指标在范围内才做比较
        if (child + 1 <= end &&  arr[child + 1] > arr[child]) //获取左右孩子中较大的那个
            child++;
        if (arr[root] > arr[child]) //如果根节点大于左右孩子节点
		{
   			return;
		}
        else { //交换父子节点并继续比较
			int temp = arr[root];
			arr[root] = arr[child];
			arr[child] = temp;
			root = child;
            child = root * 2 + 1;
        }
    }
}

void HeapSort(int arr[], int len) {
    int i;
	/* 初始化，从后往前调整，获得一个最大堆 */
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
	//先将第一个元素和已排好元素的前一位做交换，再重新调整，直到排序完毕
    for (i = len - 1; i > 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
        max_heapify(arr, 0, i - 1);//保持最大堆
    }
}

int main() {
	int arr[N];
 	fillArray(arr,N);
 	showArray(arr,N);
 	HeapSort(arr,N);
 	showArray(arr,N);
    return 0;
}

