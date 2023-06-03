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

void createTree(TreeNode **T,char *data,int *index,TreeNode *parent){
	char ch = data[*index];
	*index += 1;
	if(ch == '#') *T = NULL;
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		(*T)->parent = parent;
		createTree(&(*T)->lchild,data,index,*T);
		createTree(&(*T)->rchild,data,index,*T);
	}
}

void postThreadTree(TreeNode *T,TreeNode **pre){
	//如果当前根节点不为空
	if(T){
		postThreadTree(T->lchild,pre);//遍历左子树，线索化所有左子树
		postThreadTree(T->rchild,pre);//遍历右子树，线索化所有右子树
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
	}
	//如果树指针为空，返回
	else return;
}

 //获取左子树的叶节点
TreeNode *getFirst(TreeNode *T){
	while(T->ltag == 0)
		T = T->lchild;//找到最左边的那个叶节点
	if(T->rtag == 0) return getFirst(T->lchild);
	return T;
}

//返回右子树的叶节点
TreeNode *getNext(TreeNode *node){
    if(node->rtag == 1) return node->rchild;//如果有后继
    else {
    	if(node->parent == NULL) return NULL;//如果是根节点
    	else if(node->parent->rchild == node){//如果是右孩子
    		return node->parent;
		}
		else {//如果是左孩子
			if(node->parent->rtag == 0) return getFirst(node->parent->rchild);
				else return node->parent;
		}
	}
}

int main()
{
	TreeNode *T,*pre = NULL,*node;
	int index = 0;
	createTree(&T,"ABD#H###CF#I##G##",&index,NULL);
	postThreadTree(T,&pre);//将二叉树线索化
	for(node = getFirst(T); node != NULL; node = getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}
