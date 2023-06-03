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
}TreeNode;

TreeNode* bstSearch(TreeNode *T,int data){
	if(T){
		if(T->data == data) return T;
		else if(data < T->data) return bstSearch(T->lchild,data);
		else return bstSearch(T->rchild,data);
	}
	else return NULL;
}

TreeNode* MakeEmpty(TreeNode* T){
	if(T != NULL) {
		MakeEmpty(T->lchild);
		MakeEmpty(T->rchild);
		free(T);
	}
	return NULL;
}

TreeNode* findMin(TreeNode *T){
	if(T == NULL) return NULL;
	else if(T->lchild == NULL) return T;
	else return findMin(T->lchild);
}

TreeNode* findMax(TreeNode *T){
	if(T == NULL) return NULL;
	else if(T->rchild == NULL) return T;
	else return findMax(T->rchild);
}

TreeNode* bstInsert(TreeNode** T,int data){
	if(*T == NULL) {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = data;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}//如果此时找到插入点，则插入
	else if(data == (*T)->data){
		return;
	}//与查找树中的数据重复直接返回
	else if(data < (*T)->data) {
		bstInsert(&((*T)->lchild),data);
	}//小于该节点的数据，遍历其左子树
	else {
		bstInsert(&((*T)->rchild),data);
	}//大于该节点的数据，遍历其右子树
}

void preOrder(TreeNode *T){
	if(T){
		printf("%d ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
int main(){
	TreeNode *T = NULL;
    int num[10] = {10,4,5,19,23,2,8,6,12,3};
	int i;
    for(i = 0;i < 10;i++){
		bstInsert(&T,num[i]);
	}
	preOrder(T);
	printf("%d\n",bstSearch(T,19)->data);
	printf("%d\n",findMin(T)->data);
	printf("%d\n",findMax(T)->data);
	return 0;
}

