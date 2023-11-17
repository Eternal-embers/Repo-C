#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

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
		printf(" %3d ", p[i]);
	}
	printf("\n");
}

void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int i, j, pivot, temp;
		i = left, j = right, pivot = left;
		while (i < j) // break if i = j
		{
			// find the value grater than arr[pivot]
			while (arr[i] <= arr[pivot] && i < right)
				i++;
			// find the value less than the arr[pivot]
			while (arr[j] > arr[pivot])
				j--;

			// swap
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		// place arr[pivot] on arr[j],arr[pivot]'s position is its final position
		if (pivot != j)
		{
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = temp;
		}
		quickSort(arr, left, j - 1);  //[left,j - 1]
		quickSort(arr, j + 1, right); //[j + 1,right]
	}
}

int main()
{
	int arr[N];
	fillArr(arr, N);
	showArr(arr, N);
	putchar('\n');
	quickSort(arr, 0, N - 1);
	showArr(arr, N);
	return 0;
}
