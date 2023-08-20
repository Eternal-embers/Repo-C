/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/30 10:52
	Description: ͳ������-����������
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
	/* ���뵽���� */
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
	    insert(T->left,num);//�ݹ�������
    else
		insert(T->right,num);//�ݹ�������
}

void traverse(struct Node *T){//�������
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
	/* �������ڵ� */
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

