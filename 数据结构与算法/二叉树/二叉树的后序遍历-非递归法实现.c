#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;//左孩子
	struct TreeNode *rchild;//右孩子
	_Bool flag;
}TreeNode;

typedef struct stackNode{
	TreeNode *data;//存放树的某个结点
	struct stackNode *next;//指向栈的下一节点
}stackNode;

stackNode *initStack(void){
	stackNode *S = (stackNode *)malloc(sizeof(stackNode));//为栈的头部开辟空间,此空间不存放数据
	S->data = NULL;
	S->next = NULL;
	return S;
}

void makeEmpty(stackNode *S){
	stackNode* node;
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

stackNode *getTop(stackNode *S){
	if(isEmpty(S))return NULL;//如果为空，返回空指针
	else {
		stackNode *node = S->next;//栈指针指向头节点的下一节点
		return node;//返回出栈的那个节点
	}
}

void createTree(TreeNode **T,char *data,int *index){
	char ch = data[*index];
	*index+=1;//指向字符串的指针索引加一
	if(ch == '#')*T = NULL;//如果字符为#，结点指向NULL
	else {
		*T = (TreeNode *)malloc(sizeof(TreeNode));//为树的某个结点开辟空间
		(*T)->data = ch;//将数据放入结点数据域
		(*T)->flag = 0;
		createTree(&(*T)->lchild,data,index);//递归创建左子树
		createTree(&(*T)->rchild,data,index);//递归创建右子树
	}
}

void postOrder(TreeNode *T){
	TreeNode *node = T;
	stackNode *S = initStack();
	while(node || !isEmpty(S)) {
		if(node) {
			push(node,S);
			node = node->lchild;
		}
		else {
			TreeNode *top = getTop(S)->data;
			if(top->rchild && top->rchild->flag == 0){
				top = top->rchild;
				push(top,S);
				node = top->lchild;
			}
			else {
				top = pop(S)->data;
				printf("%c ",top->data);
				top->flag = 1;
			}
		}
	}
}
int main(){
	TreeNode *T;
	int index = 0;
	createTree(&T,"ABCDEFG",&index);
	postOrder(T);
	printf("\n");
	return 0;
}
