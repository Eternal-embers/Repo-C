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
    printf("create list succeed\n");
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

int delete(List list, ElemType key)
{
    int flag = 0;
    List head = list, pre;
    pre = list;
    list = list->next; // 从头节点下一个节点开始
    while (list)
    {
        if (list->key == key)
        {
            pre->next = list->next;
            free(list);
            flag = 1;
            break;
        }
        pre = pre->next;
        list = list->next;
    }
    return flag;
}

int main()
{
    int arr[10] = {12, 6, 4, 20, 14, 7, 9, 36, 10, 15};
    List list = createList(arr, 10);
    printf("createList: ");
    traverseList(list);
    int status = delete (list, 14);
    if (status)
        printf("delete the element of %d succeed.\n");
    printf("result of deleting the 14 element: ");
    traverseList(list);
    return 0;
}