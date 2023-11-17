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

void bubble_sort(int arr[], int n)
{
	int i, j;
	int flag = 1; // judge whether the current loop has a swap
	for (i = 0; i < N - 1 && flag == 1; i++)
	{
		flag = 0; // flag = 0 => no swap
		for (j = 0; j < N - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		// if no swap,break circle
	}
}

int main()
{
	int arr[N];
	fillArray(arr, N);
	showArray(arr, N);
	bubble_sort(arr, N);
	showArray(arr, N);
	return 0;
}
