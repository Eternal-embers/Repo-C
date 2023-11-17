#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void fillArray(int arr[], int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 1000;
}

void showArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("  %3d  ", arr[i]);
	printf("\n");
}

void quickSort(int arr[], int low, int high)
{
	if (low >= high)
		return;
	int i, j, pivot;
	i = low;
	j = high;
	pivot = arr[low];
	while (i < j)
	{
		// find a value less than pivot
		while (i < j && arr[j] >= pivot)
			j--;
		if (i < j)
		{
			arr[i] = arr[j]; // put the arr[j] on arr[i]
			i++;
		}

		// find a value grater than pivot
		while (i < j && arr[i] < pivot)
			i++;
		if (i < j)
		{
			arr[j] = arr[i]; // put the arr[i] on arr[j]
			j--;
		}
	}
	arr[j] = pivot; // put pivot in its final position
	quickSort(arr, low, j - 1);
	quickSort(arr, j + 1, high);
}

int main()
{
	int arr[N];
	fillArray(arr, N);
	showArray(arr, N);
	quickSort(arr, 0, N);
	showArray(arr, N);
	return 0;
}
