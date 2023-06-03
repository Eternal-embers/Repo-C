/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:21/03/23 20:0521/03/23 20:05
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


void preThreadTree(TreeNode *T,TreeNode **pre){
	//如果当前根节点不为空
	if(T){
		//如果当前结点的左孩子为空，左孩子指向前驱
		if(T->lchild == NULL){
			T->ltag = 1;//标记该结点的左孩子为后继
			T->lchild = *pre;//左孩子指向前驱
		}
		//如果当前结点前驱不为空且前驱的右孩子为空
		if(*pre != NULL && (*pre)->rchild == NULL){
			(*pre)->rtag =1;//标记该结点的右孩子为后继
			(*pre)->rchild = T;//右孩子指向后继
		}
		//将当前的根节点赋给前驱指针
		*pre = T;
		if(T->ltag == 0) preThreadTree(T->lchild,pre);//遍历左子树，线索化所有左子树
		if(T->rtag == 0) preThreadTree(T->rchild,pre);//遍历右子树，线索化所有右子树
	}
}

TreeNode *getNext(TreeNode *node){
	if(node->ltag == 1 || node->rtag == 1)
	    return node->rchild;
	else
		return node->lchild;
	/*
	由下面的代码简化
	if(node->rtag == 1) return node->rchild;
	else {
		if(node->ltag == 0) return node->lchild;
	    	else return node->rchild;
	}
	return node->lchild;
	*/
}

int main(){
	TreeNode *T,*pre = NULL,*node;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);
	preThreadTree(T,&pre);//将二叉树线索化
	pre -> rtag =1;
	pre -> rchild = NULL;
	for(node = T;node != NULL;node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}

