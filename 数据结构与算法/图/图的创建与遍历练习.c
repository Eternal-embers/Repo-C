/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<stdlib.h>
 #define MAXSIZE 5
typedef struct Graph{
	char *vexs;//节点
	int **arcs;//边
	int vexNum;//节点数
	int arcNum;//边数
}Graph;
/* - - - - - - - - - -队列实现 - - - - - - - - - - - - */
typedef struct Queue{
	int front;
	int rear;
	int data[MAXSIZE];
}Queue;

Queue *initQueue(){
	Queue *Q = (Queue *)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

_Bool isFull(Queue *Q){
 	return (Q->rear + 1) % MAXSIZE == Q->front;
}

_Bool isEmpty(Queue *Q){
	return Q->front == Q->rear;
}

_Bool enQueue(Queue *Q,int data){
	if(isFull(Q)) return 0;
	Q->data[Q->rear++] = data;
	Q->rear %= MAXSIZE;
	return 1;
}

int deQueue(Queue *Q){
	if(isEmpty(Q)) return -1;
	int data = Q->data[Q->front++];
	Q->front %= MAXSIZE;
	return data;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

Graph *initGraph(int vexNum){
	Graph *G = (Graph *)malloc(sizeof(Graph));
	G->vexs = (char *)malloc(sizeof(char) * vexNum);
	G->arcs = (int **)malloc(sizeof(int *) * vexNum);
	int i;
	for(i = 0;i < vexNum;i++){
		G->arcs[i] = (int *)malloc(sizeof(int) * vexNum);
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}//开辟空间

Graph *createGraph(Graph *G,char *vexs,int *arcs){
	int i,j;
	for(i = 0;i < G->vexNum;i++){
		G->vexs[i] = vexs[i];
	}
	for(i = 0;i < G->vexNum;i++){
		for(j = 0;j < G->vexNum;j++){
			G->arcs[i][j] = *(arcs + G->vexNum * i + j);
			if(G->arcs[i][j] != 0) G->arcNum++;
		}
	}
	G->arcNum /= 2;
}

int DFS(Graph *G,int *visited,int index){
	printf("%c ",G->vexs[index]);
	visited[index] = 1;
	int i;
	for(i = 0;i < G->vexNum;i++){
		if(G->arcs[index][i] == 1 && !visited[i]){
			DFS(G,visited,i);
		}
	}
}

int BFS(Graph *G,int *visited,int index){
	Queue *Q = initQueue();
	printf("%c ",G->vexs[index]);
	enQueue(Q,index);
	visited[index] = 1;
	int vex,i;
	while(!isEmpty(Q)){
		vex = deQueue(Q);
		for(i = 0;i < G->vexNum;i++){
			if(G->arcs[vex][i] == 1 && !visited[i]){
				printf("%c ",G->vexs[i]);
				enQueue(Q,i);
				visited[i] = 1;
			}
		}
	}
}

int main(){
	Graph *G = initGraph(5);
	int arcs[5][5] = {
	0,1,1,1,0,
	1,0,1,1,1,
	1,1,0,0,0,
	1,1,0,0,1,
	0,1,0,1,0
	};
	int visited[5] = {0};
 	createGraph(G,"ABCDE",(int *)arcs);
 	DFS(G,visited,0);
 	putchar('\n');
	int i;
	for(i = 0;i < G->vexNum;i++){
		visited[i] = 0;
	}
 	BFS(G,visited,0);
	return 0;
}

