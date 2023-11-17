#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int count = 0;
void fillArr(int *arr, int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 1000;
}

void showArr(const void *arr, int n)
{
	int i;
	const int *p = (const int *)arr;
	for (i = 0; i < n; i++)
	{
		printf("  %3d  ", p[i]);
	}
	printf("\n");
}

// �����趨һ���ֽ�ֵ��ͨ���÷ֽ�ֵ������ֳ�����������
// �����ڻ���ڷֽ�ֵ�����ݼ��е������ұߣ�С�ڷֽ�ֵ�����ݼ��е��������
// ����ߺ��ұߵ������ظ���������

void quickSort(int *arr, int left, int right)
{
	if (left >= right)
		return;
	int i, j, pivot; // pivot֧��
	int temp;		 // ���ڽ���
	int k;
	// ����
	for (i = 0; i < N; i++)
	{
		if (i == left)
			printf(" |%3d  ", arr[i]);
		else if (i == right)
			printf(" %3d| ", arr[i]);
		else
			printf("  %3d  ", arr[i]);
	}
	printf("\n");

	if (left < right)
	{
		pivot = left; // �����п��ŵĲ��ֳַ����������֣���׼ֵΪ�м��Ǹ���
		i = left;
		j = right;
		while (i < j)
		{
			while (arr[i] <= arr[pivot] && i < right) // ����Ѱ�ҵ�һ�����ڵ��ڻ�׼ֵ����
				i++;
			while (arr[j] > arr[pivot]) // ����Ѱ�ҵ�һ��С�ڻ�׼ֵ����
				j--;
			if (i < j)
			{
				// ����
				for (k = 0; k < N; k++)
				{
					if (k == i)
						printf(" [%3d] ", arr[k]);
					else if (k == j)
						printf(" (%3d) ", arr[k]);
					else if (k == pivot)
						printf("��%3d��", arr[k]);
					else
						printf("  %3d  ", arr[k]);
				}
				printf("\n");

				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				count++;

			} // ����ߵ�һ�����ڻ�׼ֵ�������ұߵ�һ�����ڻ�׼ֵ��������
		}
		// ����
		for (k = 0; k < N; k++)
		{
			if (k == i)
				printf(" [%3d] ", arr[k]);
			else if (k == j)
				printf(" (%3d) ", arr[k]);
			else if (k == pivot)
				printf("��%3d��", arr[k]);
			else
				printf("  %3d  ", arr[k]);
		}
		printf("\n");

		// ����׼ֵ��arr[j]����
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		count++;

		// ����
		for (k = 0; k < N; k++)
		{
			if (k == j)
				printf("��%3d��", arr[k]);
			else if (k == pivot)
				printf("��%3d��", arr[k]);
			else
				printf("  %3d  ", arr[k]);
		}
		printf("\n");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	} // �����߽�С���ұ߽���ִ�п�������
}

int main()
{
	int arr[N];
	fillArr(arr, N);
	showArr(arr, N);
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	quickSort(arr, 0, N - 1);
	showArr(arr, N);
	printf("�ܹ�����%d��", count);
	return 0;
}
