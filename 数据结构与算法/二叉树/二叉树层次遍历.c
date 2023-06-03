#include<stdio.h>
#include<stdlib.h>
typedef struct Tree{
	char data;
	struct Tree *lchild;
	struct Tree *rchild;
}Tree;

typedef struct Queue{
	Tree* data;
	struct Queue *pre;
	struct Queue *next;
}Queue;

void CreateTree(Tree **T,char *data,int *index){
	char ch = data[*index];
	*index +=1;
	if(ch == '#')*T = NULL;
	else {
		*T = (Tree *)malloc(sizeof(Tree));
		(*T)->data = ch;
		CreateTree(&(*T)->lchild,data,index);
		CreateTree(&(*T)->rchild,data,index);
	}
}

void preOrder(Tree *T){
	if(T == NULL)return;
	else {
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

Queue *initQueue(void){
	Queue *Q = (Queue *)malloc(sizeof(Queue));
	Q->data = NULL;
	Q->pre = Q;
	Q->next = Q;
	return Q;	
}

//尾插法 
void enQueue(Tree *T,Queue *Q){
	Queue *node = (Queue *)malloc(sizeof(Queue));
	node->data = T;
	node->pre = Q->pre;
	node->next = Q;
	Q->pre->next = node;
	Q->pre = node;

}

_Bool isEmpty(Queue *Q){
	if(Q ->next == Q)return 1;
	return 0;	
}

//头出队 
Queue* deQueue(Queue *Q){
	if(isEmpty(Q))return NULL;
	else {
		Queue *node = Q->next;
		Q->next = Q->next->next;
		Q->next->next->pre = Q;
		return node;
	}
}

void levelTraverse(Tree *T,Queue *Q){
	int flag = -1;
	Queue *node;
	enQueue(T,Q);
	while(T!=NULL){
		if(flag = -1){
			enQueue(T->lchild,Q);
			flag*=(-1);
		}
		else {
			enQueue(T->rchild,Q);
			T = T->lchild;
		}
	}
	while(!isEmpty(Q)){
		node = deQueue(Q);
		printf("%c \n",node->data->data);
	} 
}

int main(){
	Tree *T;
	Queue *Q;
	int index = 0;
	CreateTree(&T,"ABD##E##CF##G##",&index);
	preOrder(T);
	Q = initQueue();
	levelTraverse(T,Q);
	return 0;
}
