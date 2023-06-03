#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define dataType int
#define null -1
#define LEN 20
struct Stack{
	dataType *stack;
	int capacity;//Õ»ÈÝÁ¿
	int size;//Õ»¶¥ÏÂ±ê
};

struct Stack * createStack(int capacity){
	struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
	s->capacity = capacity;
	s->size = 0;
	s->stack = (dataType *)calloc(s->capacity,sizeof(dataType));
	return s;
}

_Bool isEmpty(struct Stack *s){
	return s->size == 0;
}

_Bool isFull(struct Stack *s){
	return s->size == s->capacity;
}

void push(dataType data,struct Stack *s){
	if(isFull(s)) {
		int i;
		dataType *p = (dataType *)calloc(s->capacity*2,sizeof(dataType));
		s->capacity *= 2;
		for(i = 0;i < s->size;i++)
			p[i] = s->stack[i];
		free(s->stack);
		s->stack = p;
		s->stack[s->size++] = data;
	}
	else {
		s->stack[s->size++] = data;
	}
}

dataType pop(struct Stack *s){
	if(isEmpty(s)) return null;
	dataType data = s->stack[s->size-1];
	s->stack[s->size--] = 0;
	return data;
}

dataType top(struct Stack *s){
	if(isEmpty(s)) return null;
	else return s->stack[s->size-1];
}

void clear(struct Stack *s){
	dataType *p = (dataType *)calloc(s->capacity,sizeof(dataType));
	free(s->stack);
	s->size = 0;
	s->stack = p;
}

void traverseStack(struct Stack *s){
	int i;
	for(i = s->size -1;i >= 0;i--)
		printf("%d ",s->stack[i]);
	putchar('\n');
}

void stackSort(struct Stack *s){
	if(isEmpty(s)) return;
	int i,j,temp;
	for(i = 1;i < s->size;i++){
		temp = s->stack[i];
		for(j = i-1;j >= 0;j--){
			if(temp > s->stack[j]) s->stack[j+1] = s->stack[j];
				else break;
		}
		s->stack[j+1] = temp;
	}
}

int main(){
	struct Stack * createStack(int capacity);
	_Bool isEmpty(struct Stack *s);
	_Bool isFull(struct Stack *s);
	void push(dataType data,struct Stack *s);
	dataType pop(struct Stack *s);
	dataType top(struct Stack *s);
	void clear(struct Stack *s);
	void traverseStack(struct Stack *s);
	void stackSort(struct Stack *s);
	
	struct Stack *s = createStack(LEN);
	int i;
	srand(time(NULL));
	for(i = 0;i < 20;i++)
		push(rand() % 100 + 1,s);
	printf("isEmpty(s):%s\n",isEmpty(s) ? "true" : "false");
	printf("isFull(s):%s\n",isFull(s) ? "true" : "false");
	printf("traverseStack:");
	traverseStack(s);
	printf("top:%d\n",top(s));
	stackSort(s);
	printf("traverseStack:");
	traverseStack(s);
	printf("pop(s):%d\n",pop(s));
	printf("pop(s):%d\n",pop(s));
	clear(s);
	printf("clear->isEmpty(s):%s\n",isEmpty(s) ? "true" : "false");
	return 0;
}
