#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node*next;
}Node;

Node* initlist(void)
{
	Node *list=(Node*)malloc(sizeof(Node));
	list->data=0;
	list->next=NULL;
	return list;
}

void tailinsert(Node *list,int data)
{
	Node *head=list;
	while(list->next)
	{
		if(list->data == data) return;
		list = list->next;
	}
	/* 创建节点 */
	if(head->next==NULL || list->data != data){//判断最后一个节点的数据是否与需要插入的数据重复
		Node *node=(Node*)malloc(sizeof(Node));
		node->data=data;
		node->next=NULL;
		list->next=node;
		head->data++;//头节点中记录的节点数加一
	}
}

void printlist(Node* list)
{
	if(list->next==NULL) {
		printf("链表为空!\n");
		return;
	}
	list=list->next;
	while(list)
	{
		printf("%d ",list->data);
		list=list->next;
	}
	printf("\n");
}
int main()
{
	Node *list = initlist();
	tailinsert(list,5);
	tailinsert(list,6);
	tailinsert(list,7);
	tailinsert(list,8);
	printf("创建链表并插入数据：");
	printlist(list);
	/* 测试插入重复数据 */
	printf("测试插入重复数据：");
	tailinsert(list,5);
	tailinsert(list,8);
    printlist(list);
    return 0;
	}
