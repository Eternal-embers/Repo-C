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
	int ltag;
	int rtag;
}TreeNode;

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[*index];
	*index += 1;
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		createTree(&(*T)->lchild,data,index);
		createTree(&(*T)->rchild,data,index);
	}
}

//将二叉树线索化，先序遍历：根左右
//按照先序遍历的顺序遍历整棵二叉树
//在遍历二叉树的过程，将空的左孩子指向该节点的前驱，空的右孩子指向该节点的后继
void preThreadTree(TreeNode* T,TreeNode** pre){
	//先线索化，再递归进行先序遍历
	if(T){
		if(T->lchild == NULL) {
			T->lchild = *pre;
			T->ltag = 1;
		}
		if(*pre != NULL && (*pre)->rchild == NULL) {
			(*pre)->rchild = T;
			(*pre)->rtag = 1;
		}
		*pre = T;
		//递归遍历
		if(T->ltag == 0) preThreadTree(T->lchild,pre);
		if(T->rtag == 0) preThreadTree(T->rchild,pre);
	}
}

TreeNode* getNext(TreeNode* node){
	//如果有后继，返回后继
	if(node->rtag == 1) return node->rchild;
	else{//没有后继
		if(node->ltag == 0) return node->lchild;//返回左孩子
		    else return node->rchild;//返回右孩子
	}
}
int main(){
	int index = 0;
	TreeNode *T,*pre = NULL,*node;
	createTree(&T,"ABD#G##E##C#FH###",&index);
	preThreadTree(T,&pre);
	pre->rtag = 1;
	pre->rchild = NULL;
	for(node = T;node != NULL;node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}

