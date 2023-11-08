#include <stdio.h>
#include <stdlib.h>

/* 对顺序表进行查找 */
int search(int arr[], int size, int dest)
{
    int list[size + 1], i;
    list[0] = dest; // 哨兵，用于查找时的截止
    for (i = 0; i < size; i++)
        list[i + 1] = arr[i];
    for (i = size; list[i] != dest; i--)
    {
    }
    return i;
}

/* 插入排序,从小到大排序 */
int sort(int arr[], int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
    {
        t = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (t < arr[j])
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = t;
    }
}

/* 对有序数组进行查找 */
int binarySearch(int arr[], int size, int dest)
{
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] < dest)
            right = mid - 1;
        else if (arr[mid] > dest)
            left = mid + 1;
        else
            return mid;
        printf("%d ", mid);
    }
    return -1;
}

int main()
{
    /*
        10
        24 19 8 26 13 7 25 12 23 11
    */
    int arr[100], n, dest;
    printf("please input the number of sequence: ");
    scanf("%d", &n);
    printf("please input %d numbers: ", n);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("dest: ");
    scanf("%d", &dest);

    printf("\nsequential search:\n");
    int res1 = search(arr, n, dest);
    if (res1 > 0)
        printf("search success:dest is at index %d\n", res1);
    else
        printf("search failed\n");

    printf("\nbinary search:\n");
    sort(arr, n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    putchar('\n');
    int res2 = binarySearch(arr, n, dest);
    if (res2 >= 0)
        printf("search success: dest is at index %d\n", res2);
    else
        printf("search failed\n");
    return 0;
}