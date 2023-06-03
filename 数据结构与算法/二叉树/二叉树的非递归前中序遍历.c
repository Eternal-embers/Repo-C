#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;//左孩子 
	struct TreeNode *rchild;//右孩子 
}TreeNode;
 
typedef struct stackNode{
	TreeNode *data;//存放树的某个结点 
	struct stackNode *next;//指向栈的下一节点 
}stackNode;

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[*index];
	*index+=1;//指向字符串的指针索引加一 
	if(ch == '#')*T = NULL;//如果字符为#，结点指向NULL 
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));//为树的某个结点开辟空间 
		(*T)->data = ch;//将数据放入结点数据域 
		createTree(&(*T)->lchild,data,index);//递归创建左子树 
		createTree(&(*T)->rchild,data,index);//递归创建右子树 
	}
}

stackNode *initStack(void){
	stackNode *S = (stackNode *)malloc(sizeof(stackNode));//为栈的头部开辟空间,此空间不存放数据 
	S->data = NULL;
	S->next = NULL;
	return S;
}

//将数据压栈 
void push(TreeNode *T,stackNode *S){
	stackNode *node = (stackNode *)malloc(sizeof(stackNode));//为栈节点开辟空间 
	//头插法 
	node->data = T;//先将数据放入栈节点的数据域中 
	node->next =  S->next;//该栈节点指向栈头节点指向的下一节点 
	S->next = node;//栈的头节点的next指针指向插入的节点 
}

//判断栈是否为空 
int isEmpty(stackNode *S){
	if(S->next == NULL)return 1;//如果栈的头节点无下一节点，栈为空 
	else return 0;
}

//出栈 
stackNode *pop(stackNode *S){
	if(isEmpty(S))return NULL;//如果为空，返回空指针 
	else {
		stackNode *node = S->next;//栈指针指向头节点的下一节点 
		S->next = node->next;//头节点的next指针指向下一节点的下一节点 
		return node;//返回出栈的那个节点 
	}
}

//二叉树的非递归先序遍历，先压栈，再循环至左节点为空;
//接着每出一次栈，判断右节点是否为空，如果不为空，压栈右节点 
void preOrder(TreeNode *T){
	TreeNode *node = T;
	stackNode *S = initStack();//获取栈的头节点
	//当树节点不为空，或者栈不为空时，继续遍历 
	while(node || !isEmpty(S)) {
		//树节点不为空 
		if(node){
			printf("%c ",node->data);//打印树节点的数据域中存放的数据 
			push(node,S);//将此时的树节点压栈 
			node = node->lchild;//指向树的指针指向此时树的下一左子树的根节点 
		}
		//树节点为空 
		else{
			node = pop(S)->data;//树的指针指向出栈的那个栈节点的数据域指向的树节点 
			node = node ->rchild;//树的指针指向该树节点的右子树 
		}
	}
}

//二叉树的非递归中序遍历，先将左子树压栈，当指向的左子树为空，出栈 
//每出一次栈打印该出栈节点的数据，再向根节点移动的过程中访问经过的每一个节点的右子树 
void inOrder(TreeNode *T){
	TreeNode *node = T;//接收树的根节点 
	stackNode *S = initStack();//获取栈的头节点
	//当只指向的树节点不为空或栈为不为空时，继续遍历 
	while(node || !isEmpty(S)){
		//如果此时指向的树节点不为空 
		if(node){
			push(node,S);//将此时的树节点压入栈中 
			node = node->lchild;//指向此时树的子树的根节点 
		}
		//如果此时指向的树节点为空，出栈 
		else{
			node = pop(S)->data;//出栈，树的指针指向出栈那个节点数据域指向的树节点 
			printf("%c ",node->data);//将出栈的那个节点的的数据打印 
			node = node->rchild;//指向此时树节点的右子树 
		}
	}
}

int main(){
	TreeNode *T;
	int index = 0;
	createTree(&T,"ABD##E##CF##G##",&index);//创建二叉树 
	preOrder(T);//二叉树的先序遍历
	printf("\n");
	inOrder(T);//二叉树的中序遍历 
	return 0;
}
