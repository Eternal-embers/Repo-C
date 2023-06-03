/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
	struct TreeNode *parent;
	int ltag;
	int rtag;
}TreeNode;

void createTree(TreeNode** T,char *data,int *index,TreeNode* parent){
	char ch = data[(*index)++];
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->parent = parent;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		createTree(&(*T)->lchild,data,index,*T);
		createTree(&(*T)->rchild,data,index,*T);
	}
}

void preOrder(TreeNode *T){
	if(T){
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

TreeNode *getFirst(TreeNode *node){
	while(node->ltag == 0){
		node = node->lchild;
	}
	if(node->rtag == 0) node = getFirst(node->rchild);
	return node;
}

TreeNode *getNext(TreeNode *node){
	if(node->rtag == 1) return node->rchild;
	else {
		if(node->parent == NULL) return NULL;//如果是根结点
		else if(node->parent->lchild == node){//如果是左孩子
			if(node->parent->rtag == 0) return getFirst(node->parent->rchild);
				else return node->parent;
		}
		else return node->parent;//如果是右孩子
	}
}

void postThreadTree(TreeNode *T,TreeNode **pre){
	if(T){
		postThreadTree(T->lchild,pre);
		postThreadTree(T->rchild,pre);
		if(T->lchild == NULL){
			T->lchild = *pre;
			T->ltag = 1;
		}
		if(*pre && (*pre)->rchild == NULL){
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
		}
		*pre = T;
	}
}

int main(){
	TreeNode *T,*node,*pre = NULL;
	int index = 0;
	createTree(&T,"ABD#H##E##CF#I##G##",&index,NULL);
	preOrder(T);
	printf("\n");
	postThreadTree(T,&pre);
	for(node = getFirst(T);node;node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}

