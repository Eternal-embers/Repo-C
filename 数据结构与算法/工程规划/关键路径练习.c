#include<stdio.h>
#include<stdlib.h>
#define INF 0x7fffffff
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
			if(G->arcs[i][j] && G->arcs[i][j] != INF){
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
		printf("v%d：%d\n",i,inDegrees[i]);
	}
	putchar('\n');
}

int* topologicalSort(Graph *G){
	Node *stack = initStack();
	int *inDegrees = findInDegrees(G);
	int *top = (int *)malloc(sizeof(int) * G->vexNum);
	int size = 0;
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
		top[size++] = index;
		for(i = 0;i < G->vexNum;i++){
			if(G->arcs[index][i] > 0 && G->arcs[index][i] != INF) {
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
	return top;
}

int getTop(int *top,int vexNum,int j){
	int i;
	for(i = 0;i < vexNum;i++){
		if(top[i] == j) return i;
	}
	return -1;
}//获取节点的索引j在拓扑序列中的索引

void criticalPath(Graph *G){
	int *top = (int *)malloc(sizeof(int) * G->vexNum);//top数组中的元素记录的是节点在图的索引
	int *early = (int *)malloc(sizeof(int) * G->vexNum);
	int *late = (int *)malloc(sizeof(int) * G->vexNum);
	top = topologicalSort(G);
	int i,j;
 	printf("拓扑排序：");
	for(i = 0;i < G->vexNum;i++){
		printf("v%c ",G->vexs[top[i]]);
	}
 	putchar('\n');
	for(i = 0;i < G->vexNum;i++){
		early[i] = 0;
		late[i] = 0;
	}
	//计算最早开始时间
	for(i = 0;i < G->vexNum;i++)//指代拓扑排序后的序列中的索引
	{
		int max = 0;
		for(j = 0;j < G->vexNum;j++)//遍历所有节点，指代节点前驱
		{
            if(G->arcs[j][top[i]] > 0 && G->arcs[j][top[i]] != INF){//判断是否有边
				int pre = getTop(top,G->vexNum,j);
				if(early[pre] + G->arcs[j][top[i]] > max)
					max = early[pre] + G->arcs[j][top[i]];
			}
		}
		early[i] = max;
	}
	//计算最晚开始时间，从后往前计算
	late[G->vexNum - 1] = early[G->vexNum - 1];//终点的最晚开始时间等于最早开始时间
	for(i =  G->vexNum - 2;i >= 0;i--)//指代拓扑排序后的序列中的索引
	{
		int min = INF;
		for(j = 0;j < G->vexNum;j++)//遍历所有节点，指代后驱节点
		{
			if(G->arcs[top[i]][j] > 0 && G->arcs[top[i]][j] != INF){//判断是否有边
				int next = getTop(top,G->vexNum,j);
				if(late[next] - G->arcs[top[i]][j] < min){
					min = late[next] - G->arcs[top[i]][j];
				}
			}
			late[i] = min;
		}
	}
	
	printf("最早开始时间：");
	for(i = 0;i < G->vexNum;i++){
		printf("%d ",early[i]);
	}
	putchar('\n');
	printf("最晚开始时间：");
	for(i = 0;i < G->vexNum;i++){
		printf("%d ",late[i]);
	}
	putchar('\n');
	
	printf("关键路径：\n");
	//确定关键路径
	for(i = 0;i < G->vexNum;i++){
		for(j = 0;j < G->vexNum;j++){
			if(G->arcs[i][j] > 0 && G->arcs[i][j] != INF){
				int start = getTop(top,G->vexNum,i);
				int end = getTop(top,G->vexNum,j);
				if((late[end] - G->arcs[i][j]) - early[start] == 0)
					printf("v%c -> v%c\n",G->vexs[i],G->vexs[j]);
			}
		}
	}
}

int main() {
	Graph* G = initGraph(9);
	int arcs[9][9] = {
		  0,  6,  4,  5,INF,INF,INF,INF,INF,
		INF,  0,INF,INF,  1,INF,INF,INF,INF,
		INF,INF,  0,INF,  1,INF,INF,INF,INF,
		INF,INF,INF,  0,INF,  2,INF,INF,INF,
		INF,INF,INF,INF,  0,INF,  9,  7,INF,
		INF,INF,INF,INF,INF,  0,INF,  4,INF,
		INF,INF,INF,INF,INF,INF,  0,INF,  2,
		INF,INF,INF,INF,INF,INF,INF,  0,  4,
		INF,INF,INF,INF,INF,INF,INF,INF,  0
	};
	createGraph(G, (char *)"012345678", (int*)arcs);
	int visited[9] = { 0 };
	printf("DFS：");
	DFS(G, visited, 0);
	putchar('\n');
	topologicalSort(G);
	criticalPath(G);
	return 0;
}

