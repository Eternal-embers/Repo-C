/*
	Name:二叉树的后序遍历非递归版
	Copyright:劣等生
	Author:劣等生
	Date:21/03/23 16:5721/03/23 16:57
	Description:
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
	_Bool flag;
}TreeNode;

typedef struct stackNode{
	struct TreeNode *data;
	struct stackNode *next;
}stackNode;

stackNode *initStack(){
	stackNode *s = (stackNode *)malloc(sizeof(stackNode));
	s->data = NULL;
	s->next = NULL;
	return s;
}

_Bool isEmpty(stackNode *s){
	return s->next == NULL;
}

void push(TreeNode *T,stackNode *s){
	stackNode *node = (stackNode *)malloc(sizeof(stackNode));
	node->data = T;
	node->next = s->next;
	s->next = node;
}

stackNode *pop(stackNode *s){
	if(isEmpty(s)) return NULL;
	else {
		stackNode *node = s->next;
		s->next = node->next;
		return node;
	}
}

stackNode *getTop(stackNode *s){
	if(isEmpty(s)) return NULL;
	else {
		stackNode *node = s->next;
		return node;
	}
}

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[(*index)++];
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->data = ch;
		(*T)->flag = 0;
		createTree(&(*T)->lchild,data,index);
		createTree(&(*T)->rchild,data,index);
	}
}

void preOrder(TreeNode *T){
	if(T){
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

//二叉树的非递归后序遍历，左右根
//从根结点开始，一直向左遍历，将遍历的结点压入栈中，直到结点为空
//找到最左边的结点后，获取栈顶元素，如果出栈的结点有右孩子且未被访问过，则访问该出栈结点的右孩子，将其压入栈中，并标记访问
//对出栈结点的右孩子重复前面的操作，直到结点为空且栈顶元素没有右孩子或者右孩子被访问过了，此时出栈，并且输出出栈元素的数据
//再继续获取栈顶元素，并重复前面的这些操作，直到结点为空且栈为空
void postOrder(TreeNode* T){
	TreeNode* node = T;
	stackNode* S = initStack();
	while(node || !isEmpty(S)){//如果结点不为空且栈不为空
		if(node){
			push(node,S);//将左孩子压栈
			node = node->lchild;
		}
		else {//如果结点为空或者栈空
			TreeNode* top = getTop(S)->data;//获取栈顶元素
			if(top->rchild && top->rchild->flag == 0){//如果有右孩子且右孩子未访问过
				top = top->rchild;
				push(top,S);//将右孩子压入栈中
				node = top->lchild;//访问它的左孩子
			}
			else {
				top = pop(S)->data;//出栈
				printf("%c ",top->data);
				top->flag = 1;//标记出栈元素
			}//此时node还是空结点，直到出栈到有有孩子的结点为止
		}
	}
}

int main() {
	TreeNode *T;
	int index = 0;
	createTree(&T,"ABD#F##E##C##",&index);
	preOrder(T);
	putchar('\n');
	postOrder(T);
	return 0;
}


