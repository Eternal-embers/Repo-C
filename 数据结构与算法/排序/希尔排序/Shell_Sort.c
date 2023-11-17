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

void Shell_Sort(int arr[], int n)
{
	int i, j, gap, temp;
	for (gap = n; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i += gap)
		{
			temp = arr[i];
			for (j = i - gap; j >= 0; j -= gap)
				if (temp < arr[j])
					arr[j + gap] = arr[j];
				else
					break;
			arr[j + gap] = temp;
		}
	}
}

int main()
{
	int arr[N];
	fillArray(arr, N);
	showArray(arr, N);
	Shell_Sort(arr, N);
	showArray(arr, N);
	return 0;
}
