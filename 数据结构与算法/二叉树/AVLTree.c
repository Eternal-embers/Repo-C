#include<stdio.h>
#include<stdlib.h>

/*
*   平衡二叉树的定义：左右子树的高度差不大于1的二叉树查找树
*   二叉查找树：在二叉树中，对任意节点X，X的左孩子的值小于X的值，X的右孩子的值大于X的值
*/
struct TreeNode{
	int data;
	int height;//节点的高度为以该节点为根节点的树的高度，规定空节点的高度为-1
	struct TreeNode* lchild;
	struct TreeNode* rchild;
};
typedef struct TreeNode AVLTree;

void preOrder(AVLTree *T,AVLTree *father,_Bool flag){
	if(T){
		if(father != NULL)
		printf("%d(%d_%s) height:%d\n",T->data,father->data,flag ? "左" : "右",T->height);
		else printf("%d(NULL) height:%d\n",T->data,T->height);
		preOrder(T->lchild,T,1);
		preOrder(T->rchild,T,0);
	}
}

int max(int a,int b){
	return a > b ? a : b;
}

int getHeight(AVLTree *T){
	return T ? T->height : 0;//如果T不为空返回该节点的高度，否则返回0
}

/* 右旋，将根节点旋转到其左孩子的右孩子的位置 */
void llRotation(AVLTree **T){
	struct TreeNode *root = *T;//所要调整的AVL树的根节点
	struct TreeNode *lchild = root->lchild;//根节点的左孩子
	struct TreeNode *grandson = lchild->rchild;//根节点的左孩子的右孩子
	root->lchild = grandson;
	lchild->rchild = root;
	/* 从下往上更新高度，右旋后root为lchild的右孩子*/
	root->height = getHeight(root->lchild) + 1;
	lchild->height = getHeight(lchild->rchild) + 1;
	*T = lchild;//更新根节点
}

/* 左旋,将根节点旋转到其右孩子的左孩子位置 */
void rrRotation(AVLTree **T){
	struct TreeNode *root = *T;//所要调整的AVL树的根节点
	struct TreeNode *rchild = root->rchild;//根节点的右孩子
	struct TreeNode *grandson = rchild->lchild;//根节点的右孩子的左孩子
	root->rchild = grandson;
	rchild->lchild = root;
	/* 从下往上更新高度，左旋后root为rchild的左孩子 */
	root->height = getHeight(root->rchild) + 1;
	rchild->height = getHeight(rchild->lchild) + 1;
	*T = rchild;//更新根节点
}

void AVLInsert(AVLTree **T,int data){
	if(*T == NULL)//递归结束，在此节点插入新节点
	{
		*T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		(*T)->data = data;
		(*T)->height = 0;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}//创建节点
	else {
		if(data < (*T)->data) {
			AVLInsert(&(*T)->lchild,data);//向左子树递归
			/* 回溯之前T经过的节点，对以该节点为根的树进行调整 */
			int lHeight = getHeight((*T)->lchild);
			int rHeight = getHeight((*T)->rchild);
			if(lHeight - rHeight == 2){
				/* LL */
				if((*T)->lchild && data < (*T)->lchild->data)
					llRotation(T);
				/* LR */
				else {
					rrRotation(&(*T)->lchild);
					llRotation(T);
				}
			}
		}
		else if(data > (*T)->data) {
			AVLInsert(&(*T)->rchild,data);//向右子树递归
			/* 回溯之前T经过的节点，对以该节点为根的树进行调整 */
			int lHeight = getHeight((*T)->lchild);
			int rHeight = getHeight((*T)->rchild);
			if(rHeight - lHeight == 2){
				/* RR */
				if((*T)->rchild && data > (*T)->rchild->data)
					rrRotation(T);
				/* RL */
				else {
					llRotation(&(*T)->rchild);
					rrRotation(T);
				}
			}
		}
  		/*
		* else{}
		* 如果data == (*T)->data,说明data在AVL树中已经存在
		* 则不进行插入，因为AVL树不插入重复的数据
		*/
	}
 	/* 更新节点的高度 */
	(*T)->height = max(getHeight((*T)->lchild),getHeight((*T)->rchild)) + 1;
}

int main(){
	int arr[10] = {7,2,10,14,5,6,3,1,20,8};
	AVLTree *T = NULL;
	int i;
	for(i = 0;i < 10;i++)
		AVLInsert(&T,arr[i]);
	preOrder(T,NULL,0);
	return 0;
}
