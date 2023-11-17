#include<stdio.h>
void fillArr(int *arr,int n){
	int i;
	srand(time(NULL));
	for(i = 0;i<n;i++)
        arr[i] = rand()%1000;
}

void showArr(const int *arr,int n){
	int i;
	for(i = 0;i<n;i++){
		printf("  %3d  ",arr[i]);
	}
	printf("\n");
}

void merge_sort_recursive(int arr[],int reg[],int start,int end){
	if(start >= end) return;//�������ֻʣһ������Ԫ�أ�����
	int len = end - start,mid = (len >>1 ) + start;//��ȡ���鳤���Լ��м�����
	int start1 = start,end1 = mid;//�������start��mid
	int start2 = mid + 1,end2 = end;//����mid+1��end
	merge_sort_recursive(arr,reg,start1,end1);//����벿�ֽ��й鲢����
	merge_sort_recursive(arr,reg,start2,end2);//���Ұ벿�ֽ��й鲢����
	int k = start;//��������㿪ʼ
	while(start1 <= end1 && start2 <= end2)//���й鲢
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];//����벿�ֺ��Ұ벿�ֹ鲢Ϊһ�����������
	//�����������ֵ�Ԫ�����������ʱ������һ��Ԫ��
	while(start1 <= end1)//����󲿷ֵ�start1δ����end1
		reg[k++] = arr[start1++];//���󲿷ֵ�ʣ���������в���reg
	while(start2 <= end2)//����Ҳ��ֵ�start2δ����end2
		reg[k++] = arr[start2++];//���Ҳ��ֵ�ʣ���������в���reg
	for(k = start;k <= end;k++)//������õ����鸴�Ƶ�arr��
		arr[k] = reg[k];
}
int main(){
	int n;
  	printf("n = ");
  	scanf("%d",&n);
   	int arr[n];
   	int reg[n];
   	fillArr(arr,n);
   	showArr(arr,n);
   	merge_sort_recursive(arr,reg,0,n-1);
   	showArr(reg,n);
   	return 0;
}
