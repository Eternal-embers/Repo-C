#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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

int min(int x, int y)
{
	return x < y ? x : y;
}

void merge_sort(int arr[], int len)
{
	// 创建临时数组以存储排序后的元素
	int *a = arr;
	int *b = (int *)malloc(len * sizeof(int));
	int seg, start;

	// 遍历每个段的大小
	for (seg = 1; seg < len; seg <<= 1)
	{
		// 遍历每个段
		for (start = 0; start < len; start += seg + seg)
		{
			// 定义要合并的两个子数组的边界
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;

			// 将两个子数组合并到临时数组'b'中
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}

		// 交换数组'a'和'b'以进行下一次迭代
		int *temp = a;
		a = b;
		b = temp;
	}

	// 如果最终排序后的数组不存储在'arr'中，则将其复制到'arr'中
	if (a != arr)
	{
		int i;
		for (i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}

	// 释放为临时数组'b'分配的内存
	free(b);
}

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);
	int arr[n];
	fillArr(arr, n);
	showArr(arr, n);
	merge_sort(arr, n);
	showArr(arr, n);
	return 0;
}
