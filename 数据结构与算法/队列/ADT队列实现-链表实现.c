#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define dataType int
#define queue struct Node
#define null -1
typedef struct Node{
	dataType data;
	struct Node *next;
}node;

queue *createQueue(){
	queue* head = (queue*)malloc(sizeof(queue));
	head->data = 0;
	head->next = NULL;
	return head;
}

_Bool isEmpty(queue *q){
	return q->next == NULL;
}

void enQueue(dataType data,queue *q){
	node *tail = q;
	node *p = (node *)malloc(sizeof(node));
	p->data = data;
	while(tail->next){
		tail = tail->next;
	}//尾插
	p->next = tail->next;
	tail->next = p;
	q->data++;
}

dataType deQueue(queue *q){
	if(isEmpty(q)) return null;
	dataType data;
	node *p = q->next;
	q->next = q->next->next;
	data = p->data;
	free(p);
	q->data--;
	return data;
}

void clear(queue *q){
	node *p = q->next;
	while(p){
		node *pt = p;
		p = p->next;
		free(pt);
	}
	q->data = 0;
}

void traverseQueue(queue *q){
	node *p = q->next;
	printf("traverseQueue:");
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

void queueSort(queue *q){
	if(q->data <= 1) return;
 	int len = q->data;
	dataType arr[len];
	node *p;
	int i,j;
	dataType temp;
	i = 0,p = q->next;
	while(p){
		arr[i++] = p->data;
		p = p->next;
	}//读取数据
	for(i = 1;i < len;i++){
		temp = arr[i];
		for(j = i-1;j >= 0;j--)
			if(temp < arr[j]) arr[j+1] = arr[j];
				else break;
		arr[j+1] = temp;
	}//插入排序
	i = 0,p = q->next;
	while(p){
		p->data = arr[i++];
		p = p->next;
	}//数据进入队列
}
int main(){
	queue *createQueue();
	_Bool isEmpty(queue *q);
	void enQueue(dataType data,queue *q);
	dataType deQueue(queue *q);
	void clear(queue *q);
	void traverseQueue(queue *q);
	void queueSort(queue *q);
	queue *q = createQueue();
	int i;
	srand(time(NULL));
	for(i = 0;i < 20;i++)
		enQueue(rand()%100+1,q);
	traverseQueue(q);
	queueSort(q);
	traverseQueue(q);
	for(i = 0;i < 10;i++)
		printf("deQueue(q):%d\n",deQueue(q));
	traverseQueue(q);
	clear(q);
	printf("isEmpty(q):%s\n",isEmpty ? "true" : "false");
	return 0;
}
