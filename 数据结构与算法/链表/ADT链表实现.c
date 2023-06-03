#include<stdio.h>
#include<stdlib.h>
#define dataType int
#define list struct Node
typedef struct Node{
	dataType data;
	struct Node* next;
}node;
node *head = NULL;
node *tail = NULL;

struct Node* createList(){
	node* h = (node *)malloc(sizeof(struct Node));
	h->data = 0;//头结点的data记录链表中的结点个数
	h->next = NULL;
	return h;
}

_Bool isEmpty(list *L){
	if(L->data > 0) return 0;
	else return 1;
}

_Bool isLast(node *p){
	return p->next == NULL;
}

node *find(dataType data,list* L){
	if(isEmpty(L)) return NULL;
	node *p = L;
	while(p!=NULL && p->data!=data){
		p = p->next;
	}
	if(p!=NULL) printf("find(data:%d):true\n",data);
	else printf("find(data:%d):false\n",data);
	return p;
}

node *getPreNode(node *p,list* L){
	if(isEmpty(L)) return NULL;
	node *res = L;
	while(res->next!=p && res!=NULL){
		res = res->next;
	}
	return res;
}

void deleteNode(node *p,list* L){
	if(p==head) head = getPreNode(p,L);
	else if(p==tail) tail = getPreNode(p,L);
	node *pre = getPreNode(p,L);
	pre->next = p->next;
	printf("deleteNode(data:%d)\n",p->data);
	free(p);
}

void deleteData(dataType data,list *L){
	if(L == NULL || L->next==NULL) return;
	node *p = L->next;
	node *pre;
	while(p){
		if(p->data == data) {
			pre = getPreNode(p,L);
			pre->next = pre->next->next;
			printf("deleteData(data:%d)\n",p->data);
			free(p);
			p = pre;
		}
		else p = p->next;
	}
}

void headInsert(dataType data,list* L){
	if(L == NULL)return;
	node *p = (node *)malloc(sizeof(struct Node));
	p->data = data;
	p->next = L->next;
	L->next = p;
	L->data++;
	if(L->data == 1) tail = p;
	head = p;
	printf("headInsert(%d):%d\n",L->data,p->data);//
}

void tailInsert(dataType data,list* L){
	if(L == NULL)return;
	node *p = (node *)malloc(sizeof(struct Node));
	p->data = data;
	p->next = tail->next;
	tail->next = p;
	tail = p;
	L->data++;
	printf("tailsert(%d):%d\n",L->data,p->data);//
}

void insertNode(dataType data,int index,list *L){
	node *p1 = L;
	node *p2 = (node *)malloc(sizeof(struct Node));
	p2->data = data;
	int i = 0;
	while(i < index && p1->next!=NULL){
		p1 = p1->next;
		i++;
	}
	p2->next = p1->next;
	p1->next = p2;
	if(p2->next == NULL) tail = p2;
	else if(index == 0) head = p2;
	L->data++;
	printf("insertNode(index:%d):%d\n",index,p2->data);//
}

void sort(list *L){
	if(L->data <= 1 || L == NULL) return;
	int len = L->data;
	int arr[len];
	int i,j,k,temp;
	node *p = L->next;
	k = 0;
	while(p){
		arr[k++] = p->data;
		p = p->next;
	}
	for(i = 1;i < len;i++){
		temp = arr[i];
		for(j = i - 1;j >= 0;j--)
			if(temp < arr[j]) arr[j+1] = arr[j];
				else break;
		arr[j+1] = temp;
	}
	k = 0;
	p = L->next;
	while(p){
		p->data = arr[k++];
		p = p->next;
	}
}

void traverseList(list *L){
	if(isEmpty(L)) {
		printf("链表为空\n");
		return;
	}
	node *p = L->next;
	printf("traverseList:");
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

void changeData(dataType pre,dataType cur,list* L){
	node *p = L->next;
	while(p){
		if(p->data == pre) p->data = cur;
		p = p->next;
	}
}

int main(){
	struct Node* createList();
	_Bool isEmpty(list *L);
	_Bool isLast(node *p);
	node *find(dataType data,list* L);
	node *getPreNode(node *p,list* L);
	void deleteNode(node *p,list* L);
	void headInsert(dataType data,list* L);
	void tailInsert(dataType data,list* L);
	void insertNode(dataType data,int index,list *L);
	void sort(list *L);
	void traverseList(list *L);
	void changeData(dataType pre,dataType cur,list* L);
	
	node *pt;
	list* L = createList();
	head = L;
	headInsert(29,L);
	headInsert(34,L);
	headInsert(54,L);
	tailInsert(20,L);
	tailInsert(51,L);
	tailInsert(63,L);
	insertNode(78,3,L);
	insertNode(64,7,L);
	insertNode(100,0,L);
	tailInsert(99,L);
	tailInsert(32,L);
	headInsert(49,L);
	find(51,L);
	find(100,L);
	pt = find(32,L);
	find(77,L);
	printf("isLast(data:%d):%s\n",pt->data,isLast(pt) ? "true" : "false");
	printf("headNode:%d\n",head->data);
	printf("tailNode:%d\n",tail->data);
	traverseList(L);
	sort(L);
	traverseList(L);
	deleteNode(find(100,L),L);
	deleteData(20,L);
	traverseList(L);
	changeData(99,100,L);
	traverseList(L);
	return 0;
}
