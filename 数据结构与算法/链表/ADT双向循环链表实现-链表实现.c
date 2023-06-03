#include<stdio.h>
#include<stdlib.h>
#define dataType int
#define null -1
typedef struct Node{
	dataType data;
	struct Node *pre;
	struct Node *next;
}node,*list;

list createList(){
	list L = (list)malloc(sizeof(struct Node));
	L->data = -1;
	L->next = L;
	L->pre = L;
}

void headInsert(dataType data,list L){
	node *p = (node *)malloc(sizeof(node));
	p->data = data;
	p->next = L->next;
	p->pre = L;
	L->next->pre = p;
	L->next = p;
}

void tailInsert(dataType data,list L){
	node *p = (node *)malloc(sizeof(node));
	p->data = data;
	p->pre = L->pre;
	p->next = L;
	L->pre->next = p;
	L->pre = p;
}

void insert(dataType data,int index,list L){
	node *p1 = L->next;
	node *p2 = (node *)malloc(sizeof(node));
	p2->data = data;
	int i = 0;
	while(i < index && p1 != L){
		p1 = p1->next;
		i++;
	}
	p1->pre->next = p2;
	p2->next = p1;
	p2->pre = p1->pre;
	p1->pre = p2;
}

void deleteNode(node *p){
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
}

void deleteData(dataType data,list L){
	node *p = L->next;
	node *pt;
	while(p != L){
		if(p->data == data){
			pt = p->next;
			p->pre->next = p->next;
			p->next->pre = p->pre;
			free(p);
			p = pt;
		}
		else p = p->next;
	}
}

node* findNode(dataType data,list L){
   node *p = L->next;
   while(p != L){
		if(p->data == data) return p;
		else p = p->next;
   }
   return NULL;
}

void changeData(dataType pre,dataType cur,list L){
	node *p = L->next;
	while(p != L){
		if(p->data == pre) p->data = cur;
		p = p->next;
	}
}

void traverseList(list L){
	node *p = L->next;
	printf("traverseList:");
	while(p!=L){
		printf("%d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

int main(){
	list createList();
	void headInsert(dataType data,list L);
	void tailInsert(dataType data,list L);
	void insert(dataType data,int index,list L);
	void deleteNode(node *p);
	void deleteData(dataType data,list L);
	node* findNode(dataType data,list L);
	void changeData(dataType pre,dataType cur,list L);
	void traverseList(list L);
	
	list L = createList();
	headInsert(25,L);
	tailInsert(35,L);
	tailInsert(45,L);
	tailInsert(55,L);
	tailInsert(65,L);
	headInsert(15,L);
	headInsert(10,L);
	headInsert(5,L);
	tailInsert(75,L);
	tailInsert(85,L);
	insert(30,4,L);
	insert(90,11,L);
	insert(-1,6,L);
	insert(32,3,L);
	traverseList(L);
	deleteNode(findNode(-1,L));
	deleteData(32,L);
	changeData(90,100,L);
	traverseList(L);
	return 0;
}


