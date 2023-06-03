#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int data;
	struct queue *next;
}Node;

Node *initqueue(void)
{
	Node *Q = (Node *)malloc(sizeof(Node));
	Q->data = 0;
	Q->next = NULL;
	return Q;
}

Node *enqueue(Node *Q,int data)
{
	Node *q=Q;
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data; 
	while(q->next != NULL)
	q = q->next;
	node->next = q->next;
	q->next = node; 
	Q->data++;
}

int isEmpty(Node *Q)
{
	if(Q->data==0||Q->next==NULL)
		return 1;
	else return 0;
}

void dequeue(Node *Q)
{
	if(isEmpty(Q))
	return -1;
	else 
	{
	Node *node = Q->next;
	Q ->next= node->next;
	free(node);
	Q->data--;
	}
}
void printqueue(Node *Q)
{
	Q=Q->next;
	while(Q){
	printf("%d-->",Q->data);
	Q = Q->next;
	}
	printf("NULL\n");
}

int main()
{
	int i;
	Node *Q=initqueue();
	enqueue(Q,1);
	enqueue(Q,2);
	enqueue(Q,3);
	enqueue(Q,4);
	printqueue(Q);
	while(Q->data>0)
	dequeue(Q);
	printqueue(Q);
}
