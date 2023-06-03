#include<stdio.h>
#define N 15

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
		if((i+1)%15==0) putchar('\n');
	}
	printf("\n");
}

/*
	 在二叉树arr中，以start为根节点的二叉树如果左右子树都是堆的情况下，
     对start节点进行下滤可以使得以start为节点的二叉树最终成为堆
     如果以start为节点的二叉树本身就是堆，直接返回
     所以，此函数保证在上述条件下，能够得到一棵以start为根节点、以end为最后一个节点的堆
     二叉树索引从0开始的情况下，对于任意i：
     2i+1为左孩子，2(i + 1)为右孩子，i/2-1为父亲节点
*/
void max_heapify(int arr[],int start,int end){
	int root,child;
	for(root = start;root * 2 + 1 <= end;root = child){
		child = root * 2 + 1;
		if(child + 1 <= end && arr[child + 1] > arr[child])
			child++;
		if(arr[root] > arr[child]) return;
		else {
			int temp = arr[root];
			arr[root] = arr[child];
			arr[child] = temp;
		}
	}
}

void heapSort(int arr[],int n){
	int i;
	//初始化，构建二叉堆，从后向前构造
	for(i = n / 2 - 1;i >= 0;i--)
		max_heapify(arr,i,n - 1);
	//排序
	for(i = n - 1;i >  0;i--){
		/*
			将二叉堆的根节点和堆的最后一个节点交换位置
			此时根节点将划入已排序序列
		*/
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		max_heapify(arr,0,i - 1);//调整根节点，将[0,i-1]恢复堆序性
	}
}

int main(){
	int arr[N];
	fillArray(arr,N);
	showArray(arr,N);
	putchar('\n');
	heapSort(arr,N);
	showArray(arr,N);
	return 0;
}

