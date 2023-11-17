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
        showArray(arr, n);
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
        showArray(arr, n);
    }
}

void Bubble_Sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        showArray(arr, n);
    }
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
        showArray(arr, n);
    }
}

int main()
{
    /*
        23 12 3 45 29 33 62 16 9 10 25 30 1 43 21
    */
    int i, n;
    printf("n = ");
    scanf("%d", &n);
    int arr[n];
    printf("please input %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int option = 0;
    printf("  exit                  >> 0\n");
    printf("  insertSort            >> 1\n");
    printf("  binaryInsertSort      >> 2\n");
    printf("  bubbleSort            >> 3\n");
    printf("  selectionSort         >> 4\n");
    printf("  option = ");
    scanf("%d", &option);
    switch (option)
    {
    case 0:
        return 0;
        break;
    case 1:
        insertion_sort(arr, n);
        break;
    case 2:
        binary_insertion_sort(arr, n);
        break;
    case 3:
        Bubble_Sort(arr, n);
        break;
    case 4:
        selection_Sort(arr, n);
        break;
    default:
        printf("error!");
    }
    printf("result: ");
    showArray(arr, n);
    return 0;
}