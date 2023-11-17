#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int count = 0;
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
    {
        printf("  %3d  ", arr[i]);
        if ((i + 1) % 20 == 0)
            putchar('\n');
    }
    printf("\n");
}

/*
    Sedgewick increasement sequence: 9 * 4^i - 9 * 2^i + 1 or 4^i - 3 * 2^i + 1
    1,5,9,41,109,209,505,929,2161 ...
*/
void shell_sort(int arr[], int len)
{
    int step[10] = {0, 1, 5, 9, 41, 109, 209, 505, 929, 2161};
    int i, j, temp;
    int *gap;
    for (i = 0; i < 10; i++)
    {
        if (len > step[i])
            gap = step + i;
    }
    while (*gap > 0)
    {
        for (i = *gap; i <= len - *gap; i++)
        {
            temp = arr[i];
            for (j = i - *gap; j >= 0 && arr[j] > temp; j -= *gap)
                arr[j + *gap] = arr[j];
            arr[j + *gap] = temp;
            count++;
        }
        gap--;
    }
}

int main()
{
    int arr[N];
    fillArray(arr, N);
    showArray(arr, N);
    shell_sort(arr, N);
    showArray(arr, N);
    return 0;
}
