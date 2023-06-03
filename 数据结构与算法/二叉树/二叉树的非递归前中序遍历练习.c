/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:2023/3.21 09:17
	Description:复习二叉树的非递归前中序遍历
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
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

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[(*index)++];
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild,data,index);
		createTree(&(*T)->rchild,data,index);
	}
}

void preOrder(TreeNode *T){
	if(T == NULL) return;
	else {
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void preOrder_iteration(TreeNode *T){
	stackNode *s = initStack();
	TreeNode *node = T;
	while(node || !isEmpty(s)){
		if(node){
			printf("%c ",node->data);//进栈时输出
			push(node,s);
			node = node->lchild;
		}
		else {
			node = pop(s)->data;
			node = node->rchild;
		}
	}
}//根左右

void inOrder(TreeNode *T){
	stackNode *s = initStack();
	TreeNode *node = T;
	while(node || !isEmpty(s)){
		if(node){
			push(node,s);
			node = node->lchild;
		}
		else {
			node = pop(s)->data;
			printf("%c ",node->data);//出栈时输出
			node = node->rchild;
		}
	}
}//左根右

int main() {
	TreeNode *T;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);
	preOrder(T);
	printf("\n");
	preOrder_iteration(T);
	printf("\n");
	inOrder(T);
	return 0;
}


