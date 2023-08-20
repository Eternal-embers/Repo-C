/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:07/30 10:05
	Description: 统计数字-单链表
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
  int num;
  int cnt;
  struct Node *next;
};

void insert(struct Node *list,int num){
	struct Node *p = list;
	/* 找到最后一个小于num的节点 */
	while(p->next && p->next->num < num){
		p = p->next;
	}
	if(p->next && p->next->num == num)
		p->next->cnt++;
	else{
		struct Node *node = (struct Node *)malloc(sizeof(struct Node));
		node->num = num;
		node->cnt = 1;
		/* 插入 */
		node->next = p->next;
		p->next = node;
	}
}

void traverse(struct Node *list){
	while(list){
		printf("%d %d\n",list->num,list->cnt);
		list = list->next;
	}
}

int main(){
	int n,i,t;
	scanf("%d",&n);
	/* 创建自带头节点的链表 */
	struct Node *list = (struct Node *)malloc(sizeof(struct Node));
	list->num = -1;
	list->cnt = -1;
	list->next = NULL;
	for(i = 0;i < n;i++){
		scanf("%d",&t);
		insert(list,t);
	}
 	traverse(list->next);
	return 0;
}


