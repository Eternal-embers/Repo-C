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

void preOrder(TreeNode* T){
	if(T){
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

//二叉树的中序线索遍历，遍历顺序：左根右
//首先递归遍历左子树，再对当前结点进行线索化，再递归当前结点的右子树
void inThreadTree(TreeNode *T,TreeNode **pre){
	if(T){
		inThreadTree(T->lchild,pre);
		if(T->lchild == NULL){
			T->lchild = *pre;
			T->ltag = 1;
		}
		if(*pre && (*pre)->rchild == NULL){
		   (*pre)->rchild = T;
		   (*pre)->rtag = 1;
		}
		*pre = T;
		inThreadTree(T->rchild,pre);
	}
}

TreeNode *getFirst(TreeNode *T){
	while(T->ltag == 0){//如果结点的左标记未被标记，说明左孩子为结点
		T = T->lchild;
	}
	return T;
}

TreeNode *getNext(TreeNode *node){
	if(node->rtag == 1) return node->rchild;
        else return getFirst(node->rchild);
}

int main(){
	TreeNode *T,*pre = NULL,*node;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);
	preOrder(T);
	putchar('\n');
	inThreadTree(T,&pre);
	pre->rchild = NULL;
	pre->rtag = 1;
	for(node = getFirst(T);node;node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}

