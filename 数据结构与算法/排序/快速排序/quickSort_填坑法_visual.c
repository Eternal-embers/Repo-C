#include<stdio.h>
#define N 15
void format(int *arr,int n,int i,int j,int index){
	int k;
	for(k = 0;k<n;k++){
		if(i==j && k==i) printf(" <%3d> ",arr[k]);
		else if(k==i) printf(" [%3d] ",arr[k]);
		else if(k==j) printf("��%3d��",arr[k]);
		else printf("  %3d  ",arr[k]);
	}
	printf(" index:%3d",index);
	printf("\n");
}

void quickSort(int array[],int low,int high){
	if(low>=high) return;
	int i = low,j = high;
	int index = array[i];//ȡ����ߵ�����Ϊ��׼��
	while(i<j) {
		while(i < j && array[j] >= index)//����Ѱ�ҵ�һ��С��index����
			j--;
		format(array,N,i,j,index);
		if(i < j) array[i++] = array[j];//��array[j]����array[i]��,����i�����ƶ�
		while(i < j && array[i] < index)//����Ѱ�ҵ�һ������index����
			i++;
		format(array,N,i,j,index);
		if(i < j) array[j--] = array[i];//��array[j]����array[i]��,����j�����ƶ�
	}
	array[i] = index;//����׼���������Ŀ�
	format(array,N,i,j,index);
	printf("\n");
	quickSort(array,low,i-1);//�ݹ���ã�����low��i-1
	quickSort(array,i+1,high);//�ݹ���ã�����i+1��high
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
