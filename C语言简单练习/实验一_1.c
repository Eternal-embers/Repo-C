#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAXSIZE 100
#define ElemType int

typedef struct table
{
    ElemType *element;
    int length;
} *List;

List initList(ElemType arr[], unsigned size)
{
    List list = (List)malloc(sizeof(struct table));
    list->element = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    memset(list->element, 0, sizeof(ElemType));
    int i;
    for (i = 0; i < size; i++)
    {
        list->element[i] = arr[i];
    }
    list->length = size;
    return list;
}

void traverseList(List list)
{
    int i;
    for (i = 0; i < list->length; i++)
    {
        printf("%d ", list->element[i]);
    }
    putchar('\n');
}

void reverse(List list)
{
    int left = 0;
    int right = list->length - 1;
    while (left < right)
    {
        int t = list->element[right];
        list->element[right] = list->element[left];
        list->element[left] = t;
        left++;
        right--;
    }
}

int main()
{
    int i, n = 0;
    printf("please input the number of element: ");
    scanf("%d", &n);
    printf("please input %d number: ", n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    List list = initList(arr, n);
    printf("initList: ");
    traverseList(list);
    reverse(list);
    printf("reverse List: ");
    traverseList(list);
    return 0;
}