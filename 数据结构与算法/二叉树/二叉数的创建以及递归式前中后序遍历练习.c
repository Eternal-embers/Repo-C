#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[(*index)++];
	if(ch == '#'){
		*T = NULL;
	}
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
}//¸ù×óÓÒ

void inOrder(TreeNode *T){
	if(T == NULL) return;
	else {
		inOrder(T->lchild);
		printf("%c ",T->data);
		inOrder(T->rchild);
	}
}//×ó¸ùÓÒ

void postOrder(TreeNode *T){
	if(T == NULL) return;
	else {
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ",T->data);
	}
}//×óÓÒ¸ù

int main(){
	TreeNode *T;
	int index = 0;
	createTree(&T,"AB##C##",&index);
	preOrder(T);
	putchar('\n');
	inOrder(T);
	putchar('\n');
	postOrder(T);
	return 0;
}
