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
	 �ڶ�����arr�У���startΪ���ڵ�Ķ�������������������Ƕѵ�����£�
     ��start�ڵ�������˿���ʹ����startΪ�ڵ�Ķ��������ճ�Ϊ��
     �����startΪ�ڵ�Ķ�����������Ƕѣ�ֱ�ӷ���
     ���ԣ��˺�����֤�����������£��ܹ��õ�һ����startΪ���ڵ㡢��endΪ���һ���ڵ�Ķ�
     ������������0��ʼ������£���������i��
     2i+1Ϊ���ӣ�2(i + 1)Ϊ�Һ��ӣ�i/2-1Ϊ���׽ڵ�
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
	//��ʼ������������ѣ��Ӻ���ǰ����
	for(i = n / 2 - 1;i >= 0;i--)
		max_heapify(arr,i,n - 1);
	//����
	for(i = n - 1;i >  0;i--){
		/*
			������ѵĸ��ڵ�Ͷѵ����һ���ڵ㽻��λ��
			��ʱ���ڵ㽫��������������
		*/
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		max_heapify(arr,0,i - 1);//�������ڵ㣬��[0,i-1]�ָ�������
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

