/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 07/30 17:09
	Description: 约瑟夫环-循环链表
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int id;
	struct Node *pre;
	struct Node *next;
};
int n,k,m;

struct Node *createList(){
	struct Node *list = (struct Node *)malloc(sizeof(struct Node));
	list->id = 1;
	list->pre = list;
	list->next = list;
	struct Node *p = list;//p指向链表的最后一个节点
	int i;
	for(i = 2;i <= n;i++){
		struct Node *node = (struct Node *)malloc(sizeof(struct Node));
		node->id = i;
		node->pre = p;
		node->next = p->next;
		p->next->pre = node;
		p->next = node;
		p = node;
	}
	while(list->id != k){
		list = list->next;
	}
	return list;
}

void *deleteNode(struct Node *node){
	node->pre->next = node->next;
	node->next->pre = node->pre;
	free(node);
}

int main(){
	scanf("%d %d %d",&n,&k,&m);
	k = (k > n) ? (k % n) : k;
    struct Node *node = createList();
    struct Node *next = node;
    int out = 0;
    int cnt = 1;
    while(out != n){
    	next = node->next;
    	if(cnt == m){//出局
			out++;//记录出局一个
    		printf("%d\n",node->id);
   		    deleteNode(node);
			cnt = 1;
			node = next;
		}
		else{
			cnt++;//下一个的报数
			node = node->next;
		}
	}
	return 0;
}

