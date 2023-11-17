#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void fillArray(int arr[], int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 1000 + 1;
}
void showArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("  %4d  ", arr[i]);
		if ((i + 1) % 20 == 0)
			putchar('\n');
	}
	printf("\n");
}

void insertion_sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = temp;
	}
}

void binary_insertion_sort(int arr[], int n)
{
	int i, j, low, high, mid, temp;
	for (i = 1; i < n; i++)
	{
		// find insertion point
		low = 0;
		high = i - 1;
		temp = arr[i];
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (temp < arr[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}

		// move backward
		for (j = i - 1; j >= high + 1; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = temp;
	}
}

int main()
{
	int arr[N];
	fillArray(arr, N);
	showArray(arr, N);
	binary_insertion_sort(arr, N);
	showArray(arr, N);
	return 0;
}
