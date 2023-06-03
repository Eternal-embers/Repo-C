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

void makeEmpty(stackNode *S){
	stackNode* node = S;
	while(S){
		node = S->next;
		free(S);
		S = node;
	}
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

//二叉树的非递归前序遍历，根左右
//从根节点开始，不断向左走，依次将不为空的结点压栈，在压栈时输出结点的数据，直到左孩子为空
//左孩子为空时，出栈，每出栈一个结点，访问它的右孩子，
//对右孩子重复前面所述的操作，直到栈为空且此时访问的结点为空
void preOrder(TreeNode *T){
	TreeNode* node = T;
	stackNode* S = initStack();
	while(node || !isEmpty(S)){//当结点不为空或者栈不为空时，执行前序遍历
		if(node){
			push(node,S);
			printf("%c ",node->data);
			node = node->lchild;//一直向左走
		}
        else{
			node = pop(S)->data;//出栈
			node = node->rchild;//访问每一个出栈元素的右孩子
		}
	}
}

//二叉树的非递归中序遍历，左根右
//从根结点开始，不断向左走，依次将不为空的结点压栈，直到左孩子为空，此时找到最左边的那个结点
//当左孩子为空时，出栈，每出栈一个结点，输出该出栈结点的数据，再访问该出栈结点的右孩子
//对右孩子重复前面的操作，直到栈为空且此时所访问的结点为空
void inOrder(TreeNode *T){
	TreeNode* node = T;
	stackNode* S = initStack();
	while(node || !isEmpty(S)){
		if(node){
			push(node,S);
			node = node->lchild;
		}
		else {
			node = pop(S)->data;
			printf("%c ",node->data);
			node = node->rchild;//访问出栈结点的右孩子
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
