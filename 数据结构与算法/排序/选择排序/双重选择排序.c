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
	// double selection sort
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int min = left;	 // the index of the smallest number
		int max = right; // the index of the largest number
		int i;
		// select the minimum and maximum numbers
		for (i = left; i <= right; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}
		int temp;
		if (max != right) // swap arr[max] and arr[right]
		{
			temp = arr[right];
			arr[right] = arr[max];
			arr[max] = temp;
		}

		if (min == right) // if min = left and max = right
			min = max;

		if (min != left) // swap arr[min] and arr[left]
		{
			temp = arr[left];
			arr[left] = arr[min];
			arr[min] = temp;
		}

		// narrow down
		left++;
		right--;
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
