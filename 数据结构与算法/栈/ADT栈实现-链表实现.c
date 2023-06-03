#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define stack struct Node
#define dataType int

typedef struct Node{
	dataType data;
	struct Node *next;
}node;

stack *createStack(){
	node *head = (node*)malloc(sizeof(struct Node));
	head->data = 0;
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

void clear(stack *s){
	while(!isEmpty(s)){
	   node *p = s->next;
	   s->next = s->next->next;
	   free(p);
	}
	s->data = 0;
}

dataType getNode(int index,stack *s){
	if(isEmpty(s)) return -1;
	int i = 0;
	node *p = s->next;
	while(i < index && p){
		p = s->next;
		i++;
	}
	return p->data;
}

dataType traverseStack(stack *s){
	if(isEmpty(s)) return;
	node *p = s->next;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	putchar('\n');
}

int main(){
	stack *createStack();
	_Bool isEmpty(stack *s);
	void push(dataType data,stack *s);
	dataType pop(stack *s);
	dataType top(stack *s);
	void clear(stack *s);
	stack *s = createStack();
	int i;
	srand(time(NULL));
	for(i = 0;i < 10;i++)
		push(rand()%100,s);
	traverseStack(s);
	printf("isEmpty(s):%s\n",isEmpty(s) ? "true" : "false");
	pop(s);
	pop(s);
	traverseStack(s);
	clear(s);
	printf("isEmpty(s):%s\n",isEmpty(s) ? "true" : "false");
	return 0;
}




