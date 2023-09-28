#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int key;
    struct linkedList *next;
} *list;

list createList()
{
    list head = (list)malloc(sizeof(struct linkedList));
    head->key = 0;
    head->next = NULL;
    return head;
}

/* 尾插法 */
void tailInsert(list L, int key)
{
    /* create a new node */
    list node = (list)malloc(sizeof(struct linkedList));
    node->key = key;
    /* get the last node of list */
    while (L->next)
    {
        L = L->next;
    }
    node->next = L->next;
    L->next = node;
}

list initList(int arr[], int length)
{
    /* create the list */
    list head = createList();
    int i;
    /* insert */
    for (i = 0; i < length; i++)
    {
        tailInsert(head, arr[i]);
        head->key++;
    }
    return head;
}

int getAverage(list L)
{
    int length = L->key;
    int sum = 0;
    L = L->next;
    while (L)
    {
        sum += L->key;
        L = L->next;
    }
    return sum / length;
}

void traverseList(list L)
{
    L = L->next;
    while (L)
    {
        printf("%d ", L->key);
        L = L->next;
    }
    putchar('\n');
}

int main()
{
    int i, n;
    printf("pleases input the number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("please input %d number: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    list L = initList(arr, n);
    printf("initList: ");
    traverseList(L);
    printf("average: %d\n", getAverage(L));
}