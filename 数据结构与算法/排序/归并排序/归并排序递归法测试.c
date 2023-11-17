#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArr(int *arr, int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 1000;
}

void showArr(const int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("  %3d  ", arr[i]);
	}
	printf("\n");
}

void print(const int *arr, int start, int end)
{
	int i;
	printf("start:%d end:%d\n", start, end);
	for (i = start; i <= end; i++)
		printf("  %3d  ", arr[i]);
	putchar('\n');
}

void merge_sort_recursive(int arr[], int reg[], int start, int end)
{
	if (start >= end)
		return;										 // �������ֻʣһ������Ԫ�أ�����
	int len = end - start, mid = (len >> 1) + start; // ��ȡ���鳤���Լ��м�����
	int start1 = start, end1 = mid;					 // �������start��mid
	int start2 = mid + 1, end2 = end;				 // ����mid+1��end
	merge_sort_recursive(arr, reg, start1, end1);	 // ����벿�ֽ��й鲢����
	merge_sort_recursive(arr, reg, start2, end2);	 // ���Ұ벿�ֽ��й鲢����
	print(arr, start1, end1);
	print(arr, start2, end2);
	putchar('\n');
	int k = start;															  // ��������㿪ʼ
	while (start1 <= end1 && start2 <= end2)								  // ���й鲢
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++]; // ����벿�ֺ��Ұ벿�ֹ鲢Ϊһ�����������
	//[start1,end1]��[start2,end2]�����ֿ�����һ����δ����arr��
	while (start1 <= end1)		   // ���[start1,end1]δȫ������
		reg[k++] = arr[start1++];  // ���󲿷ֵ�ʣ���������в���reg
	while (start2 <= end2)		   // ���[start2,end2��δȫ������
		reg[k++] = arr[start2++];  // ���Ҳ��ֵ�ʣ���������в���reg
	for (k = start; k <= end; k++) // ������õ����鸴�Ƶ�arr��
		arr[k] = reg[k];
}
int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);
	int arr[n + 1];
	int reg[n + 1];
	fillArr(arr, n);
	showArr(arr, n);
	merge_sort_recursive(arr, reg, 0, n - 1);
	showArr(reg, n);
	return 0;
}
