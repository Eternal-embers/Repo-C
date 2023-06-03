#include<stdio.h>
#include<stdlib.h>
#define stack struct Node
#define dataType union data
typedef struct Node{
	union data{
		int i;
		double d;
		char c;
	};
	struct Stack *next;
}node;
stack *createStack(){
	node *head = (node*)malloc(sizeof(struct Node));
	(head->data).i = 0;
	head->next = NULL;
	return head;
}

_Bool isEmpty(stack *s){
	if(s->next == NULL) return 1;
	else return 0;
}

void push(dataType data,stack *s){
	node *p = (node *)malloc(sizeof(struct Node));
	p->data = data;
	p->next = s->next;
	s->next = p;
	s->data++;
}

dataType pop(stack *s){
	if(isEmpty(s)) return -1;
	dataType data = s->next->data;
	node *p = s->next;
	s->next = s->next->next;
	free(p);
	s->data--;
}

dataType top(stack *s){
	return s->next->data;
}

int main(){

}
