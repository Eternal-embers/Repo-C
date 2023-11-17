#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 21

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

void shellSort(int arr[], int n)
{
    int gap, i, j;
    int temp;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i - gap; j >= 0; j -= gap)
            {
                if (temp < arr[j])
                    arr[j + gap] = arr[j]; // 向后挪位
                else
                    break;
            }
            arr[j + gap] = temp;
        }
    }
}

int main()
{
    int arr[N];
    fillArray(arr, N);
    showArray(arr, N);
    shellSort(arr, N);
    showArray(arr, N);
    return 0;
}