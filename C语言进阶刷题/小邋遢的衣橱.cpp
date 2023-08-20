/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:08/01 14:42
	Description: 小邋遢的衣橱
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char *name;
	struct Node *next;
};
char s1[4];
char s2[20];

void push(struct Node *stack,char *name){
	/* 创建节点 */
	int len = strlen(name);
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->name = (char *)malloc(sizeof(char) * len);
	int i;
	for(i = 0;i < len;i++)
		node->name[i] = name[i];
	node->name[i] = '\0';
	node->next = NULL;
	/* 头插法 */
	node->next = stack->next;
	stack->next = node;
}

char *pop(struct Node *stack){
	if(stack->next) {
		struct Node *node = stack->next;
		stack->next = stack->next->next;
		return node->name;
	}
	else return NULL;
}

int main(){
	int N;
	scanf("%d",&N);
	struct Node *stack = (struct Node *)malloc(sizeof(struct Node));
	stack->name = NULL;
	stack->next = NULL;
	int i;
	char *p;
	for(i = 0;i < N;i++){
		scanf("%s %s",s1,s2);
		if(s1[0] == 'i')
			push(stack,s2);
		else {
			p = pop(stack);
			while(p && strcmp(p,s2) != 0){
				p = pop(stack);
			}
		}
	}
	p = pop(stack);
	if(p == NULL) printf("Empty");
	else printf("%s",p);
	return 0;
}

