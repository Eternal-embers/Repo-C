#include<stdio.h>
#include<stdlib.h>
#define dataType int
#define null -1
struct Queue{
	dataType *queue;
	int capacity;//队列最大容量
	int size;//记录队列中的元素个数
	int front;
	int rear;
};

struct Queue *initQueue(int capacity){
	struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
	q->capacity = capacity;
	q->queue = (dataType *)calloc(q->capacity,sizeof(dataType));
	q->size = 0;
	q->front = 0;
	q->rear = 0;
	return q;
}

_Bool isEmpty(struct Queue *q){
	return q->size == 0;
}

_Bool isFull(struct Queue *q){
	return q->size == q->capacity - 1;
}
void enQueue(dataType data,struct Queue *q){
	if(isFull(q)) return;
	if(q->size==0) q->rear = q->rear;
	q->queue[q->rear++] = data;
	q->rear = q->rear % q->capacity;
	q->size++;
}

dataType deQueue(struct Queue *q){
	if(q->size == 0) return null;
	dataType data = q->queue[q->front++];
	q->front = q->front % q->capacity;
	q->size--;
	return data;
}

void clear(struct Queue *q){
	free(q->queue);
	q->size = 0;
	q->front = 0;
	q->rear = 0;
}

void traverseQueue(struct Queue *q){
	if(isEmpty(q)) return;
	int i = q->front;
	printf("traverseQueue:");
	while(i != q->rear){
		printf("%d ",q->queue[i++]);
		i = i % q->capacity;
	}
	putchar('\n');
}

dataType getFront(struct Queue *q){
	return q->queue[q->front];
}

dataType getRear(struct Queue *q){
	return q->queue[q->rear-1];
}
int main(){
	struct Queue *initQueue(int capacity);
	_Bool isEmpty(struct Queue *q);
	_Bool isFull(struct Queue *q);
	void enQueue(dataType data,struct Queue *q);
	dataType deQueue(struct Queue *q);
	void clear(struct Queue *q);
	void traverseQueue(struct Queue *q);
	dataType getFront(struct Queue *q);
	dataType getRear(struct Queue *q);
	
	struct Queue *q = initQueue(20);
	srand(time(NULL));
	int i;
	for(i = 0;i < 19;i++)
		enQueue(rand()%100 + 1,q);
	printf("queue-size:%d\n",q->size);
	traverseQueue(q);
	for(i = 0;i < 10;i++)
		printf("deQueue(q):%d\n",deQueue(q));
	traverseQueue(q);
	for(i = 0;i < 5 ;i++)
		enQueue(rand()%100 + 1,q);
	traverseQueue(q);
	printf("front:queue[%d]:%d\n",q->front,getFront(q));
	printf("rear:queue[%d]:%d\n",q->rear - 1,getRear(q));
	return 0;
}
