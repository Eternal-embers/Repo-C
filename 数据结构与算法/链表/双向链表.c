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
	if(L->data==0){
		node->data = data;
		L->next = node;
		node->pre = L;
		node->next = NULL;
	}		
	else{
		node->data = data;
		L->next->pre = node;
		node->next = L->next;
		L->next = node;
		node->pre = L;
	}
	L->data++;
}

void tailinsert(Node *L,int data)
{
	Node *p;
	Node *node = (Node *)malloc(sizeof(Node));
	while(p->next)
	{
		p = p->next;
	}
	node->data = data;
	node->next = NULL;
 	node->pre = p;
 	p->next = node;
 	L->data++;
}

void deletelist(Node *L,int data)
{
	Node *left=L;
	Node *p = L->next;
	while(p)
	{
		if(p->data==data){
			if(p->next==NULL){
			left->next=NULL;
			free(p);
			break;
			} 
				else{
				left->next = p->next;
				p->next->pre = p->pre;
				free(p);
				break;//如果要删除多个重复数据，将break去掉 
				}
		}
		left=p;
		p=p->next;
	}
	L->data--;
}

void printlist(Node *L)
{
	L = L->next;
	while(L)
	{
	printf("%d --> ",L->data); 
	L = L->next;
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
	tailinsert(L,5);
	tailinsert(L,6);
	tailinsert(L,7);
	tailinsert(L,8);
	printlist(L);
	deletelist(L,8);
	deletelist(L,2);
	printlist(L);
	return 0;
	
}
