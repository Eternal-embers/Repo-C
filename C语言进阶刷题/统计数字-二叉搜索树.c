/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 07/30 10:52
	Description: 统计数字-二叉搜索树
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int num;
	int cnt;
	struct Node *left;
	struct Node *right;
};

void insert(struct Node *T,int num){
	if(T->num == num) T->cnt++;
	/* 插入到左孩子 */
	else if(T->left == NULL && T->num > num){
		T->left = (struct Node *)malloc(sizeof(struct Node));
		T->left->num = num;
		T->left->cnt = 1;
		T->left->left = NULL;
		T->left->right = NULL;
	}
	else if(T->right == NULL && T->num < num){
		T->right = (struct Node *)malloc(sizeof(struct Node));
		T->right->num = num;
		T->right->cnt = 1;
		T->right->left = NULL;
		T->right->right = NULL;
	}
	else if(T->left && T->num > num)
	    insert(T->left,num);//递归左子树
    else
		insert(T->right,num);//递归右子树
}

void traverse(struct Node *T){//中序遍历
	if(T){
		if(T->left) traverse(T->left);
		printf("%d %d\n",T->num,T->cnt);
		if(T->right) traverse(T->right);
	}
}

int main(){
	int n,i,t;
	scanf("%d",&n);
	scanf("%d",&t);
	/* 创建根节点 */
	struct Node *T = (struct Node *)malloc(sizeof(struct Node));
	T->num = t;
	T->cnt = 1;
	T->left = NULL;
	T->right = NULL;
	for(i = 1;i < n;i++){
		scanf("%d",&t);
		insert(T,t);
	}
 	traverse(T);
	return 0;
}

