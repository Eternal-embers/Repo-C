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

void preOrder(TreeNode *T){
	if(T == NULL)return;
	else {
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inThreadTree(TreeNode *T,TreeNode **pre){
	//如果当前根节点不为空 
	if(T){
		inThreadTree(T->lchild,pre);//遍历左子树，线索化所有左子树
		//如果当前结点的左孩子为空，左孩子指向前驱
		if(T->lchild == NULL){
			T->ltag =1;//标记该结点的左孩子为后继
			T->lchild = *pre;//左孩子指向前驱
		}
		//如果当前结点前驱不为空且前驱的右孩子为空
		if(*pre != NULL && (*pre)->rchild == NULL){
			(*pre)->rtag =1;//标记该结点的右孩子为后继
			(*pre)->rchild = T;//右孩子指向后继
		}
		//将当前的根节点赋给前驱指针 
		*pre = T;
		inThreadTree(T->rchild,pre);//遍历右子树，线索化所有右子树
	}
	//如果树指针为空，返回 
	else return; 
}
 
 //获取左子树的叶节点 
TreeNode *getFirst(TreeNode *T){
	while(T->ltag == 0)
		T = T->lchild;//找到最左边的那个叶节点
	return T;
}

//返回右子树的叶节点 
TreeNode *getNext(TreeNode *node){
	//如果该结点为叶节点，返回其右孩子所指的地址 
	if(node -> rtag == 1)
		return node -> rchild;
	//如果该结点不为叶节点，返回其右孩子的最左边的叶节点
	else return getFirst(node -> rchild); 
}

int main()
{
	TreeNode *T,*pre = NULL,*node;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);
	preOrder(T);
	printf("\n");
	inThreadTree(T,&pre);//将二叉树线索化 
	pre -> rtag =1;
	pre -> rchild = NULL;
	for(node = getFirst(T); node != NULL; node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}
