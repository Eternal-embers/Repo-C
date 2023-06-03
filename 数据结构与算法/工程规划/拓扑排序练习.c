#include<stdio.h>
#include<stdlib.h>

typedef struct Graph {
	char* vexs;
	int** arcs;
	int vexNum;
	int arcNum;
}Graph;

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* initStack() {
	Node* stack = (Node*)malloc(sizeof(Node));
	stack->data = 0;
	stack->next = NULL;
	return stack;
}

void push(Node* stack, int data) {
	Node* node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->next;
	stack->next = node;
	stack->data++;
}

int isEmpty(Node* stack) {
	return stack->next == NULL;
}

int pop(Node* stack) {
	if (!isEmpty(stack)) {
		int data;
		Node* node = stack->next;
		data = node->data;
		stack->next = node->next;
		free(node);
		return data;
	}
	else {
		return -1;
	}
}

Graph* initGraph(int vexNum) {
	Graph* G = (Graph *)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vexNum);
	G->arcs = (int**)malloc(sizeof(int *) * vexNum);
	int i;
	for (i = 0; i < vexNum; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}

void createGraph(Graph* G, char* vexs, int* arcs) {
	int i,j;
	for (i = 0; i < G->vexNum; i++) {
		G->vexs[i] = vexs[i];
	}
	for (i = 0; i < G->vexNum; i++) {
		for (j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = *(arcs + i * G->vexNum + j);
			if (G->arcs[i][j]) {
				G->arcNum++;
			}
		}
	}
	G->arcNum /= 2;
}

void DFS(Graph* G, int* visited, int index) {
	printf("v%c ", G->vexs[index]);
	visited[index] = 1;
	int i;
	for (i = 0; i < G->vexNum; i++) {
		if (G->arcs[index][i] && !visited[i]) {
			DFS(G, visited, i);
		}
	}
}

int *findInDegrees(Graph *G){
	int i,j;
	int *inDegrees = (int *)malloc(sizeof(int) * G->vexNum);
	for(i = 0;i < G->vexNum;i++){
		inDegrees[i] = 0;
	}
	for(i = 0;i < G->vexNum;i++){
		for(j = 0;j < G->vexNum;j++){
			if(G->arcs[i][j]){
				inDegrees[j]++;
			}
		}
	}
	return inDegrees;
}

void showInDegrees(int *inDegrees,int vexNum){
	int i;
	printf("    入度\n");
	for(i = 0;i < vexNum;i++){
		printf("v%d：%d\n",i + 1,inDegrees[i]);
	}
	putchar('\n');
}

void topologicalSort(Graph *G){
	Node *stack = initStack();
	int *inDegrees = findInDegrees(G);
	int i,index;
	/* 入栈 */
	for(i = 0;i < G->vexNum;i++){
		if(inDegrees[i] == 0) {
			push(stack,i);
			inDegrees[i]--;
		}
	}
	while(!isEmpty(stack)){
		/* 出栈 */
		index = pop(stack);
		printf("v%c ",G->vexs[index]);
		for(i = 0;i < G->vexNum;i++){
			if(G->arcs[index][i]) {
				inDegrees[i]--;
			}
		}
		/* 入栈 */
		for(i = 0;i < G->vexNum;i++){
			if(inDegrees[i] == 0) {
				push(stack,i);
				inDegrees[i]--;
			}
		}
		//showInDegrees(inDegrees,G->vexNum);
	}
}

int main() {
	Graph* G = initGraph(6);
	int arcs[6][6] = {
		0,1,1,1,0,0,
		0,0,0,0,0,0,
		0,1,0,0,1,0,
		0,0,0,0,1,0,
		0,0,0,0,0,0,
		0,0,0,1,1,0
	};
	createGraph(G, (char *)"123456", (int*)arcs);
	int visited[6] = { 0 };
	printf("DFS：");
	DFS(G, visited, 0);
	putchar('\n');
	printf("拓扑排序：");
    topologicalSort(G);
    putchar('\n');
	return 0;
}

