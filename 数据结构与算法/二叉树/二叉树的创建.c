/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 08/01 08:40
	Description: �������Ĵ���
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
		node->lchild = createTree(data,index);//�ݹ鴴��������
		node->rchild = createTree(data,index);//�ݹ鴴��������
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

