#include <stdio.h>
#include <stdlib.h>
#define ElemType int

typedef struct List
{
    ElemType key;
    struct List *next;
} *List;

List createList(int arr[], unsigned size)
{
    /* list作为链表的头节点 */
    List head = (List)malloc(sizeof(struct List));
    List p1, p2;
    p1 = (List)malloc(sizeof(struct List));
    p1->key = arr[0];
    p2 = NULL;
    int i;
    /* 尾插法 */
    for (i = 0; i < size; i++)
    {
        if (i == 0)
            head->next = p1;
        else
        {
            p1->key = arr[i];
            p2->next = p1;
        }
        p2 = p1;
        p1 = (List)malloc(sizeof(struct List));
    }
    p2->next = NULL;
    free(p1);
    head->key = size; // 头节点的数据记录链表中节点个数
    return head;
}

void traverseList(List list)
{
    list = list->next; // 头节点的下一个节点开始
    while (list)
    {
        printf("%d ", list->key);
        list = list->next;
    }
    putchar('\n');
}

void operate(List list)
{
    List pt, pre; // pt指向list的前一个节点，pre指向max的前一个节点
    pt = list, pre = list;
    list = list->next;
    List max, min;
    max = (List)malloc(sizeof(struct List));
    min = (List)malloc(sizeof(struct List));
    max->key = -2147483648;
    min->key = 2147483647;
    while (list)
    {

        if (list->key > max->key)
        {
            max = list;
            pre = pt;
        }
        if (list->key < min->key)
            min = list;
        pt = pt->next;
        list = list->next;
    }
    pre->next = max->next;
    max->next = min->next;
    min->next = max;
}

int main()
{
    int arr[10] = {12, 6, 4, 20, 14, 7, 9, 36, 10, 15};
    List list = createList(arr, 10);
    printf("createList: ");
    traverseList(list);
    operate(list);
    printf("result: ");
    traverseList(list);
    return 0;
}