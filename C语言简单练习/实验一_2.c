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

void delete(List list, unsigned index)
{
    int i = 0;
    for (i = index; i < list->length; i++)
        list->element[i] = list->element[i + 1]; // 向前填充
    list->length--;
} // checked

void insert(List list, unsigned pos, ElemType key)
{
    int i = 0;
    for (i = list->length - 1; i >= pos; i--)
        list->element[i + 1] = list->element[i]; // 向后复制
    list->element[pos] = key;
    list->length++;
} // checked

void operate(List list)
{
    int max, min, maxValue, i;
    max = 0, min = 0;
    for (i = 0; i < list->length; i++)
    {
        if (list->element[i] > list->element[max])
            max = i;
        if (list->element[i] < list->element[min])
            min = i;
    }
    maxValue = list->element[max];   // 记录最大值
    delete (list, max);              // 删除最大值
    insert(list, min + 1, maxValue); // 在min索引的位置后面插入maxValue
} // checked

/*
    测试数据：
    输入：
    10
    12 6 4 20 14 7 9 36 10 15
    输出：12 6 4 36 20 14 7 9 10 15
*/
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
    operate(list);
    printf("output: ");
    traverseList(list);
    return 0;
}