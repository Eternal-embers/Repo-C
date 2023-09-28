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
	/* �����ڵ� */
	if(head->next==NULL || list->data != data){//�ж����һ���ڵ�������Ƿ�����Ҫ����������ظ�
		Node *node=(Node*)malloc(sizeof(Node));
		node->data=data;
		node->next=NULL;
		list->next=node;
		head->data++;//ͷ�ڵ��м�¼�Ľڵ�����һ
	}
}

void printlist(Node* list)
{
	if(list->next==NULL) {
		printf("����Ϊ��!\n");
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
	printf("���������������ݣ�");
	printlist(list);
	/* ���Բ����ظ����� */
	printf("���Բ����ظ����ݣ�");
	tailinsert(list,5);
	tailinsert(list,8);
    printlist(list);
    return 0;
	}
