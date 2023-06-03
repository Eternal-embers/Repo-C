#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

typedef struct QueueNode{
	TreeNode* data;
	struct QueueNode* pre;
	struct QueueNode* next;
}QueueNode;

QueueNode* initQueue(){
	QueueNode* Q = (QueueNode *)malloc(sizeof(QueueNode));
	Q->data = NULL;
	Q->pre = Q;
	Q->next = Q;
	return Q;
}

void enQueue(TreeNode* data,QueueNode* Q){
	QueueNode* node = (QueueNode *)malloc(sizeof(QueueNode));
	node->data = data;
	node->next = Q;
	node->pre = Q->pre;
	Q->pre->next = node;
	Q->pre = node;
}

_Bool isEmpty(QueueNode* Q){
	return Q->next == Q;
}

QueueNode* deQueue(QueueNode* Q){
	if(isEmpty(Q)) return NULL;
	else {
		QueueNode* node = Q->next;
		node->next->pre = Q;
		Q->next = node->next;
		return node;
	}
}

void createTree(TreeNode** T,char* data,int* index){
	char ch = data[(*index)++];
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		createTree(&(*T)->lchild,data,index);
		createTree(&(*T)->rchild,data,index);
	}
}

void preOrder(TreeNode* T){
	if(T){
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void levelTraverse(QueueNode* Q,TreeNode* T){
    enQueue(T,Q);
    while(!isEmpty(Q)){//如果队列不为空
    	QueueNode* node = deQueue(Q);//出队
    	printf("%c ",node->data->data);//输出出队的结点的数据
    	//将每一个结点的左孩子和右孩子入队
		if(node->data->lchild){
			enQueue(node->data->lchild,Q);
		}
		if(node->data->rchild){
			enQueue(node->data->rchild,Q);
		}
	}
}

int main(){
	TreeNode* T;
	int index = 0;
	QueueNode* Q = initQueue();
	createTree(&T,"ABD##E##CF##G##",&index);
	preOrder(T);
	printf("\n");
	levelTraverse(Q,T);
	return 0;
}
