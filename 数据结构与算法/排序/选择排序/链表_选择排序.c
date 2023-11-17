#include <stdio.h>
#include <stdlib.h>
#define dataType int
#define list struct Node

typedef struct Node
{
	dataType data;
	struct Node *next;
} node;

node *head = NULL;
node *tail = NULL;

struct Node *createList()
{
	node *head = (node *)malloc(sizeof(struct Node));
	head->data = 0; // the header node records the togal number of nodes
	head->next = NULL;
	return head;
}

_Bool isEmpty(list *L)
{
	if (L->data > 0)
		return 0;
	else
		return 1;
}

void tailInsert(dataType data, list *L)
{
	if (L == NULL)
		return;
	if (tail == NULL)
		tail = L;
	node *p = (node *)malloc(sizeof(struct Node));
	p->data = data;
	p->next = tail->next;
	tail->next = p;
	tail = p;
	L->data++;
	printf("tailsert(%d):%d\n", L->data, p->data); //
}

node *getPreNode(node *p, list *L)
{
	if (isEmpty(L))
		return NULL;
	node *res = L->next;
	while (res->next != p && res != NULL)
	{
		res = res->next;
	}
	return res;
}

void traverseList(list *L)
{
	if (isEmpty(L))
	{
		printf("The linked is empty!\n");
		return;
	}
	node *p = L->next;
	printf("traverseList:");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
}

void listSort(list *L)
{
	if (L->data <= 1 || L == NULL)
		return;
	node *p1, *p2, *p;
	dataType t;
	p1 = L->next;
	while (p1)
	{
		p2 = p1->next;
		p = p1;
		while (p2)
		{
			if (p2->data < p->data)
				p = p2;
			p2 = p2->next;
		}
		t = p1->data;
		p1->data = p->data;
		p->data = t;
		p1 = p1->next;
	}
}

int main()
{
	struct Node *createList();
	void tailInsert(dataType data, list * L);
	node *getPreNode(node * p, list * L);
	void traverseList(list * L);
	void listSort(list * L);
	list *L = createList();
	tailInsert(23, L);
	tailInsert(36, L);
	tailInsert(12, L);
	tailInsert(89, L);
	tailInsert(65, L);
	tailInsert(35, L);
	tailInsert(287, L);
	tailInsert(48, L);
	traverseList(L);
	listSort(L);
	traverseList(L);
	return 0;
}
