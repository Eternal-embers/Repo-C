#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff

struct matrix{
	int col;//列
	int row;//行
	int element;//元素
	struct matrix* next;
};

struct matrix *createMatrix(){
	struct matrix *m = (struct matrix*)malloc(sizeof(struct matrix));
	m->col = -1;
	m->row = -1;
	m->element = INF;
	m->next = NULL;
	return m;
}

void *insert(struct matrix* m,int col,int row,int element){
	struct matrix* node = (struct matrix *)malloc(sizeof(struct matrix));
	node->col = col;
	node->row = row;
	node->element = element;
	node->next = m->next;
	m->next = node;
}

int find(struct matrix *m,int col,int row){
	struct matrix *t = m->next;
	int i;
	while(t){
		if(t->col == col && t->row == row) return t->element;
		t = t->next;
	}
	return INF;
}

void showMatrix(struct matrix *m,int cols,int rows){
	int i,j;
	for(i = 0;i < rows;i++){
		for(j = 0;j < cols;j++){
			int element = find(m,j,i);
			if(element != INF) printf("%4d",element);
			else printf("%4d",0);
		}
		putchar('\n');
	}
}

void input(struct matrix* m){
	printf("行 列 元素\n");
	while(1){
		int col,row,element;
		scanf("%d%d%d",&row,&col,&element);
		if(col == -1 || row == -1) return;
		insert(m,col - 1,row - 1,element);
	}
}

int main(){
	struct matrix* m = createMatrix();
	input(m);
 	showMatrix(m,10,10);
	return 0;
}

