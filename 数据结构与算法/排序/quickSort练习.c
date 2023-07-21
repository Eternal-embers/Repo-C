#include<stdio.h>
#include<stdlib.h>
#define N 20
void fillArray(int arr[],int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
		arr[i] = rand()%1000;
}

void showArray(int arr[],int n){
	int i;
	for(i = 0;i<n;i++)
		printf("  %3d  ",arr[i]);
	printf("\n");
}

//���������ڿӷ�
void quickSort(int arr[],int low,int high){
	if(low>=high) return;
	int i,j,index;
	i = low;
	j = high;
	index = arr[low];
	while(i<j){
		while(i<j && arr[j]>=index)//����Ѱ�ҵ�һ��С��index����
			j--;
		if(i<j) arr[i++] = arr[j];//������ߵĿ���
		while(i<j && arr[i]<index)//����Ѱ�ҵ�һ������index����
			i++;
		if(i<j) arr[j--] = arr[i];//�����ұߵĿ���
	}
	arr[j] = index;//i��j����ʱ��index����arr[j]��
	quickSort(arr,low,j-1);//��index��߽��п�������
	quickSort(arr,j+1,high);//��index�ұ߽��п�������
}

int main()
{
	int arr[N];
	fillArray(arr,N);
	showArray(arr,N);
	quickSort(arr,0,N);
	showArray(arr,N);
	return 0;
}
