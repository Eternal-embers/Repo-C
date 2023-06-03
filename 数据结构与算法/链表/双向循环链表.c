#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node *initlist(void)
{
	Node *L = (Node *)malloc(sizeof(Node));
	L->data = 0;
	L->pre = NULL;
	L->next = NULL;
	return L;
}

void headinsert(Node *L,int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	if(L->data==0)
	{
		node->next = L;
		node->pre = L;
		L->next = node;
		L->pre = node;
	}
	else{
		//链表不为空
		node->next = L->next;
		node->pre = L;
		L->next->pre = node;
		L->next = node;
	}
	L->data++;
}

void taillist(Node *L,int data)
{
	Node *node =(Node *)malloc(sizeof(Node));
	node->data = data;
	Node *p = L;
	while(p->next != L)
	{
		p = p->next;
	}
	node->pre = p;
	node->next = L;
	p->next = node;
	L->pre = node;
	L->data++;
}

void deletelist(Node *L,int data)
{
	Node *left = L;
	Node *node = L->next;
	while(node != L)
	{
		if(node->data==data){
			left->next=node->next;
			node->next->pre=left;
			free(node);
			L->data--;
			break;//如果要删除多个重复数据，这里可以去掉break 
		}
		left=node;
		node=node->next;
	}
}

void printlist(Node *L)
{
	Node *node=L->next;
	while(node!=L)
	{
		printf("%d-->",node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main()
{
	Node *L=initlist();
	headinsert(L,1);
	headinsert(L,2);
	headinsert(L,3);
	headinsert(L,4);
	printlist(L); 
	taillist(L,5);
	taillist(L,6);
	taillist(L,7);
	taillist(L,8);
	printlist(L); 
	deletelist(L,8);
	deletelist(L,2);
	printlist(L);
	return 0;
}
