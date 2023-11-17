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

void selection_Sort(int arr[], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[k] > arr[j])
				k = j; // k is the index of the largest number
		}
		// swap arr[i] and arr[k]
		int temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

int main()
{
	int arr[N];
	fillArray(arr, N);
	showArray(arr, N);
	selection_Sort(arr, N);
	showArray(arr, N);
	return 0;
}
