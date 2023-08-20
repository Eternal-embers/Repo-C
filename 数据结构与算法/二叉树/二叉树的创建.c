/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 08/01 08:40
	Description: 二叉树的创建
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	char data;
	struct Node *lchild;
	struct Node *rchild;
};

struct Node *createTree(char* data,int* index){
	char ch = data[(*index)];
	(*index)++;
	if(ch == '#')
		return NULL;
	else{
		struct Node *node = (struct Node *)malloc(sizeof(struct Node));
		node->data = ch;
		node->lchild = createTree(data,index);//递归创建左子树
		node->rchild = createTree(data,index);//递归创建右子树
		return node;
	}
}

void preOrder(struct Node *T){
	if(T){
		printf("%c",T->data);
  		preOrder(T->lchild);
  		preOrder(T->rchild);
	}
}

int main(){
	int index = 0;
	struct Node *T = createTree("ABD##E##CF##G##",&index);
	preOrder(T);
	return 0;
}

